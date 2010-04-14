/*
 * =====================================================================================
 *
 *       Filename:  Bnode.c
 *
 *    Description:  show the advantage of inheritance
 *
 *        Version:  1.0
 *        Created:  10.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/Bnode.h>

/* essential '0', should let ginit_class() know there's no pair to change */
$defclass(Bnode, Node_abc, 0, 0);
