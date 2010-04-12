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
#include	<omfc/Bintree.h>

int
main ( int argc, char *argv[] )
{
	$pri(Bintree) * tree = (PTR) gnew(Bintree);

	$do(tree, add, $arg(5));
	$do(tree, add, $arg(3));
	$do(tree, add, $arg(11));
	$do(tree, add, $arg(0));

	printf("%p\n", $do(tree, search, $arg(11)));
	printf("%p\n", $do(tree, search, $arg(0)));
	printf("%p\n", $do(tree, search, $arg(3)));
	printf("%p\n", $do(tree, search, $arg(5)));
	gdelete((OBJ) tree);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
