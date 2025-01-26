#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This lets you pass in the address of the pointer without needing to cast
#define safeFree(p) saferFree((void**)&(p))


// CHAPTER 3
// POINTERS AND FUNCTIONS
// 1) Stack & Heap structure 
//    > (V)-- Swapping values (Copy vs Location)
//    > Modifying by value vs. By pointer (passing by pointer)
// 2) Passing a Pointer to a Constant
// 3) Returning a pointer from a function 
// 4) Function pointers - Pointers TO functions
     // void (*foo)();
     // Returns type void. 
     // Second pair of parenthesis is where parameters go.

int* fptr();      // Returns a pointer to an integer.
int  (*fptr1)();  // Pointer to a function.
int* (*fptr2)();

int (*fp)(int);

// If you want to reduce visual clutter, you can declare (*funcptr)(int); as a typedef.
typedef int (*addptr)(int);

int square(int num) {
      return num*num;
}

int add_two_nums(int num1, int num2) {
      return num1 + num2;
}

addptr add;
// add = add_two_nums;

void passAddressOfConstants(const int* num1, int* num2) 
{
      *num2 = *num1;
}


int* allocateArray(int size, int value) // int* -> Return type (pointer to an int) 
{
      int* arr = (int*) malloc(size * sizeof(int));  // Return object - space for newly allocated array. Size 5 * 45 values.  
      for (int i = 0; i < size; i++) { // Assignment of values  
            arr[i] = value;
      }
      return arr; // arr is returned from the heap space.
}

// ## Returning pointers to local data
// Problematic function if we want to preserve 'arr' for later use. The compiler throws a warning for this. 
// A solution to this could be to make `arr` a static variable; it will be allocated outside of the stack space and preserved after the function exits, but it can cause problems later. 
int* localAllocateArray(int size, int value) {
      int arr[size];
      for (int i = 0; i < size; i++) { 
            arr[i] = value;
            printf("%d\n", arr[i]);
      }
      return arr;
}

void allocatePointerToArray(int **arr, int size, int value) { 
      *arr = (int*) malloc(sizeof(size * sizeof(int)));
      if (*arr != NULL) {
            for (int i = 0; i < size; i++) {
                  *(*arr) = value;
            }
      }
}


// Assigning NULL to a recently freed pointer is good practice, but it doesn't do this by default.
// This custom free() requires we pass in a pointer to the pointer that contains the data to be freed / it's address.
void saferFree(void **pp) {
      if (pp != NULL && *pp != NULL) {
           printf("Attempting to free %p.\n", pp);
           free(*pp); 
           *pp = NULL;

           printf("EXIT FUNCTION\n.");
      }
}


int main() 
{ 
      const int n = 10;
      int m = 5;

      passAddressOfConstants(&n, &m); 
      printf("%d\n", n);
      printf("%d\n", m);

      int* vector = allocateArray(5, 15);
      printf("Value of *vector: %d\n", *vector); // 15 -- i.e, pointer to the first value

      for (int i = 0; i < 5; i++) { 
            printf("%d\n", vector[i]); // 5 integers of value 15
      }      

      free(vector); // Dangling pointer.
      vector = NULL; 
      printf("Address of vector: %p\n", vector); // NULL - address 0x0 

      int* localVector = localAllocateArray(5, 25); 
      for (int i = 0; i < 5; i++) {
            printf("Values of localVector: %d\n", localVector[i]);
      } 

      // saferFree() Testing
      int *pn;
      pn = (int*) malloc(sizeof(int));
      *pn = 5;
      int *ppn;
      ppn = pn; 

      printf("Value of *ppn: %d\n", *ppn);
      printf("Address of ppn: %p\n", ppn);
      printf("Value of *pn: %d\n", *pn);
      printf("Address of pn: %p\n", pn);
      
      printf("\n");
      //saferFree((void*)pn);
      safeFree(pn);
      printf("\n");
      
      printf("Address of pn is %p.\n", pn); 
     //  printf("Value of *pn is %d.\n", *pn);     // If memory is successfully freed the safe way, this line will terminate the program 

      // Function pointers (Pointers to functions)
      // Assigning square to fp using '&' is redundant in this context
      int ns = 5;
      fp = square;
      printf("%d squared is %d.\n", ns, fp(ns));

      


      return 0;
}
