/*
 * =====================================================================================
 *
 *       Filename:  Node_abc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19.03.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#define		NODE_ABC_IMPLEMENTATION

#include	<omfc/Node_abc.h>

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
$dclmethod(int, comp, $arg(OBJ));


/*
 *--------------------------------------------------------------------------------------
 *      Method:  getter_x
 *   Parameter:  
 * Description:  return the value of component X
 *--------------------------------------------------------------------------------------
 */
$getter(T, x, Node_abc);                                   /* whatever ';' */

/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  X
 * Description:  only modify X
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Node_abc, $arg(va_list * arg))
	va_list ap = *arg;
	T x = va_arg(ap, T);
	if (x) {
		me->x = x;
	}
	return (OBJ) me;
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  dtor
 *   Parameter:  
 * Description:  <-DESC->
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, dtor, Node_abc)
	printf("a Node_abc dead\n");
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  comp
 *   Parameter:  anothor node object
 * Description:  return INT to indicate the result
 * 		 -1  a <  b
 * 		 0   a == b
 * 		 1   a >  b
 *--------------------------------------------------------------------------------------
 */
$defmethod(int, comp, Node_abc, $arg(OBJ b))
	$private(Node_abc) * obj = (PTR) b;
	if (me->x < obj->x) {
		return -1;
	} else if (me->x == obj->x) {
		return 0;
	} else {
		return 1;
	}
}

$call_ginit_class(Node_abc, Class, 4,
		 $set(Node_abc, ctor),
		 $set(Node_abc, dtor),
		 $set(Node_abc, comp),
		 $set(Node_abc, getter_x));
