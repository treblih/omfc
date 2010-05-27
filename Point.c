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

#undef		$sub
#undef		$spr
#define		$sub		Point
#define		$spr		Class

$dclmethod(OBJ, ctor, va_list);
$dclmethod(void, dtor);
$dclmethod(void, draw);

$defmethod(OBJ, ctor, Point, va_list _arg)
	me->x = va_arg(_arg, int);
	me->y = va_arg(_arg, int);
	return (OBJ) me;
}

$defmethod(void, dtor, Point)
	printf("a point has been dead\n");
}

$defmethod(void, draw, Point)
	printf("x %d, y %d\n", me->x, me->y);
}

$defclass(Point,
	3,
	$write(ctor),
	$write(dtor),
	$write(draw),
	0);
