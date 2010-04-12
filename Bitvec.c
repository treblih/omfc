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

/* an u32 has 32 bits */

$dclmethod(OBJ, ctor, $arg(va_list *));
$dclmethod(void, dtor);
$dclmethod(void, set, $arg(u32));
$dclmethod(void, unset, $arg(u32));


/*
 *--------------------------------------------------------------------------------------
 *      Method:  getter_bitvec
 *   Parameter:  
 * Description:  get the addr of the bit vector
 *--------------------------------------------------------------------------------------
 */
$getter(PTR, bitvec, Bitvec);

/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  n bits
 * Description:  calloc an u32-raid holds all the bits need
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Bitvec, $arg(va_list * arg))
	va_list ap = *arg;
	u32 len = U32_NEED(va_arg(ap, u32));            /* U32_NEED, can't >> 5 directly */
	me->bitvec = calloc(1, len);
	return (OBJ) me;
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  dtor
 *   Parameter:  
 * Description:  <-DESC->
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, dtor, Bitvec)
	printf("a Bitvec dead\n");
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  set
 *   Parameter:  index to change
 * Description:  <-DESC->
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, set, Bitvec, $arg(u32 index))
	u32 * ptr = me->bitvec + BIT_INDEX(index);
	*ptr |= (1 << BIT_OFFSET(index));
}

/*
 *--------------------------------------------------------------------------------------
 *      Method:  unset
 *   Parameter:  index to change
 * Description:  <-DESC->
 *--------------------------------------------------------------------------------------
 */
$defmethod(void, unset, Bitvec, $arg(u32 index))
	u32 * ptr = me->bitvec + BIT_INDEX(index);
	*ptr &= (0 << BIT_OFFSET(index));
}

$call_ginit_class(Bitvec, Class, 5,
		 $set(Bitvec, ctor),
		 $set(Bitvec, dtor),
		 $set(Bitvec, set),
		 $set(Bitvec, unset),
		 $set(Bitvec, getter_bitvec));
