/*
 * =====================================================================================
 *
 *       Filename:  omfc.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31.03.10 10:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		OMFC_H
#define		OMFC_H

#include	<assert.h>                              /* for calloc */
#include	<stdlib.h>                              /* for calloc */
#include	<stdarg.h>                              
#include	<stdbool.h>                              
#include	<stdio.h>                              
#include	<string.h>                              /* for calloc */
#include	<unistd.h>                              

#include	<omfc/type.h>
#include	<omfc/interface.h>
#include	<omfc/generics.h>
#include	<omfc/Class.h>

#define		offsetof(type, member)		__builtin_offsetof(type, member)

#define	 	$arg(...)		, __VA_ARGS__

#define	 	$do(obj, msg, ...)	(obj)->class->msg((OBJ)(obj) __VA_ARGS__)

#define	 	$pri(A)				struct private_##A##_interface
#define	 	$private(A)			struct private_##A


#define         $4sizeof(A)                             \
struct A##_4sizeof


#define         $defmethod(ret, func, class, ...)       \
static ret func(OBJ _me __VA_ARGS__)                    \
{                                                       \
	$private(class) * me = ($private(class) *) _me;


#define         $dclmethod(ret, func, ...)              \
static ret func(OBJ __VA_ARGS__)


#define	 	$extend(sub, spr, unused1, public, unused2, private) \
struct sub {                                            \
        $##spr##_interface;                             \
	public                                          \
};                                                      \
struct private_##sub {                                  \
        struct sub * class;                             \
        struct private_##spr##_interface _;             \
	private                                         \
};                                                      \
struct private_##sub##_interface {                      \
	/* just for obj->class->msg */                  \
	struct sub * class;                             \
	/*------------------------------------------------------------------ \
	 *  1st 4 is .class, the other is make space for the next generation \
	 *  see private_##sub above                     \
	 *-----------------------------------------------------------------*/ \
        char private_##sub##_interface[sizeof(struct private_##sub) - 8];     \
};                                                      \
extern OBJ sub                                          /* no ; */



#define	 	$class(sub, public, private)            \
struct sub {                                            \
	public                                          \
};                                                      \
struct private_##sub {                                  \
        struct sub * class;                             \
	private                                         \
};                                                      \
struct private_##sub##_interface {                      \
        char private_##sub##_interface[sizeof(struct private_##sub) - 4];     \
};                                                      \
extern OBJ sub


#define         $set(cls, func)                         \
		offsetof(struct cls, func), func

#define         $call_ginit_class(sub, spr, ...)        \
sub = malloc(sizeof(struct sub));                       \
ginit_class(sub, spr, sizeof(struct spr), sizeof($private(sub)), __VA_ARGS__); \
return (OBJ) sub


extern PTR gheap;

#endif
