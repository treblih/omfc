/*
 * =====================================================================================
 *
 *       Filename:  type.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31.03.10 11:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */


#ifndef		TYPE_H
#define		TYPE_H

struct Object {
	struct Object * class;
};


typedef const char *	STR;
typedef void *		PTR;
typedef unsigned	u32;

/* typedef void *		OBJ; */
typedef struct Object *	OBJ;
typedef _Bool		BOOL;

typedef void *(*FUNC)();

#endif
