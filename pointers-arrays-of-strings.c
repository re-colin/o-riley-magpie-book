#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
      // POINTERS TO ARRAYS OF STRINGS
      char str[16] = "Hi";
      char *sptr = str;
      int len = strlen(str);
      char *temp[16] = {""};
      char tmp[5][5] = {}; 
      int j = 0;

      printf("%s\n", sptr); 
      printf("%c\n", *sptr);
      
      for (int i = 0; i < 5; i++) {
            tmp[j][i] = *sptr;
            sptr++;
            printf("%c\n", tmp[j][i]);
      }     

      printf("%s\n", tmp[j]);
      
      temp[0] = "Colin";
      temp[1] = "Rhys";
      temp[2] = "Lake"; // legal
                       
      temp[0][0] = 'Y'; // can't assign to string literal 

      printf("%s\n", temp[j]);
      j++;
      printf("%s\n", temp[j]);
      
      printf("%c\n", temp[j][0]);



      return 0;
}
