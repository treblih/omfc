/*
 * =====================================================================================
 *
 *       Filename:  Node.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12.04.10 13:10
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
#include         <omfc/Node_abc.h>                          /* derive from Node */

#ifndef		T
#define	 	T		int
#endif

$dclclass(Node, Node_abc,
	public,
	,                                               /* essential ',' */
	private,
	OBJ link;
	);

#define         $Node_interface                         \
                $Node_abc_interface                     /* no ';' */

#endif
