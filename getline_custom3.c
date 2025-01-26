#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SEE: CUSTOM BUFFERS / USER INPUT (**DYNAMIC) ALLOCATION


void custom_realloc(char **ptr, int size) {
     if (realloc(ptr, 10) != NULL) {
            // int *np = NULL;
            *ptr = realloc(*ptr, size);     
            if (*ptr != NULL) {
                  printf("Custom realloc() successful.\n");
            } 
     } 
     printf("Custom realloc() unsuccessful.\n"); 
}

// Allocating user input - `fgets()` version. 
// Re-allocate memory previously allocated for an input string. 
void *get_user_string() {
      const short int max_size = 10;
      char *buf = malloc(sizeof(char) * max_size);
      char input[max_size];
      char *new_buf = NULL;
      int input_len = 0;

      if (buf == NULL) {
            printf("\nmalloc() for buf unsuccessful.");
            return NULL;
      }
      
      *buf = input[0];

      printf("\nEnter string: "); 
      fgets(input, max_size, stdin);

      input_len = strlen(input); 

      int i = 0;
      printf("\nInput string: "); 
      while (i < input_len) {
            printf("%c  %d\n", input[i], input[i]);
            i++;
      }

      // This re-allocates less space for our string if its length is <9. Excluding '\0' 
      if (input_len < max_size - 1) {
            new_buf = realloc(buf, sizeof(char) * input_len);
            *new_buf = input[0];
      } else {
            printf("Input string is >=9, skipping realloc.\n");
      }
      
      if (new_buf != NULL) {
            printf("\nrealloc() successful!\n");
            free(buf);
            buf = NULL;
            printf("\nOld buffer freed.");
      } else if (new_buf == NULL) { 
            printf("new_buf reallocation unsuccessful. Operation either invalid or unnecessary.\n");
            return NULL;
      }

      printf("\nEXTRA INFORMATION -- FOR LEARNING PURPOSES:\n");
      // printf("Addr|Val - buf: %p  %d %c\n", &buf, *buf, *buf);
      printf("Addr|Val - new_buf: %p  %d %c\n", &new_buf, *new_buf, *new_buf);

      printf("\nEXITING...");
      return new_buf;
}

// For each set of characters entered, allocate space for it on the heap.
// Call realloc() in a new buffer to make more space if the input string exceeds a set maximum length.
void *getline_custom() {
      size_t max_len = 10;     
      const int new_increment = 10;
      char *cbuffer = malloc(max_len);
      char *new_buffer = NULL;
      size_t length = 0;
      int character = 0;
      char *cposition = cbuffer;

      while (1) 
      {
            character = fgetc(stdin);  
            if (character == '\n') { break; } // Breaks loop on enter key from the user
            
            if (++length > max_len) {
                  printf("\nInput exceeded by character ");
                  printf("'%c' ", character);
                  new_buffer = realloc(cbuffer, max_len += new_increment);

                  if (new_buffer != NULL) {
                        printf("\nrealloc() of %lu bytes successful.", max_len);
                  } else {
                        printf("\nrealloc() operation unsuccessful.");
                        free(cbuffer);
                        break;
                  }
            
            }
      }
      printf("\nReturning newly allocated buffer...\n");
      return new_buffer; 
}

int main () {
      //getline_custom();

      get_user_string(); 
      return 0;
}
