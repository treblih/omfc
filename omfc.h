/*
 * =====================================================================================
 *
 *       Filename:  omfc.h
 *
 *    Description:  provide all gramma extension for OMFC, all macros here
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

#include	<assert.h>                              /* assert */
#include	<stdlib.h>                             
#include	<stdarg.h>                              /* va_... */
#include	<stdbool.h>                             /* _Bool */
#include	<stdio.h>                               /* ..printf */
#include	<string.h>                              /* memcpy memset */ 
#include	<unistd.h>                              /* size_t off_t */

/* all base header files */
#include	<omfc/type.h>
#include	<omfc/interface.h>
#include	<omfc/generics.h>
#include	<omfc/Class.h>


/*-----------------------------------------------------------------------------
 *  				macros start
 *-----------------------------------------------------------------------------*/

/* GCC recomends to use the builtin function __builtin_offsetof like this */
#define		offsetof(type, member)	__builtin_offsetof(type, member)

/* a trick, just for the boring ',' */
#define	 	$arg(...)		, __VA_ARGS__

/*-----------------------------------------------------------------------------
 *  apply arbitrary method to a certain object. like --  
 *  car->run();
 *  a given object->class->method(object itself, the other args);
 *-----------------------------------------------------------------------------*/
#define	 	$do(obj, msg, ...)	(obj)->class->msg((OBJ)(obj) __VA_ARGS__)

/*-----------------------------------------------------------------------------
 *  could hide all info of a private class except it's meta class pointer
 *  used in general
 *-----------------------------------------------------------------------------*/
#define	 	$pri(A)			struct private_##A##_interface *

/*-----------------------------------------------------------------------------
 *  provide all info of a certain class, used in some special derived class,
 *  such as List & Stack & Queue should have the privilege to control it's Node
 *  if use getter & setter there, too inefficient
 *-----------------------------------------------------------------------------*/
#define	 	$private(A)		struct private_##A *

/*-----------------------------------------------------------------------------
 *  define a method of a class 
 *-----------------------------------------------------------------------------*/
#define         $defmethod(ret, func, cls, ...)         \
	/* no ';' after _me */                          \
static ret func(OBJ _me __VA_ARGS__)                    \
{       /* a class need to manipulate it's components directly, so $private() */ \
	$private(cls) me = (PTR) _me;


/*-----------------------------------------------------------------------------
 *  declare a method. no 'CLASS'. compare with $defmethod()
 *-----------------------------------------------------------------------------*/
#define         $dclmethod(ret, func, ...)              \
	/* no ';' also, while no ';' */                 \
static ret func(OBJ __VA_ARGS__)


/*-----------------------------------------------------------------------------
 *  unused1 -- public
 *  unused2 -- private		just 4 clarity when extending
 *
 *  an 'dclclass' will generates 3 structure:
 *
 *  Sub				meta class, holds method pointer
 *  private_Sub			private data
 *  private_Sub_interface	private part interface for inheritance
 *
 *	and
 *  Sub_interface should be written by yourself explicitly
 *  because the SUB classes ought to have the privilege to use
 *  the method derived from it's super class. so all method in a macro Sub_interface
 *  shoud be wrapped into a non-named structure or no wrapper
 *
 *  finally export the corresponding global class indicator
 *-----------------------------------------------------------------------------*/
#define	 	$dclclass(sub, spr, unused1, public, unused2, private) \
struct sub {                                            \
	/* super methods */                             \
        $##spr##_interface;                             \
	/* new ones */                            	\
	public                                          \
};                                                      \
/* visited by $private(sub), data visible */            \
struct private_##sub {                                  \
	/* obj->class->msg. EVERY OBJECT IS ABLE TO USE IT'S METHODS */ \
        struct sub * class;                             \
	/* can't visit super data directly, because it's a struct */ \
        struct private_##spr##_interface _;             \
	/* new data */                                  \
	private                                         \
};                                                      \
/* visited by $pri(sub), data invisible*/               \
struct private_##sub##_interface {                      \
	struct sub * class;                             \
	/*------------------------------------------------------------------ \
	 *  struct private_Sub {
	 *  	 struct Sub * class;
	 *  	 struct private_Spr_interface _;
	 *  };
	 *
	 *  ==> sizeof(private_Sub) == 4 + sizeof(private_Spr_interface)
	 *
	 *  the whole private_Sub_interface shoud be 4 bytes less than
	 *  private_Sub, because must make space for a differen
	 *  struct sub * class; for next generation
	 *  and in general we use --
	 *
	 *  $pri(Car) * car = (PTR) gnew(Car);
	 *  $do(car, run);
	 *
	 *  so in private_Sub_interface we should remain a way to use 
	 *  it's method that's why this struc also has a 'struc sub * class;'
	 *
	 *  u know why it's '- 8', not '- 4'
	 *-----------------------------------------------------------------*/ \
	char private_##sub##_interface[sizeof(struct private_##sub) - 8];     \
};                                                      \
extern OBJ sub                                          /* no ';' */



#define	 	$class(public, private)            \
struct SUB {                                            \
	public                                          \
};                                                      \
struct private_##SUB {                                  \
        struct SUB * class;                             \
	private                                         \
};                                                      \
struct private_##SUB##_interface {                      \
        char private_##SUB##_interface[sizeof(struct private_##SUB) - 4]; \
};                                                      \
extern OBJ SUB


/*-----------------------------------------------------------------------------
 *  in the end of every .c for less keystroke and clarify the source
 *  for overwrite the inherited methods, 
 *  and also write it's new methods to the class descriptor
 *  see ginit_class() in generics.c
 *-----------------------------------------------------------------------------*/
#define         $write(func)                            \
		offsetof(struct $sub, func), func

#define		$alias(new, ori)                        \
		offsetof(struct $sub, new), offsetof(struct $spr, ori)


/*-----------------------------------------------------------------------------
 *  in the end of every .c for less keystroke and clarify the source
 *-----------------------------------------------------------------------------*/
#define         $defclass(sub, spr, ...)                \
static OBJ init ()                                      \
{                                                       \
	/* sub is global indicator of respective classes.
	 * change from init() pointer */ 		\
        sub = malloc(sizeof(struct sub));               \
	/* modify sub -> region, i.e. the class' descriptor */ \
	ginit_class(sub, spr, sizeof(struct spr), sizeof(struct private_##sub), __VA_ARGS__); \
	/* return the addr, just a copy */              \
	return (OBJ) sub;                               \
}                                                       \
OBJ sub = (OBJ) init      


/* auto getter */
#define         $getter(ret, elem)                      \
$dclmethod(ret, getter_##elem);                         \
$defmethod(ret, getter_##elem, $sub)                    \
        return (ret) me->elem;                          \
}

/* auto setter */
#define         $setter(type, elem)                     \
$dclmethod(void, setter_##elem, $arg(type));            \
$defmethod(void, setter_##elem, $sub, $arg(type arg))   \
        me->elem = arg;                                 \
}


/*-----------------------------------------------------------------------------
 *  generate a var in the stack
 *-----------------------------------------------------------------------------*/
#define         $onstk(_cls, _var, ...)                 \
struct private_##_cls##_interface (_var);               \
if ((PTR) (_cls) < gheap) {                             \
	_cls = (*(FUNC)(_cls))();                       \
}                                                       \
(_var).class = (PTR) (_cls);                            \
gimplicit((OBJ) &(_var) __VA_ARGS__)                    /* init */


extern PTR gheap;

#endif
