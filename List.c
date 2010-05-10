/*
 * =====================================================================================
 *
 *       Filename:  List.c
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

#include	<omfc/List.h>

#define		$sub		List
#define		$spr		Stack


$dclmethod(PTR, find_first_null);
$dclmethod(PTR, find_first_nonnull);

$defmethod(PTR, find_first_null, List)
	$private(Node) node = $do(me, getter_head);
	
	while (node) {
		if ($do(node, getter_x)) {
			node = (PTR) node->link;
		} else {
			break;
		}
	}
	return (PTR) node;                              /* maybe NULL */
}

$defmethod(PTR, find_first_nonnull, List)
	$private(Node) node = $do(me, getter_head);

	while (node) {
		if (!$do(node, getter_x)) {
			node = (PTR) node->link;
		} else {
			break;
		}
	}
	return (PTR) node;                              /* maybe NULL */
}

$defclass(List, Stack,
	2,
	$write(find_first_null),
	$write(find_first_nonnull),
	2,
	$alias(add, push),
	$alias(rem, pop));
