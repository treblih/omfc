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

#undef		$sub
#undef		$spr
#define		$sub		Stack
#define		$spr		Class

$dclmethod(OBJ, ctor, va_list);
$dclmethod(void, dtor);
$dclmethod(void, push, T);
$dclmethod(T, pop);


$get(PTR, head);
$get(size_t, cnt);

/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  
 * Description:  make sure the stack obj is clean
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Stack, va_list _arg)
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
$defmethod(void, push, Stack, T x)
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
	T x = $do(obj, get_x);
        me->head = obj->link;                           /* stack.head */
        me->cnt--;                                      /* stack.cnt */
	gdelete((OBJ)obj);                              /* release the node */
	return x;
}

$defclass(Stack, Class,
	6, 
	$write(ctor),
	$write(dtor),
	$write(push),
	$write(pop),
	$write(get_head),
	$write(get_cnt),
	0);

Stack()
{
	static is_exist;
	static class_addr;

	if (!is_exist) {
		/* sub is global indicator of respective classes.
		 * change from init() pointer */ 		
		struct Stack * stk = malloc(sizeof(struct Stack));               
		/* modify sub -> region, i.e. the class' descriptor */ 
		ginit_class(Stack, Class, sizeof(struct spr), sizeof(struct private_##sub), ##__VA_ARGS__); 
		/* return the addr, just a copy */              
		return (OBJ) sub;                               
	}
	return class_addr;
}
