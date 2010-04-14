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

#define		$sub		Stack
#define		$spr		Class

$dclmethod(OBJ, ctor, $arg(va_list));
$dclmethod(void, dtor);
$dclmethod(void, push, $arg(T));
$dclmethod(T, pop);


/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  
 * Description:  make sure the stack obj is clean
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Stack, $arg(va_list _arg))
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
	$private(Node) obj = (PTR) gnew(Node, x);
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
	$private(Node) obj = (PTR) me->head;
	T x = $do(obj, getter_x);
        me->head = obj->link;                           /* stack.head */
        me->cnt--;                                      /* stack.cnt */
	gdelete((OBJ)obj);                              /* release the node */
	return x;
}

$defclass(Stack, Class,
	4, 
	$write(ctor),
	$write(dtor),
	$write(push),
	$write(pop),
	0);
