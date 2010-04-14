/*
 * =====================================================================================
 *
 *       Filename:  Heap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13.04.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include	<omfc/Heap.h>

#define		$sub		Heap
#define		$spr		Class

$dclmethod(OBJ, ctor, $arg(va_list));

$defmethod(OBJ, ctor, Heap, $arg(va_list _arg))
	me->tree = (PTR) gnew(Bintree);                 /* make a Bintree */
	PTR start = va_arg(_arg, PTR);
	/* assert(!((int) start % 0x1000)); */
	me->start = start;
	me->end = va_arg(_arg, PTR);
	me->max = va_arg(_arg, PTR);
	me->spr = va_arg(_arg, int);
	me->rdonly = va_arg(_arg, int);

	header_t * hole = me->start;
	hole->magic = HEAP_MAGIC;
	hole->free = 1;
	hole->size = (int) (start - me->end);

	$do(($pri(Bintree)) me->tree, add, $arg(Hnode, 0x100000, hole));
	return (OBJ) me;
}

$defclass(Heap, Class, 1,
	$write(ctor),
	0);
