/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/omfc.h>
#include	<omfc/List.h>


int
main ( int argc, char *argv[] )
{
	$pri(List) list = (PTR) gnew(List);
	$do(list, add, $arg(2));
	$do(list, add, $arg(6));
	$do(list, add, $arg(61));
	/* $do(list, rem); */

	T x = $do(($pri(Node))$do(list, find_first_nonnull), getter_x);
	
	printf("%d\n", x);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
