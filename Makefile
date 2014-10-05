CC=gcc
CFLAGS=-Wall -I. -lgmp 
LD=gcc
LDFLAGS=-lgmp 
OBJ = main.o 

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

lab1: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
