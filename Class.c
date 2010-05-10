/*
 * =====================================================================================
 *
 *       Filename:  Class.c
 *
 *    Description:  base class of most derived classes
 *    		    has interfaces ctor & dtor
 *
 *        Version:  1.0
 *        Created:  16.03.10 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#define		CLASS_IMPLEMENTATION

#include	<omfc/omfc.h>

/*-----------------------------------------------------------------------------
 *  static initialization. same as Nil
 *-----------------------------------------------------------------------------*/
static struct Class class = {
	{ (OBJ)&Nil }, 0, sizeof(struct Object), 0, 0
};

const OBJ Object = (OBJ)&class;
const OBJ Class = (OBJ)&class;

/*-----------------------------------------------------------------------------
 *  for global construction & destruction
 *  every global indicator is initialized to respective init() addr, 
 *  all of them are less than gheap(heap start addr)
 *  so 1st call it's init(), during the jurney, change it to it's class descriptor
 *-----------------------------------------------------------------------------*/
PTR gheap;                                              /* global judge */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  gget_heap
 *  Description:  get the heap start addr via sbrk()
 * =====================================================================================
 */
__attribute__ ((__constructor__)) void gget_heap()
{
	gheap = sbrk(0);
	/* static gheap = sbrk(0); */
	/* return gheap; */
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  gclean_all
 *  Description:  so simple, rewind heap pointer to it's original start via brk()
 * =====================================================================================
 */
__attribute__ ((__destructor__)) void gclean_all()
{
	brk(gheap);
}
