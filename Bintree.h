/*
 * =====================================================================================
 *
 *       Filename:  Bintree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.04.10 17:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		BINTREE_H
#define		BINTREE_H

#include	<omfc/omfc.h>
#include	<omfc/Bnode.h>                          /* use Bnode */

/*-----------------------------------------------------------------------------
 *  for extremum()
 *  smallest -- 0 -- left
 *  largest  -- 1 -- right
 *-----------------------------------------------------------------------------*/
#define		SMALLEST		0
#define		LARGEST			1

$dclclass(Bintree, Class,
	public,
	OBJ (* search)();
	void (* add)();
	PTR (* del)();
        OBJ (* extremum)();
        OBJ (* first_fit)();
	size_t (* getter_cnt)();,
	private,
	OBJ head;                                       /* to the root Bnode */
	size_t cnt;
	);

#define         $Bintree_interface                      \
                $Class_interface;                       \
                OBJ (* search)();                       \
		void (* add)();                         \
                PTR (* del)();                          \
                OBJ (* extremum)();                     \
        	OBJ (* first_fit)();                    \
		size_t (* getter_cnt)()

#endif
