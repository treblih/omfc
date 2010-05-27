/*
 * =====================================================================================
 *
 *       Filename:  Class.c
 *
 *    Description:  base class of most derived classes
 *
 *        Version:  1.0
 *        Created:  16.03.10 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include	<omfc/omfc.h>

/*-----------------------------------------------------------------------------
 *  static initialization
 *-----------------------------------------------------------------------------*/
static struct Class class = {
	{ (OBJ)&class }, 0, sizeof(struct Object), 0, 0
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Class
 *  Description:  only one public interface
 * =====================================================================================
 */
OBJ Class()
{
	return (OBJ)&class;
}
