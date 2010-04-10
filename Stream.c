/*
 * =====================================================================================
 *
 *       Filename:  Stream.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/Stream.h>


$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
$dclmethod(int, put, $arg($pri(String) *, ...));
static OBJ init(void);

/*
 *--------------------------------------------------------------------------------------
 *       Class:  point
 *      Method:  point_ctor
 * Description:  
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Stream, $arg(va_list * arg))
	va_list ap = *arg;
	STR str = va_arg(ap, STR);
	me->stm = str ? fopen(str, "r+") : stdout;            /* return char *, not const */
	return (OBJ) me;
}

$defmethod(void, dtor, Stream)
	printf("a Stream dead\n");
	if (me->stm) {
		fclose(me->stm);
	}
}

$defmethod(int, put, Stream, $arg($pri(String) * format, ...))
	va_list ap;
	va_start(ap, format);
	int n = vfprintf(me->stm, $do(format, getter_str), ap);
	return n;
}

static OBJ init()
{
	$call_ginit_class(Stream, Class, 3, 
			 $set(Stream, ctor),
			 $set(Stream, dtor),
			 $set(Stream, put));
}

OBJ Stream = (OBJ) init;
