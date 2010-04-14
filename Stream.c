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

#define		$sub		Stream
#define		$spr		Class

$dclmethod(OBJ, ctor, $arg(va_list));
$dclmethod(void, dtor);
$dclmethod(int, put, $arg($pri(String), ...));


/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  a const char *, i.e. the file name
 * Description:  if file name == NULL, regard STDOUT as default
 * 		 Stream has a component FILE * stm
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Stream, $arg(va_list _arg))
	STR str = va_arg(_arg, STR);
	me->stm = str ? fopen(str, "r+") : stdout;            /* return char *, not const */
	return (OBJ) me;
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  dtor
 *   Parameter:  
 * Description:  close the FILE stream
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, dtor, Stream)
	printf("a Stream dead\n");
//	if (me->stm) {
//		fclose(me->stm);
//	}
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  put
 *   Parameter:  const char *, the format part;
 *   		 substitution part
 * Description:  put the string and the substitution part(just like ones in printf)
 * 		 into a certain FILE me->stm
 *--------------------------------------------------------------------------------------
 */
$defmethod(int, put, Stream, $arg($pri(String) format, ...))
	va_list arg;
	va_start(arg, format);
	int n = vfprintf(me->stm, $do(format, getter_str), arg);
	return n;
}

$defclass(Stream, Class, 3, 
	 $write(ctor),
	 $write(dtor),
	 $write(put),
	 0);
