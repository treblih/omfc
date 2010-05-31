/*
 * =====================================================================================
 *
 *       Filename:  Point.c
 *
 *    Description:  
 *
 *        Created:  26.05.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include 	<omfc/Point.h>

#define		$sub			Point
#define		$private_sub		private_Point
#define		$spr			Class

$dclmethod(OBJ, ctor, va_list);
$dclmethod(void, dtor);
$dclmethod(void, draw);

$defmethod(OBJ, ctor, va_list _arg)
	me->x = va_arg(_arg, int);
	me->y = va_arg(_arg, int);
	return (OBJ) me;
}

$defmethod(void, dtor)
	printf("a point has been dead\n");
}

$defmethod(void, draw)
	printf("x %d, y %d\n", me->x, me->y);
}

$defclass(3, $write(ctor), $write(dtor), $write(draw), 0);
