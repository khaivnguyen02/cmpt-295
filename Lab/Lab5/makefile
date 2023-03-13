# 1) In order to (maybe) experience a "segmentation fault" 
#    when a password exceeds the size of the buffer,
#    "make" the program with the flag "-fno-stack-protector".  
#    
# 2) In order to experience gcc's protection, 
#    i.e., the detection of buffer overflow via 
#    the use of canary when a password exceeds
#    the size of the buffer, "make clean", 
#    comment out the SFLAGS with "-fno-stack-protector", 
#    uncomment the SFLAGS without "-fno-stack-protector" 
#    and "make" the program again.

SFLAGS = -S -O2 -fno-stack-protector
# SFLAGS = -S -O2
OFLAGS = -g -c
CFLAGS = -o pw

all: pw

pw:	password.o 
	gcc $(CFLAGS) password.o

password.o:	password.s
	gcc $(OFLAGS) password.s

password.s:	password.c
	gcc $(SFLAGS) password.c

clean:	
	rm -f pw *.o password.s