/*
 * Filename: Lecture_7_Demo.c
 *
 * Purpose: Demonstrating the effect of fixed size memory
 *          when manipulating floating point representation of fractional decimal numbers:
 *          looking at conversion, addition, associativity when adding and multiplying, and rounding.  
 * 
 * Author: 
 * Revision: Jan. 2023
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%p\t0x%.2x\n", &start[i], start[i]); 
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); 
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}


int main(int argc, char *argv[]) {
    int action = 0;
    const int CONVERSION = 1;
    const int ADDITION = 2;
    const int ASSOCIATIVITY = 3;
    const int ROUNDING = 4;

    if ( argc < 2 ) {
        printf("Forgot the argument? Try again!\n");    
        return 1;
    }
    
    if (argc == 2) {
        action = atoi(argv[1]);
        if ( action == CONVERSION) {

            printf("\nConversion int -> float:\n");
            int x = 346;
            float f = (float) x;
            printf("int(%d) -> float(%.4f)\n", x, f);
            printf("int(%d):\n", x);
            show_int(x);
            printf("float(%.4f):\n", f);
            show_float(f);

            printf("Conversion float -> int:\n");
            f = 346.625;
            x = (int) f;
            printf("float(%.4f) -> int(%d)\n", f, x);
            printf("int(%d):\n", x);
            show_int(x);
            printf("float(%.4f):\n", f);
            show_float(f);
        }

        if ( action == ADDITION ) { 

            printf("\nAddition:\n");
            float x = 8.625;
            printf("x is %0.3f\n", x);            
            show_float(x);
            float y = 18.015625;
            printf("y is %0.3f\n", y);  
            show_float(y);
            float sum = x + y;
            printf("x (%0.3f) + y (%0.6f) = %0.6f\n", x, y, sum);
            show_float(sum);  
        }
        
        if ( action == ASSOCIATIVITY ) {      

            printf("\nAssociativity:\n");
            float f1 = 3.14;
            float f2 = 1e20;
            float f3 = 1e-9;

            printf("f1 = %E\n", f1);
            show_float(f1);
            printf("f2 = %E\n", f2);
            show_float(f2);
            printf("f3 = %E\n",f3);
            show_float(f3);

            printf("\nAssociativity - Addition and subtraction:\n");
            printf("f1+f2: %E+%E = %E\n",f1, f2, (f1+f2));
            show_float(f1+f2);

            printf("(f1+f2)-f2: (%E+%E)-%E = %E\n",f1, f2, f2, (f1+f2)-f2);
            printf("f1+(f2-f2): %E+(%E-%E) = %E\n\n",f1, f2, f2, f1+(f2-f2));

            printf("Associativity - Multiplication:\n");
            printf("(f2*f2)*f3 (overflow): (%E*%E)*%E = %E\n", f2, f2, f3, (f2*f2)*f3);
            printf("f2*(f2*f3): %E*(%E*%E) = %E\n\n", f2, f2, f3, f2*(f2*f3));

            printf("Associativity - Interesting case:\n");        
            printf("(f2*f2)-(f2*f2) -> (INF - INF = -NAN) : (%E*%E)-(%E*%E) = %E\n\n", f2, f2, f2, f2, (f2*f2)-(f2*f2));
        }

        if ( action == ROUNDING ) { 

            printf("\nRounding:\n");
            float stop = 2.0;
            printf("Starting at k = 0.0, add 0.1 at each iteration and stop when k is no longer <= 2.0.\n");
            printf("Setting stop to 2.0\n");
            show_float(stop);
            float k = 0.0;
            printf("And k = %0.1f\n", k);
            show_float(stop);
            unsigned int iter = 0;
            while ( k <= stop ) {
                printf("\nIteration %d ", ++iter);       
                printf("k = %0.1f\t\t%E\n", k, k);
                show_float(k);
                k += 0.1; 
            }
            printf("\nStop: %0.1f\t%E\n", stop, stop);
            show_float(stop);
            printf("k: %0.1f\t\t%E\n", k, k);
            show_float(k);  
        }
    }
    return 0;
}