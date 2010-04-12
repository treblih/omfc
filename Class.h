/*
 * =====================================================================================
 *
 *       Filename:  Class.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31.03.10 14:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		CLASS_H
#define		CLASS_H

#include	<omfc/Nil.h>

/*-----------------------------------------------------------------------------
 *  Class structre. visible, base one
 *-----------------------------------------------------------------------------*/
typedef struct Class {
	struct Object _;                                /* only be visited by a OBJ pointer */
	PTR ptr;                                        /* no use for this moment */
	size_t size;                                    /* private data size */
	$itfce_ctor_dtor;                               /* interfaces, ctor & dtor */
} * CLS;                                                /* quick reference */

/*-----------------------------------------------------------------------------
 *  1st component of every private date struct is a pointer to his respective
 *  meta class, i.e. itself
 *-----------------------------------------------------------------------------*/
struct private_Class {
	struct Class * class;                           
};

/*-----------------------------------------------------------------------------
 *  just 4 next generation
 *  be patient about the ';'. every mid one has a ';' but not the last one
 *  follow the c macro principle
 *  we use char ..._interface[12]; to hide the private info or any other component
 *  u wanna hide
 *-----------------------------------------------------------------------------*/
#define         $Class_interface                        \
		char Class_interface[12];               \
		$itfce_ctor_dtor

/*-----------------------------------------------------------------------------
 *  static initialization, 'cause it's Class, the basic one
 *  private_Class only has one component -- a pointer to Class
 *  but it's volatile, so no space occupied for next generation
 *-----------------------------------------------------------------------------*/
struct private_Class_interface {};

#endif
