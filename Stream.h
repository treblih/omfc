/*
 * =====================================================================================
 *
 *       Filename:  Stream.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09.04.10 10:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		STREAM_H
#define		STREAM_H

#include	<omfc/omfc.h>
#include	<omfc/String.h>                         /* use, not derive */

$extend(Stream,
	Class,
	public,
	int (* put)();,
	private,
	FILE * stm;                                     /* FILE descriptor */
	);

#define	 	$Stream_interface                       \
                $Class_interface;                       \
		int (* put)()

#endif
