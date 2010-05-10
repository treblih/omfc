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
#include	<omfc/Heap.h>

int
main ( int argc, char *argv[] )
{
	$pri(Bintree) tree = (PTR) gnew(Bintree);

#if 0
	$do(tree, add, $arg( 5));
	$do(tree, add, $arg( 3));
	$do(tree, add, $arg( 11));
	$do(tree, add, $arg( 0));
#endif

	$do(tree, add, $arg(Hnode, 5, 0x9048000));
	$do(tree, add, $arg(Hnode, 3, 0x9048000));
	$do(tree, add, $arg(Hnode, 11, 0x9048000));
	$do(tree, add, $arg(Hnode, 10, 0x9048000));

	printf("small %d\n", $do(($pri(Bnode))$do(tree, first_fit, $arg(2)), getter_x));
//	printf("%p\n", $do(tree, search, $arg(11)));
//	printf("%p\n", $do(tree, search, $arg(0)));
//	printf("%p\n", $do(tree, search, $arg(3)));
//	printf("%p\n", $do(tree, search, $arg(5)));

	/* gnew(Heap, 100, 200, 500, 0, 0); */
	gdelete((OBJ) tree);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
