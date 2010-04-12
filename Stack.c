/*
 * =====================================================================================
 *
 *       Filename:  Stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/Stack.h>

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
$dclmethod(void, push, $arg(T));
$dclmethod(T, pop);

static OBJ init(void);


/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  
 * Description:  make sure the stack obj is clean
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Stack, $arg(va_list * arg))
	me->head = (OBJ) 0;
	me->cnt = 0;
	return (OBJ) me;
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  dtor
 *   Parameter:  
 * Description:  <-DESC->
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, dtor, Stack)
	printf("a Stack dead\n");
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  push
 *   Parameter:  X
 * Description:  implements push of the interface. 
 * 		 make a node obj holds the X then add at the start
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, push, Stack, $arg(T x))
	$private(Node) * obj = ($private(Node) *) gnew(Node, x);
        obj->link = me->head;                           /* stack_n.link */
        me->head = (OBJ) obj;                           /* stack.head */
        me->cnt++;                                      /* stack.cnt */
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  pop
 *   Parameter:  
 * Description:  delete the node obj, return the value
 *--------------------------------------------------------------------------------------
 */
$defmethod(T, pop, Stack)
	$private(Node) * obj = ($private(Node) *) me->head;
	T x = obj->x;
	me->head = obj->link;                          /* stack.head */
	me->cnt--;                                            /* stack.cnt */
	gdelete((OBJ)obj);
	return x;
}

static OBJ init()
{
	$call_ginit_class(Stack, Class, 4, 
			 $set(Stack, ctor),
			 $set(Stack, dtor),
			 $set(Stack, push),
			 $set(Stack, pop));
}

OBJ Stack = (OBJ) init;
