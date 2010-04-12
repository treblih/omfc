/*
 * =====================================================================================
 *
 *       Filename:  bitvec.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.04.10 21:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		BITVEC_H
#define		BITVEC_H

#include	<omfc/omfc.h>

#define		BIT_INDEX(n)		((n) >> 5)
#define		BIT_OFFSET(n)		((n) % 32)
#define		U32_NEED(n)		(((n) - 1 + 32) >> 5)

$extend(Bitvec,
	Class,
	public,
	void (* set)();
	void (* unset)();
	PTR (* getter_bitvec)();,                       /* get the addr */
	private,
	u32 * bitvec;                                   /* start of bit-vec */
	);

#define         $Bitvec_interface                       \
                $Class_interface;                       \
		void (* set)();                         \
		void (* unset)();                       \
		PTR (* getter_bitvec)()

#endif
