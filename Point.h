/*
 * =====================================================================================
 *
 *       Filename:  Point.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19.03.10 10:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang Zhang (), imyeyeslove@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef		POINT_H
#define		POINT_H

#include	<omfc/omfc.h>

$inheritance(Point,
	     Class,
	     public,
	     void (* draw)();,
	     private,
	     int x;
	     int y;
	     );

#define         $Point_interface                        \
		$Class_interface;                       \
	     	void (* draw)()

#endif
