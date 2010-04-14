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

#define		$sub		Bitvec
#define		$spr		Class

$dclmethod(OBJ, ctor, $arg(va_list));
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
$getter(PTR, bitvec);

/*
 *--------------------------------------------------------------------------------------
 *      Method:  ctor
 *   Parameter:  n bits
 * Description:  calloc an u32-raid holds all the bits need
 *--------------------------------------------------------------------------------------
 */
$defmethod(OBJ, ctor, Bitvec, $arg(va_list _arg))
	u32 len = U32_NEED(va_arg(_arg, u32));            /* U32_NEED, can't >> 5 directly */
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

$defclass(Bitvec, Class, 5,
	 $write(ctor),
	 $write(dtor),
	 $write(set),
	 $write(unset),
	 $write(getter_bitvec),
	 0);
