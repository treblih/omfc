/*
 * =====================================================================================
 *
 *       Filename:  Nil.c
 *
 *    Description:  Nil class, base one
 *
 *        Version:  1.0
 *        Created:  31.03.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include	<omfc/omfc.h>
#include	<omfc/Nil.h>

/*-----------------------------------------------------------------------------
 *  static initialization. same as Class
 *-----------------------------------------------------------------------------*/
static struct Object nil = { (OBJ)0 };
const OBJ Nil = (OBJ)&nil;                              /* global indicator */
