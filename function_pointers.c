#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I got a redeclaration error earlier due to declaring the typedef incorrectly.
typedef int (*fptr)(int); // Function takes in integer and returns an integer
typedef int (*fptrOp)(int, int); // + Function pointer declaration
typedef int (*FPop)(int, int);
FPop operations[128] = {NULL};

// without typedef
// int (*operations[128])(int, int) = {NULL};

int square(int num) {
      return num * num;
}

int add(int num1, int num2) {
      return num1 + num2;
}

int sub(int num1, int num2) {
      return num1 - num2;
}

// Address 'fptrOp' points to the arg operation and invokes it. This adds flexibility in function calling.
int compute(fptrOp operation, int num1, int num2) { 
      return operation(num1, num2);
}

fptrOp select(char opcode) {
      switch(opcode) {
            case '+': return add;
            case '-': return sub;
 
      }
      return 0; // this throws an error if you return anything besides 0.
}

int evaluate(char opcode, int num1, int num2) {
      fptrOp operation = select(opcode);
      return operation(num1, num2);
}

void initializeOperationsArray() {
      operations['+'] = add;
      operations['-'] = sub;
}

int evaluateArray(char opcode, int num1, int num2) {
      fptrOp operation;
      // Line 53 throws a warning. It goes away if you cast opcode as an int.
      operation = operations[(int)opcode];
      return operation(num1, num2);
}
      
int main () 
{
      int n = 10;
      //fptr = square;

      fptr fp1; // Instance of 'fptr' function
      fp1 = square;      
      printf("%d squared is %d", n, fp1(n));

      printf("%d\n", compute(add, 12, 237));
      printf("%d\n", compute(sub, 12, 237));
     
      printf("%d\n", evaluate('+', 5, 6));
      printf("%d\n", evaluate('-', 5, 6));

      initializeOperationsArray();
      printf("evaluateArray(): %d\n", evaluateArray('+', 5, 6));
      printf("evaluateArray(): %d\n", evaluateArray('-', 5, 6));

      // Comparison of function pointers also works. 
      if (fp1 == square) {
            printf("fp1 is of the function square.");
      }

      return 0;
}
