# # Makefile for dip.	-*- Indented-Text -*-
# Copyright (C) 2009 Free Software Foundation, Inc.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# 19.12.09, Yang Zhang, NUIST, Nanjing, CHN.

#### Start of system configuration section. ####
CC	:=	gcc
CFLAGS	:=	-Wall -std=gnu99 -g

BASE	:=	Class.c  Nil.c  generics.c test.c


STACK	:=	bit
POINT	:=	Point

.PHONY:	stack point clean

stack:	clean_stack $(STACK) 
point:	clean_point $(POINT) 
	
$(STACK): 	Bitvec.c
	$(CC) $(CFLAGS) -o $@ $< $(BASE)
$(POINT):	Point.c
	$(CC) $(CFLAGS) -o $@ $< $(BASE)

clean_stack:
	rem bit
clean_point:
	rem Point
