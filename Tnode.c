/*
 * =====================================================================================
 *
 *       Filename:  Tnode.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/Tnode.h>

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
static OBJ init(void);

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Tnode
 *      Method:  ctor
 * Description:  only component need initializing is x, as a new Tnode can only be add
 * 		 as a new leaf
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Tnode, $arg(va_list * arg))
	va_list ap = *arg;
	T x = va_arg(ap, T);
	if (x) {
		me->x = x;
	}
	return (OBJ) me;
}

$defmethod(void, dtor, Tnode)
	printf("a Tnode dead\n");
}

static OBJ init()
{
	$call_ginit_class(Tnode, Class, 2, 
			 $set(Tnode, ctor),
			 $set(Tnode, dtor));
}

OBJ Tnode = (OBJ) init;
