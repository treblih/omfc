/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/Stack.h>


#include	<stdlib.h>

	int
main ( int argc, char *argv[] )
{
	$pri(Stack) stk = (PTR) gnew(Stack);
	$do(stk, push, $arg(5));
	printf("%d\n", $do(stk, pop));

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
