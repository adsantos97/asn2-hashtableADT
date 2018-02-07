CC = gcc 
CFLAGS = -O4 -Wall 

#
# -g debug flag
#
ht:	main.o ht.o 
	$(CC) $(CFLAGS) -o ht main.o ht.o misc.o list.o

main.o:	main.c ht.h
	$(CC) $(CFLAGS) -c -O main.c -o main.o

ht.o:	ht.c ht.h
	$(CC) $(CFLAGS) -c -O ht.c -o ht.o

.PHONY: clean
clean:
	@-/bin/rm ht *.bak ht.o main.o a.out core xx xd* &> /dev/null

.PHONY: print
print:
	a2ps --delegate=no -T 4 -q -Avirtual -2 -L70 -o xd main.c ht.h ht.c 

.PHONY: handout
handout:
	a2ps --delegate=no -T 4 -q -Avirtual -2 -L70 -o xd main.c ht.h 
