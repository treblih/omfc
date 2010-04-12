/*
 * =====================================================================================
 *
 *       Filename:  interface.h
 *
 *    Description:  all interfaces stay here at the moment
 *
 *        Version:  1.0
 *        Created:  08.04.10 13:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		INTERFACE_H
#define		INTERFACE_H

#define         $itfce_ctor_dtor                        \
                OBJ (* ctor)();                         \
		void (* dtor)()

#define	 	$itfce_getter_setter
		

#define		$itfce_push_pop                         \
                void (* push)();                        \
		T (* pop)()

#endif
