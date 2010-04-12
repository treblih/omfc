/*
 * =====================================================================================
 *
 *       Filename:  stream.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/omfc.h>
#include	<omfc/Stack.h>
#include	<omfc/String.h>
#include	<omfc/Stream.h>


int main ( int argc, char *argv[] )
{
	$pri(Stack) * stk = (PTR) gnew(Stack);
	$pri(String) * str = (PTR) gnew(String, "poped is %d\n");
	$pri(Stream) * stm = (PTR) gnew(Stream, 0);

	$do(stk, push, $arg(6));
	$do(stm, put, $arg(str, $do(stk, pop)));

	gdelete((OBJ)stm);
	gdelete((OBJ)str);
	gdelete((OBJ)stk);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
