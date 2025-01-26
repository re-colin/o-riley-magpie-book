#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CHAPTER 4: POINTERS & ARRAYS



// Display array contents using bracket notation
void display_array_a_i(int arr[], int len) {
      for (int i = 0; i < len; i++) {
            printf("%d\n", arr[i]);
      }
}

// Display 2D array using bracket notation
// The number of columns always needs to be specified because the compiler needs to know the number of elements in each row. If it doesn't have this information, it can't evaluate an expression like arr[0][3]. 
void display_array_2D_a(int arr[][5], int rows) {
      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 5; j++) {
                  printf("%d", arr[i][j]);
            }
            
      }
}

// Display 2D array using pointer notation 
// Here, we can't use array subscripts like arr[i][j]. 
// Single array subscripts will be interpreted as an offset within the array.
// We can't use more than one because the compiler doesn't know the dimension size.
// printf("%d\n", (arr+i)[j]);

void display_array_2D_p_unknownsize(int *arr, int rows, int cols) {
      printf("\n");
      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                 //  printf("arr[%d][%d]: %d\n", i, j, *arr[i][j]);
            
                 // In brackets, the address of a value is incremented before its dereferenced. 
                 printf("%d\n", *(arr + (i*cols) + j)  );
            }
      }
}

int main() 
{
      int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} }; // Two rows with 3 elements. 
      
      for (int i = 0; i < 2; i++) {
            printf("matrix[%d]: %p  sizeof(matrix[%d]): %lu\n", i, &matrix[i], i, sizeof(matrix[i]));
            // Output is 12 because each row is 3 ints. 3 * 4 = 12. 
      }


      int matrix_len = sizeof(matrix) / sizeof(int); 
      printf("Length of matrix: %d\n", matrix_len);   // length, i.e how many elements are in matrix
      
      int arr3d[3][2][4] = {  // 3D array with 3 elements inside of it, each holding two items - each with 4 ints contained in them.
          { {1, 2, 3, 4}, {5, 6, 7, 8} },
          { {9, 10, 11, 12}, {13, 14, 15, 16} },
          { {17, 18, 19, 20}, {21, 22, 23, 24} }
      }; 

      int arr3d_len = sizeof(arr3d) / sizeof(int);
      printf("Length of arr3d: %d\n\n", arr3d_len);  // 24  
      
      // A pointer to an array does not point to the array itself, rather the first element.
      int vector[5] = {1, 2, 3, 4, 5};
      int vector_len = sizeof(vector) / sizeof(int);
      int *pv = vector;
     
      printf("%p\n", vector);
      printf("%p\n", &vector[0]); // these represent basically the same thing.
      printf("%p\n", &vector); // this prints a pointer to the *entire* array. 
      

      for (int i = 0; i < 5; i++) {
            printf("%i) pv address: %p\n", i, pv);
            printf("%i) pv value  : %d\n", i, *pv);
            pv++;
      }

      pv += 1; 
      printf("\nAddress of pv: %p\n", pv);
      printf("Value of pv: %d\n", *pv);

      // Scalar addition operation
      // NOTE: See operator presedence
      pv = vector;
      int val = 3; 
      for (int i=0; i<5; i++) {
            printf("%d\n", *pv++ *= val);
      }

      // Allocating an array from the heap & assigning values  
      int *pvh = (int*) malloc(sizeof(int));
      for (int i = 0; i<5; i++) {
            pvh[i] = i+1;
            printf("%d\n", pvh[i]);
      }

      // NOTE: Check stdin getline function 
      
      int list[5] = {1, 2, 3, 4, 5};
      int *listp = list;
      int list_len = sizeof(list) / sizeof(int);
      // display_array_a_i(list, list_len);
      printf("\nPointer notation:");
//      display_array_p_i(listp, list_len);    

      // Allocating memory for an array of pointers
      int* arr[5];
      printf("\n");
      for (int i = 0; i < 5; i++) {
           //arr[i] = malloc(sizeof(int));
           //*arr[i] = i;
          *(arr + i) = (int*)malloc(sizeof(int)); // Levels of indirection also work.
          **(arr + i) = i; 
      }
      // display_array_p_i(*arr, 5);
      // Display array *properly*.
      printf("displaying contents of arr: ");
      for (int i = 0; i < 5; i++) {
            printf("%d\n", *arr[i]);
      }

      int matrixb[2][5] =  {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10}
      }; 

      // definition (*pmatrixb)[] declares a pointer to an array. Do not mix this up with an array of pointers.
      // *This* is an array of pointers:  *arr[5];
      int (*pmatrixb)[5] = matrixb;

      for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {
                  printf("matrixb[%d][%d] Address: %p Value: %d\n",  i, j, &matrixb[i][j], matrixb[i][j]);
            }
      
      }

      display_array_2D_a(matrixb, 2);
      display_array_2D_p_unknownsize(&pmatrixb[0][0], 2, 5);



      return 0;
}
