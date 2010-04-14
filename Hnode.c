/*
 * =====================================================================================
 *
 *       Filename:  Hnode.c
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
#include	<omfc/Hnode.h>

#define		$sub		Hnode
#define		$spr		Bnode

$dclmethod(OBJ, ctor, $arg(va_list));

$defmethod(OBJ, ctor, Hnode, $arg(va_list _arg))
	size_t size = (size_t) va_arg(_arg, T);
	PTR node = va_arg(_arg, PTR);

	/*-----------------------------------------------------------------------------
	 *  call super class' ctor to init the corresponding part of a node
	 *  Bnode-ctor is a func pointer which points to the original one in Node_abc.c
	 *-----------------------------------------------------------------------------*/
	off_t offset = offsetof(struct Bnode, ctor);
	(*(FUNC *) ((PTR) Bnode + offset))((OBJ) me, &size);

	me->node = node;                                /* init the left */
	return (OBJ) me;
}

$defclass(Hnode, Bnode, 1, 
	$write(ctor),
	0);
