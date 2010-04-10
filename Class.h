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

typedef struct Class {
	struct Object _;
	PTR ptr;
	size_t size;
	$itfce_ctor_dtor;
} * CLS;

struct private_Class {
	struct Class * class;
};

#define         $Class_interface                        \
		char Class_interface[12];               \
		$itfce_ctor_dtor

struct private_Class_interface {};

#endif
