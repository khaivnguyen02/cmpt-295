SFLAGS = -S -Og
OFLAGS = -g -c
CFLAGS = -o sw


sw: main.o swap.o
	gcc $(CFLAGS) swap.o main.o

main.o:	main.s
	gcc $(OFLAGS) main.s

swap.o: swap.s
	gcc $(OFLAGS) swap.s

main.s:	main.c
	gcc $(SFLAGS) main.c

swap.s: swap.c              # comment out when writing your own swap.s, this way
	gcc $(SFLAGS) swap.c    # gcc will not overwrite it with its own version

clean:
	rm -f sw *.s *.o