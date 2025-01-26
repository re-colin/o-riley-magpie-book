#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 20240219
// CH2: DYNAMIC MEMORY MANAGEMENT
// ALLOCATE AND FREE WITH CAUTION.

int main() 
{
      // malloc, support, free
      int *pi = (int*) malloc(sizeof(int));
      *pi = 5;
      printf("*pi: %d\n", *pi);    
      free(pi);
      printf("pi: %p\n", pi);    
      *pi = 0; // assign NULL after memory freed 
      printf("*pi: %d\n", *pi);    
     
      // Reassigning address values  
      char *pc = (char*)malloc(6); // allocated for string of length 6 (including null termination)
      for (int i = 0; i < 8; i++) {
            pc[i] = 0;
            printf("%d\n", pc[i]); 
      }

      // Do not run this block
      // char *uc;
      // while (1) {
      //      uc = (char*) malloc(10000000000000);
      //      printf("Allocating %p.....", uc);
      // }

      char *name = (char*) malloc(strlen("Colin")+1);
      // strcpy(name, "Colin");
      name = "Colin";
      printf("%s\n", name); 

      while (*name != 0) {
            printf("%c\n", *name);
            name++;
      }
      printf("%s\n", name); // Original address lost - name now points to strings NUL char.

      int *lp = (int *) malloc(sizeof(int));
      *lp = 5;
      printf("Value of lp: %d\n", *lp);
      lp = (int*) malloc(sizeof(int));
      printf("Value of lp: %d\n", *lp); // Data lost - memory was re-allocated

      // This block terminates once you input anything. We're referencing memory that hasn't been allocated.
      //char *nam;
      // scanf("%s\n", nam);
      // printf("Your name is %s", name);

      // ### Using calloc()
      int *cp = calloc(5, sizeof(int));
      int c = 2000;
      cp = &c;
      *cp = 10;

      // Equivalent result
      int *mp = malloc(5 * sizeof(int));
      // memset(mp, 0, 5 * sizeof(int)); 
      int m;
      // mp = &m;
      // m = 100; // Reassignment - Memory is not allocated to heap. Causes error when trying to free().

      printf("Value of *mp: %d\n", *mp);
      printf("Value of *cp: %d\n", *cp);
      printf("Value of cp: %p\n", cp);

      printf("Size of *mp: %lu\n", sizeof(*mp)); // Value size (size of int)
      printf("Size of mp: %lu\n", sizeof(mp));   // Pointer address size
      printf("Size of *cp: %lu\n", sizeof(*cp)); // Value size (size of int)
      printf("Size of cp: %lu\n", sizeof(cp));   // Pointer address size
      
      free(mp); 
      // free(cp); 

      // ### Using realloc()
      // Re-allocating less memory than we're using
      char *str1;
      char *str2;
      str1 = (char*) malloc(16);   // Allocate 16 bytes for type char
      strcpy(str1, "123456789AB"); // 11 bytes + NUL termination character
      str2 = realloc(str1, 2);     // Re-allocate 8 bytes to str2 from str1 

      printf("Value of str1: %s  [%p]\n", str1, str1);
      printf("Value of str2: %s  [%p]\n", str2, str2);
      printf("Size of str1: %lu\n", sizeof(*str1));
      printf("Size of str2: %lu\n", sizeof(*str2));

      // Memory was not allocated. Undefined behaviour / err.
      int num;
      int *pn = (int*) malloc(sizeof(int));
      pn = &num; // Memory from 'num' was not allocated to the heap; freeing it causes undefined behaviour 
      // free(pn); 

      // Memory successfully freed may still contain its address value. This is a dangling pointer. 
      // Trying to do anything to it might cause undefined behaviour.
      int dnum = 100;
      int *dp = (int*) malloc(sizeof(int)); 
      *dp = dnum;
      printf("Value of *dp: %d\n", *dp);
      printf("Address of dp: %p\n", dp);
      free(dp);
      printf("Value of *dp: %d\n", *dp);
      printf("Address of dp: %p\n", dp);
      dp = &dnum;
      printf("Value of *dp: %d\n", *dp);
      printf("Address of dp: %p\n", dp);


}
