/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<omfc/omfc.h>
#include	<omfc/Bitvec.h>

int
main ( int argc, char *argv[] )
{
	$pri(Bitvec) * bit = (PTR) gnew(Bitvec, 32);

	$do(bit, set, $arg(1));
	$do(bit, unset, $arg(1));

	gdelete((OBJ)bit);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
