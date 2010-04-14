/*
 * =====================================================================================
 *
 *       Filename:  Hnode.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13.04.10 14:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		HNODE_H
#define		HNODE_H

#include	<omfc/Bnode.h>

$dclclass(Hnode,
	Bnode,
	public,
	,
	private,
	PTR node;
	);

#define		$Hnode_interface                        \
		$Bnode_interface

#endif
