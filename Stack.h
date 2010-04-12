/*
 * =====================================================================================
 *
 *       Filename:  Stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08.04.10 11:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		STACK_H
#define		STACK_H

#include	<omfc/omfc.h>
#include        <omfc/Node_abc.h>                       /* use Node_abc */

$extend(Stack,
	Class,
	public,
	$itfce_push_pop;,                               /* interface */
	private,
	OBJ head;
	size_t cnt;
	);

#define         $Stack_interface                        \
		$Class_interface;                       \
		$itfce_push_pop

#endif
