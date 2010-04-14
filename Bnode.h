/*
 * =====================================================================================
 *
 *       Filename:  Bnode.h
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

#ifndef		BNODE_H
#define		BNODE_H

#include	 <omfc/omfc.h>
#include	 <omfc/Node_abc.h>                      /* derive from Node_abc */

#ifndef		T
#define	 	T		int
#endif

/* see below -- OBJ link[2]; */
#define		left		0
#define		right		1

$dclclass(Bnode,
	Node_abc,
	public,
	,                                               /* essential ',' */
	private,
	OBJ link[2];
	);

#define         $Bnode_interface                         \
                $Node_abc_interface                     /* no ';' */

#endif
