/*
 * =====================================================================================
 *
 *       Filename:  List.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.04.10 21:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		LIST_H
#define		LIST_H

#include	<omfc/omfc.h>
#include	<omfc/Stack.h>

$dclclass(List, Stack,
	public,
	PTR (* find_first_null)();
	PTR (* find_first_nonnull)();
	void (* add)();                        
	T (* rem)();,
	private,
	);

#define		$List_interface                         \
                $Stack_interface;                       \
		PTR (* find_first_null)();              \
		PTR (* find_first_nonnull)();           \
		void (* add)();                         \
		T (* rem)()

#endif
