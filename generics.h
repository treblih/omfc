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

extern OBJ gnew(OBJ, ...);
extern OBJ galloc(OBJ);
extern OBJ ginit(OBJ, va_list *);
extern void gdelete(OBJ);
extern PTR gcast(OBJ, OBJ);

extern OBJ gclass_of(const OBJ);
extern size_t gsize_of(OBJ);
extern STR gname_of(OBJ);
extern BOOL gis_of(OBJ, OBJ);
extern void ginit_class(OBJ, OBJ, size_t, size_t, int, ...);


extern const OBJ Object;
extern const OBJ Class;


#endif
