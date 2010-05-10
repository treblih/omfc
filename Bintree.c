/*
 * =====================================================================================
 *
 *       Filename:  Bintree.c
 *
 *    Description:  obj -- a new Bnode which holds the data X, stable
 *    		    vlt	-- represents "volatile", changable
 *
 *    		    Bnode is basic, use it all over the world except one --
 *    		    vgnew() in add
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

#define		$sub		Bintree
#define		$spr		Class

$dclmethod(OBJ, ctor, $arg(va_list));
$dclmethod(void, dtor);
$dclmethod(OBJ, search, $arg(T));
$dclmethod(void, add, $arg(OBJ, ...));
$dclmethod(PTR, del, $arg(T));
$dclmethod(OBJ, extremum, $arg(BOOL));
$dclmethod(OBJ, first_fit, $arg(T));

static void post_order(OBJ, NORET);


/*
 *--------------------------------------------------------------------------------------
 *      Method:  getter_cnt
 *   Parameter:  
 * Description:  tree node count
 *--------------------------------------------------------------------------------------
 */
$getter(size_t, cnt);

/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:
 * Description:  make sure all data is 0
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Bintree, $arg(va_list _arg))
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
	$private(Bnode) vlt = (PTR) me->head;
	$onstk(Bnode, obj, $arg(x));                    /* on stack */

	/*-----------------------------------------------------------------------------
	 *  use Bnode's comp, which derived from class Node
	 *-----------------------------------------------------------------------------*/
	while (vlt) {
		int res = $do(vlt, comp, $arg((OBJ) &obj));
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
 *   Parameter:  node_type, corresponding data
 * Description:  make a node obj holds the X then add a new one to the fit position
 *
 * 		 Bnode is the basic node that fits the requestion of a bin-tree
 * 		 all other type derived from Bnode should also be controled by a 
 * 		 bin-tree well, so here when producing a new node, the func need to
 * 		 know the specific type
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, add, Bintree, $arg(OBJ node_type, ...))
	va_list arg;
	va_start(arg, node_type);
	$private(Bnode) vlt = (PTR) me->head;

	/*-----------------------------------------------------------------------------
	 *  only one interface for different node types
	 *-----------------------------------------------------------------------------*/
	$private(Bnode) obj = (PTR) vgnew(node_type, arg);

	/* make sure every Bnode is clean, it's calloc'd */
        if (!vlt) {                                     /* is the tree empty? */
		me->head = (PTR) obj;
		goto end;
	}
	while (1) {
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
end:
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
 * 		 
 * 		 VLT WANTED !!
 *--------------------------------------------------------------------------------------
 */
$defmethod(PTR, del, Bintree, $arg(T x))
	int dir = 0;                                    /* direction */
	$private(Bnode) vlt = (PTR) me->head;
	/*-----------------------------------------------------------------------------
	 *  during the control-flow below, prt will be vlt's parent
	 *  but now init it with vlt
	 *  so if just 1 node in the tree, treat it specially
	 *-----------------------------------------------------------------------------*/
        $private(Bnode) prt = vlt;                    
        $private(Bnode) obj = (PTR) gnew(Bnode, x);     /* removing one */

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
		return NULL;
	}

	/*-----------------------------------------------------------------------------
	 *  prt == vlt ==> deleting root node
	 *-----------------------------------------------------------------------------*/
	BOOL del_root;
	if (prt == vlt) {
		del_root = true;
	}

	/*-----------------------------------------------------------------------------
	 *  3rd, delete, divide into 3 different situaion. be patient
	 *  now, vlt is the removing one
	 *  chl is vlt's right-child
	 *-----------------------------------------------------------------------------*/
	$private(Bnode) chl = (PTR) vlt->link[right];
	if (!chl) {                                     /* no right-child, easiest */
		del_root ? (me->head 	   = vlt->link[left]):
			   (prt->link[dir] = vlt->link[left]);

	} else if (chl && (!chl->link[left])) {         /* right-child has no left-child */
		chl->link[left] = vlt->link[left];
		del_root ? (me->head 	   = (PTR) chl):
			   (prt->link[dir] = (PTR) chl);

	} else if (chl && chl->link[left]) {            /* right-child has left-child */
		$private(Bnode) leftmost = (PTR) chl->link[left];
		$private(Bnode) prev;
		while (leftmost->link[left]) {
			prev = leftmost;
			leftmost = (PTR) leftmost->link[left];
		}
		prev->link[left] = leftmost->link[right]; /* able to be NULL */
		leftmost->link[left] = vlt->link[left];   /* able to be NULL */
		leftmost->link[right] = (PTR) chl;
		del_root ? (me->head 	   = (PTR) leftmost):
			   (prt->link[dir] = (PTR) leftmost);
	}
	
	me->cnt--;
	/* T x = $do(vlt, getter_x); */
	gdelete((OBJ) vlt);
	/* return x; */
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  extremum
 *   Parameter:  
 *  Description:  find the smallest / largest
 *  		  ex -- 0 -- smallest -- left
 *  		        1 -- largest  -- right
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, extremum, Bintree, $arg(BOOL ex))
	$private(Bnode) vlt = (PTR) me->head;
	while (vlt->link[ex]) {
		vlt = (PTR) vlt->link[ex];
	}
	return (OBJ) vlt;
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  first_fit
 *   Parameter:  
 * Description:  find the 1st which could contain the X, i.e. 1st >= X
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, first_fit, Bintree, $arg(T x))
	$private(Bnode) vlt = (PTR) me->head;
	while (x >= $do(vlt, getter_x)) {
		vlt = (PTR) vlt->link[right];           /* impossible left */
	}
	return (OBJ) vlt;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  post_order
 *  Description:  walk while do as u say
 *  		  print Bnode info, delete Bnode, or whatever
 *  		  should be wrapped
 * =====================================================================================
 */
static void post_order(OBJ _me, NORET do_what)
{
        if (_me) {                                      /* significant judge */
		$private(Bnode) me = (PTR) _me;
		post_order(me->link[left], do_what);    /* recursive */
		post_order(me->link[right], do_what);
		do_what(_me);                          
	}
}

$defclass(Bintree, Class, 8,
	 $write(ctor),
	 $write(dtor),
	 $write(search),
	 $write(add),
	 $write(del),
	 $write(extremum),
	 $write(first_fit),
	 $write(getter_cnt),
	 0);
