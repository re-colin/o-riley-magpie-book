#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int take_ui_free(void **mem) {
      if (*mem != NULL && mem != NULL) {
            free(*mem);
            *mem = NULL;
            printf("Memory freed successfully.\n");
            return 0;
      }
      printf("Invalid memory address.\n");
      return 1;
}

int custom_realloc(void **mem, size_t size) {
      if (realloc(*mem, size) != NULL) {
            printf("\nrealloc successful.");
            return 0;
      }
      printf("\nrealloc unsuccessful."); 
      return 1;
}

int custom_calloc(void **mem, size_t size) {
      if (calloc(20, sizeof(int)) != NULL ) {
            printf("\ncalloc successful.");
            return 0;
      }
      printf("\ncalloc unsuccessful.");
      return 1;
}

int scanf_for_realloc() {
      
     //  int ptr_size = ;
      char *ptr_loc;
      int i;

      printf("\nEnter args for realloc:");
      printf("\nPointer: ");
      scanf("%d", &i);
      printf("\nMemory size:");
      scanf("%d", &i);
    
      printf("Input value(s): %d", i);  

      return 0; 
}

int* alloc_variable_size_obj(void **ptr, int size) {
      
      int special_value = 10;
      *ptr = malloc(size);


      return *ptr;
}


int main () {
      int *i = (int*) malloc(sizeof(int));
      *i = 10;
      printf("i   VAL: %d\tADDR:  %p\n", *i, i);
      take_ui_free((void*)&i);
      printf("i  (INV. VAL)\tADDR:  %p\n", i); // Using the address-of operator still gives you its address even if its freed. The variable itself is nothing - 0x0.

      // i = realloc(i, sizeof(int) * 2); 
      int *j = realloc(i, 50); 
      *j = 20;

      printf("\nSize of realloc'd memory: %lu  %lu  %lu", sizeof(&j), sizeof(j), sizeof(*j));
      printf("\nValues of realloc'd memory: %p  %p  %d", &j, j, *j);

      custom_realloc((void*)&i, 20);
      custom_calloc((void*)20, 5);
//      scanf_for_realloc();

      int *ptr = NULL;

      alloc_variable_size_obj((void*)&ptr, 10);

      return 0;
}
