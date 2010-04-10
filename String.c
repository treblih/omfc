/*
 * =====================================================================================
 *
 *       Filename:  String.c
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

#include	<omfc/String.h>

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
$dclmethod(STR, getter_str);
static OBJ init(void);

/*
 *--------------------------------------------------------------------------------------
 *       Class:  point
 *      Method:  point_ctor
 * Description:  
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, String, $arg(va_list * arg))
	va_list ap = *arg;
	STR str = va_arg(ap, STR);
        me->str = strndup(str, strlen(str));            /* return char *, not const */
	return (OBJ) me;
}

$defmethod(void, dtor, String)
	printf("a String dead\n");
}

$defmethod(STR, getter_str, String)
	return me->str;
}

static OBJ init()
{
	$call_ginit_class(String, Class, 3, 
			 $set(String, ctor),
			 $set(String, dtor),
			 $set(String, getter_str));
}

OBJ String = (OBJ) init;
