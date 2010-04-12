/*
 * =====================================================================================
 *
 *       Filename:  Bintree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.04.10 17:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		BINTREE_H
#define		BINTREE_H

#include	<omfc/omfc.h>
#include	<omfc/Bnode.h>                          /* use Bnode */

$extend(Bintree,
	Class,
	public,
	OBJ (* search)();
	void (* add)();
	OBJ (* del)();,                                 /* essential ',' */
	private,
	OBJ head;                                       /* to the root Bnode */
	size_t cnt;
	);

#define         $Bintree_interface                      \
                $Class_interface;                       \
                OBJ (* search)();                       \
		void (* add)();                         \
		OBJ (* del)()

#endif
