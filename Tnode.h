/*
 * =====================================================================================
 *
 *       Filename:  Tnode.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.04.10 17:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		TNODE_H
#define		TNODE_H

#include	 <omfc/omfc.h>

#ifndef		T
#define	 	T		int
#endif

$extend(Tnode,
	Class,
	public,
	,
	private,
	T x;
	OBJ left;
	OBJ right;
	);

#define         $Tnode_interface                         \
                $Class_interface                        

#endif
