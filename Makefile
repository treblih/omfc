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
CFLAGS	:=	-std=gnu99 -g -rdynamic

BASE	:=	Class.c  Nil.c  generics.c


STACK	:=	stack
STREAM	:=	stream
BINTREE	:=	bintree
POINT	:=	Point

.PHONY:	stack point clean stream bitvec btree

stack:	clean_stack $(STACK) 
stream:	clean_stream $(STREAM) 
point:	clean_point $(POINT) 
btree: clean_bintree $(BINTREE) 
	
$(STACK): 	stack.c
	$(CC) $(CFLAGS) -o $@ $< $(BASE) Stack.c Node_abc.c Node.c
$(BINTREE): 	bintree.c
	$(CC) $(CFLAGS) -o $@ $< $(BASE) Bintree.c Node_abc.c Node.c Bnode.c Hnode.c
$(STREAM): 	stream.c
	$(CC) $(CFLAGS) -o $@ $< $(BASE) Stack.c String.c Stream.c Node_abc.c Node.c
$(POINT):	Point.c
	$(CC) $(CFLAGS) -o $@ $< $(BASE)

clean_stack:
	rem stack
clean_stream:
	rem stream
clean_point:
	rem Point
clean_bintree:
	rem bintree
