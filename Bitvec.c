/*
 * =====================================================================================
 *
 *       Filename:  Bitvec.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.04.10 22:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/Bitvec.h>

#define		BIT_INDEX(n)		((n) >> 5)
#define		BIT_OFFSET(n)		((n) % 32)

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
$dclmethod(void, set, $arg(u32));
$dclmethod(void, unset, $arg(u32));

static OBJ init(void);

/*
 *--------------------------------------------------------------------------------------
 *       Class:  point
 *      Method:  point_ctor
 * Description:  
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Bitvec, $arg(va_list * arg))
	va_list ap = *arg;
	u32 len = va_arg(ap, u32) >> 5;                 /* ints = bits / 32 */
	me->bitvec = calloc(1, len);
	return (OBJ) me;
}

$defmethod(void, dtor, Bitvec)
	printf("a Bitvec dead\n");
}

$defmethod(void, set, Bitvec, $arg(u32 index))
	u32 * ptr = me->bitvec + BIT_INDEX(index);
	*ptr |= (1 << BIT_OFFSET(index));
}

$defmethod(void, unset, Bitvec, $arg(u32 index))
	u32 * ptr = me->bitvec + BIT_INDEX(index);
	*ptr &= (0 << BIT_OFFSET(index));
}

static OBJ init()
{
	$call_ginit_class(Bitvec, Class, 4, 
			 $set(Bitvec, ctor),
			 $set(Bitvec, dtor),
			 $set(Bitvec, set),
			 $set(Bitvec, unset));
}

OBJ Bitvec = (OBJ) init;
