SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -W -std=c99 -pedantic

# Rajouter le nom des executables apres '=', separes par un espace.
# Si une ligne est pleine, rajouter '\' en fin de ligne et passer a la suivante.

EXECS = main

.c.o :
	$(CC) -c $(CFLAGS) $*.c

help ::
	@echo "Options du make : help all clean distclean"

all :: $(EXECS)

$(EXECS) : %: %.o
	$(CC) -o $@.out $@.o

clean ::
	\rm -f *.o core && rm -f *out core

distclean :: clean
	\rm -f *% $(EXECS) $(EXECSUTIL) $(EXECSTIMER)
