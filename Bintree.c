/*
 * =====================================================================================
 *
 *       Filename:  Bintree.c
 *
 *    Description:  obj -- a new Bnode which holds the data X, stable
 *    		    vlt	-- represents "volatile", changable
 *
 *        Version:  1.0
 *        Created:  11.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/Bintree.h>

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
$dclmethod(OBJ, search, $arg(T));
$dclmethod(void, add, $arg(T));
$dclmethod(OBJ, del, $arg(T));

static void post_order(OBJ, HANDLER);

/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:
 * Description:  make sure all data is 0
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Bintree, $arg(va_list * arg))
	me->head = (OBJ) 0;
	me->cnt = 0;
	return (OBJ) me;
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  dtor
 *   Parameter:
 * Description:  regard gdelete as delegation to delete all Bnode in the tree
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, dtor, Bintree)
        post_order(me->head, gdelete);              /* not me, me represents Bintree */
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  search
 *   Parameter:	 X
 * Description:  make a node obj holds the X
 * 		 return the addr which holds the target data X
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, search, Bintree, $arg(T x))
	$private(Bnode) * vlt = (PTR) me->head;
	$private(Bnode) * obj = (PTR) gnew(Bnode, x);

	/*-----------------------------------------------------------------------------
	 *  use Bnode's comp, which derived from class Node
	 *-----------------------------------------------------------------------------*/
	while (vlt) {
		int res = $do(vlt, comp, $arg(obj));
		if (!res) {                             /* equal */
			return (OBJ) vlt;
		} else if (res > 0) {                   /* vlt->x > x */
			vlt = (PTR) vlt->link[left];
		} else {                                /* vlt->x < x */
			vlt = (PTR) vlt->link[right];
		}
	}
	return NULL;                                    /* not found */
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  add
 *   Parameter:  X
 * Description:  make a node obj holds the X then add a new one to the fit position
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, add, Bintree, $arg(T x))
	$private(Bnode) * vlt = (PTR) me->head;
	$private(Bnode) * obj = (PTR) gnew(Bnode, x);

	/* make sure every Bnode is clean, it's calloc'd */
	while (1) {
		if (!vlt) {                             /* is the tree empty? */
			me->head = (PTR) obj;
			break;
		}
		int res = $do(vlt, comp, $arg(obj));
		if (res > 0) {                          /* vlt->x > x */
			if (vlt->link[left]) {
				vlt = (PTR) vlt->link[left];
			} else {
				vlt->link[left] = (PTR) obj;
				break;                  /* add then jump out */
			}
		} else {                                /* vlt->x <= x */
			if (vlt->link[right]) {
				vlt = (PTR) vlt->link[right];
			} else {
				vlt->link[right] = (PTR) obj;
				break;                  /* add then jump out */
			}
		}
	}
	me->cnt++;                                      /* don't forget this */
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  del
 *   Parameter:  X
 * Description:  delete a certain Bnode from the bin-tree
 * 		 return the addr
 * 		 del only modify the structure of the tree but doesn't delete it
 * 		 so u could do like this:
 *
 * 		 gdelete($do(bin_tree, del, $arg(X)));
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, del, Bintree, $arg(T x))
	int dir = 0;                                    /* direction */
	$private(Bnode) * vlt = (PTR) me->head;
	$private(Bnode) * obj = (PTR) gnew(Bnode, x);   /* removing one */
	$private(Bnode) * prt = obj;                    /* parent */

	/*-----------------------------------------------------------------------------
	 *  1st, locate the removing one and it's parent
	 *-----------------------------------------------------------------------------*/
	while (vlt) {
		int res = $do(vlt, comp, $arg(obj));
		if (!res) {                             /* found, jump out */
			break;
		} else if (res > 0) {
			prt = vlt;
			vlt = (PTR) vlt->link[left];
			dir = left;                     /* record the direction */
		} else {                                /* obj->x < x */
			prt = vlt;
			vlt = (PTR) vlt->link[right];
			dir = right;                    /* same as above */
		}
	}

	/*-----------------------------------------------------------------------------
	 *  2nd, check the reason why jump out of the "while"
	 *-----------------------------------------------------------------------------*/
	if (!vlt) {                                      /* namely, not found */
		return (OBJ) 0;
	}

	/*-----------------------------------------------------------------------------
	 *  3rd, delete, divide into 3 different situaion. be patient
	 *  now, vlt is the removing one
	 *  chl is vlt's right-child
	 *-----------------------------------------------------------------------------*/
	$private(Bnode) * chl = (PTR) vlt->link[right];
	if (!chl) {                                     /* no right-child, easiest */
		prt->link[dir] = vlt->link[left];

	} else if (chl && (!chl->link[left])) {         /* right-child has no left-child */
		chl->link[left] = vlt->link[left];
		prt->link[dir] = (PTR) chl;

	} else if (chl && chl->link[left]) {            /* right-child has left-child */
		$private(Bnode) * leftmost = (PTR) chl->link[left];
		$private(Bnode) * prev;
		while (leftmost->link[left]) {
			prev = leftmost;
			leftmost = (PTR) leftmost->link[left];
		}
		prev->link[left] = leftmost->link[right]; /* able to be NULL */
		leftmost->link[left] = vlt->link[left];   /* able to be NULL */
		leftmost->link[right] = (PTR) chl;
		prt->link[dir] = (PTR) leftmost;
	}
	
	me->cnt--;
	return (OBJ) obj;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  post_order
 *  Description:  walk while do as u say
 *  		  print Bnode info, delete Bnode, or whatever
 *  		  should be wrapped
 * =====================================================================================
 */
static void post_order(OBJ _me, HANDLER do_what)
{
        if (_me) {                                      /* significant judge */
		$private(Bnode) * me = (PTR) _me;
		post_order(me->link[left], do_what);    /* recursive */
		post_order(me->link[right], do_what);
		do_what(_me);                          
	}
}

$call_ginit_class(Bintree, Class, 5,
		 $set(Bintree, ctor),
		 $set(Bintree, dtor),
		 $set(Bintree, search),
		 $set(Bintree, add),
		 $set(Bintree, del));
