SFLAGS = -S -Og
OFLAGS = -g -c
CFLAGS = -o result


result: decode2.o 
	gcc $(CFLAGS) decode2.o

decode2.o:	decode2.s
	gcc $(OFLAGS) decode2.s

decode2.s:	decode2.c
	gcc $(SFLAGS) decode2.c
clean:
	rm -f result *.o