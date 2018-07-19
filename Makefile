CC = gcc
CFLAGS = -O2 -Wall -Werror
LFLAGS = -lm

cnami:
	$(CC) $(CLFAGS) -o bin/cnami src/cnami.c $(LFLAGS)

clean:
	rm bin/cnami
