/*
 * =====================================================================================
 *
 *       Filename:  Heap.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13.04.10 13:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef		HEAP_H
#define		HEAP_H

#include	<omfc/omfc.h>
#include	<omfc/Bintree.h>
#include	<omfc/Hnode.h>

#define 	HEAP_MAGIC        	0x19881014
#define	 	HEADER_SIZE		sizeof(header_t)
#define	 	FOOTER_SIZE		sizeof(footer_t)
#define		HEAP_SIZE		HEADER_SIZE + FOOTER_SIZE


typedef struct {
    u32 magic;   // Magic number, used for error checking and identification.
    int free;   // 1 if this is a hole. 0 if this is a block.
    size_t size;    // size of the block, including the end footer.
} header_t;

typedef struct {
    u32 magic;     // Magic number, same as in header_t.
    header_t * header; // Pointer to the block header.
} footer_t;

$dclclass(Heap, Class,
	public,
	,
	private,
	OBJ tree;
	PTR start;
	PTR end;
	PTR max;
	int spr;
	int rdonly;
	);

#define		$Heap_interface                         \
		$Class_interface

#endif
