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


/*
 *--------------------------------------------------------------------------------------
 *      Method:  getter_str
 *   Parameter:  
 * Description:  return the addr, in heap, by strndup
 *--------------------------------------------------------------------------------------
 */
$getter(STR, str, String)

/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  const char *
 * Description:  strndup helps us to malloc then make a copy to the space
 * 		 String just needs a component which holds the addr of the malloc'd space
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

$call_ginit_class(String, Class, 3, 
		 $set(String, ctor),
		 $set(String, dtor),
		 $set(String, getter_str));
