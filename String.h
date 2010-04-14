/*
 * =====================================================================================
 *
 *       Filename:  String.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08.04.10 21:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		STRING_H
#define		STRING_H

#include	<omfc/omfc.h>

#define	 	BUFSIZE		256

/*
 * =====================================================================================
 *        Class:  String
 *  Description:  can't use char[n] as private, because length is variant
 * =====================================================================================
 */
$dclclass(String,
	Class,
	public,
	STR (* getter_str)();,                          /* the string addr */
	private,
	char * str;
	);

#define         $String_interface                       \
                $Class_interface;                       \
		STR (* getter_str)()

#endif
