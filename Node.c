/*
 * =====================================================================================
 *
 *       Filename:  Node.c
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
#define		NODE_IMPLEMENTATION

#include	<omfc/Node.h>

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
static OBJ init(void);

/*
 *--------------------------------------------------------------------------------------
 *       Class:  point
 *      Method:  point_ctor
 * Description:  
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Node, $arg(va_list * arg))
	va_list ap = *arg;
	T x = va_arg(ap, T);
	if (x) {
		me->x = x;
	}
	return (OBJ) me;
}

$defmethod(void, dtor, Node)
	printf("a Node dead\n");
}

static OBJ init()
{
	$call_ginit_class(Node, Class, 2, 
			 $set(Node, ctor),
			 $set(Node, dtor));
}

OBJ Node = (OBJ) init;
