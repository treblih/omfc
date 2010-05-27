/*
 * =====================================================================================
 *
 *       Filename:  point.c
 *
 *    Description:  
 *
 *        Created:  27.05.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include 	<omfc/Point.h>
#include	<stdlib.h>

int
main(int argc, char *argv[])
{
	$pri(Point) point = (PTR) gnew(Point, 5, 6);
	$do(point, draw);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
