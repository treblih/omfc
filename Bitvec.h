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

$extend(Bitvec,
	Class,
	public,
	void (* set)();
	void (* unset)();,
	private,
	u32 * bitvec;
	);

#define         $Bitvec_interface                       \
		$Class_interface                        \
		void (* set)();                         \
		void (* unset)()

#endif
