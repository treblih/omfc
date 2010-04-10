/*
 * =====================================================================================
 *
 *       Filename:  Bstree.h
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

#ifndef		BSTREE_H
#define		BSTREE_H

$extend(Bstree,
	Class,
	public,
	search
	private,
	$pri(Tnode) * head;
	size_t cnt;
	);

#define	 	$Bstree_interface                       \
		$Class_interface

#endif
