/*
 * =====================================================================================
 *
 *       Filename:  Node_abc.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08.04.10 10:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		NODE_ABC_H
#define		NODE_ABC_H

#include	 <omfc/omfc.h>

#ifndef		T
#define	 	T		int
#endif

$extend(Node_abc,
	Class,
	public,
	int (* comp)();
	T (* getter_x)();,
	private,
	T x;
	);

#define         $Node_abc_interface                     \
                $Class_interface;                       \
                int (* comp)();                         \
		T (* getter_x)()

#endif
