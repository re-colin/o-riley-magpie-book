#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 20240217
// THIS FILE IS ABOUT POINTERS.

int main() {
     // ### Declaration / definition, best practice 
     int *np1 = NULL;
     int num1 = 200;
     np1 = &num1;  
      
//     *np1 = 300; // lvalue, reassignment via dereference

     printf("Octal: %o\n", *np1);
     printf("Hex: %x\n", *np1);
     printf("Decimal: %d\n", *np1);

     printf("Address of np1: %p\n", &np1);
     printf("Value of np1: %d\n", *np1);
  
     // int casting - probably bad practice 
     int *np2;
     uintptr_t num2 = 100;
     np2 = (int*)num2; 
     // printf("%d\n", np2); // argument type conflict, prints 100

     // ### Void pointers
     void *vp1 = np2;
     char c = 'A';
     int n = 2; 

     vp1 = &c;
     printf("%p\n", vp1); // Multiplatform pointer display support
     vp1 = &n;

     // Revert casting
     int e = 100;
     int *pi = &e;
     printf("Value of pi: %d\n", *pi);
     void *pv = pi;
     pi = (int *)pv;
     printf("Value of pi: %d\n", *pi);

     // Pointer arithmetic, subtraction, overflow
     int vectors[] = {17, 4, 31, 24};
     int *vp = vectors;

     // If you initialize the above variables as shorts (2), you will notice a 2 byte addition for each item instead of 4
     // The array overflow also won't produce garbage values as large as if they were regular integers.
     printf("\nAddress of vp: %p\nValue of vp: %d\n", vp, *vp); // 0x7ffee8f5a790, 17
     vp++; // vp = vp + 1 is also valid.
     printf("Address of vp: %p\nValue of vp: %d\n", vp, *vp);   // 0x7ffee8f5a794, 4
     vp--;
     printf("Address of vp: %p\nValue of vp: %d\n", vp, *vp);   // 0x7ffee8f5a790, 17

     vp += 4; // Array overflow
     printf("Address of vp: %p\nValue of vp: %d\n", vp, *vp);   // Garbage value

     // Differences between pointers
     int *p0 = vectors;
     int *p1 = vectors + 1;
     int *p2 = vectors + 2;
     int *p3 = vectors + 3;

     printf("\n*p3 - *p2: %d\n", *p3 - *p2);
     printf("\np0 - p2: %ld\n", p0 - p2);
     printf("\np0 - p2: %ld\n", p0 - p2);

     printf("Value of p3: %d\n", *p3);

     // Comparison operations (Addresses)
     printf("p2 > p3: %d\n", p2 > p3); // False / 0

     // Comparison operations (Dereferenced values)
     printf("*p2 > *p3: %d\n", *p2 > *p3); // True / 1 

     // ### Other Pointer Uses  
     // Levels of Indirection
     
     char *titles[] = {"A Tale of Two Cities", "Wuthering Heights","Don Quixote", "Odyssey","Moby-Dick","Hamlet", "Gulliver's Travels"};
     char **bestBooks[3];
     char **englishBooks[4]; // Making this a single pointer warrants an incompatible assignment warning

     bestBooks[0] = &titles[0];
     bestBooks[1] = &titles[1];
     bestBooks[2] = &titles[2];
     englishBooks[1] = &titles[3];
     englishBooks[2] = &titles[4];
     englishBooks[3] = &titles[5]; // NOTE: These are not matched correctly to their descriptors, but for this example I've decided that some of these are English and some of them are the best arbitrarily and not on real merit.
     // NOTE: Make a graph of this.

     printf("\nbestBooks[0]: %s\n", *bestBooks[0]);
     printf("englishBooks[1]: %s\n", *englishBooks[1]);
    
     // Constants and Pointers 
     int d = 50;
     int const* cpi = &d;
     printf("%d\n", *cpi);
     // *cpi = 51; read-only variable not assignable


     return 0;
}
