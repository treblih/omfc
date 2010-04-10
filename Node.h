/*
 * =====================================================================================
 *
 *       Filename:  Node.h
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

#ifndef		NODE_H
#define		NODE_H

#include	 <omfc/omfc.h>

#ifndef		T
#define	 	T		int
#endif

$extend(Node,
	Class,
	public,
	,
	private,
	T x;
	OBJ link;
	);

#define         $Node_interface                         \
                $Class_interface                        

#endif
