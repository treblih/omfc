/*
 * =====================================================================================
 *
 *       Filename:  generics.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31.03.10 14:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		GENERICS_H
#define		GENERICS_H

#ifndef		extern
#ifndef		GENERICS_IMPLEMENTATION
#define		extern		extern
#else
#define		extern
#endif
#endif


#define		gcast(new, old)		(struct new *) old

/* the only thing that one object always have is a pointer to it's class */
#define		gclass_of(_obj)         _obj->class

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  new
 *  Description:  new == calloc(allocate space in heap) + ctor(init)
 *
 *  		  must be a class pointer
 * =====================================================================================
 */
#define         gnew(_cls, ...)		ginit(galloc(_cls()), ##__VA_ARGS__)

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  vgnew
 *  Description:  va_list version
 *  		  like vprintf -- printf; vsprintf -- sprintf
 * =====================================================================================
 */
#define		vgnew(_cls, _arg)	vginit(galloc(_cls()), _arg)

/* extern OBJ gnew(OBJ, ...); */
/* extern OBJ vgnew(OBJ, va_list); */

extern OBJ galloc(OBJ);
extern OBJ ginit(OBJ, ...);
extern OBJ vginit(OBJ, va_list);
extern void gdelete(OBJ);
/* extern PTR gcast(OBJ, OBJ); */

/* extern OBJ gclass_of(const OBJ); */
extern size_t gsize_of(OBJ);
/* extern STR gname_of(OBJ); */
extern BOOL gis_of(OBJ, OBJ);
extern void ginit_class(OBJ, OBJ, size_t, size_t, int, ...);
extern OBJ gimplicit(OBJ, ...);

#endif
