# UNIX C makefile for tmenu

CC = cc
CFLAGS = -O
LDFLAGS =
LIBS = -lc

OBJS = tmenu.o getdir.o unwind.o displaymenu.o exec.o compare.o countlist.o
tmenu : $(OBJS)
	ld -s -i -X /lib/crt0.o -o tmenu $(OBJS) $(LIBS)

clean : 
	-rm *.o tmenu

