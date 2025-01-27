// because I lost the other file :|
// CH5 REVISED: POINTERS AND STRINGS
// 20250127

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() 
{
	
	char ac1[6] = "Colin";  // String literal,  Global
	char *pc1 = "Dawn";	// Pointer to char, Global
	static char *spc1 = "Hello"; // Static pointer to char, only available to this function
	static char sac1[] = "Goodbye"; // Static string literal, only available to this function 

	// Copy of a string literal thats dynamically allocated
	char *pc2 = (char*) malloc(strlen("Lake") + 1);	
	strcpy(pc2, "Lake");

	// A copy isn't created when directly assigning to a char pointer
	// 
	*(pc2) = 'T';

	printf("%s\n", pc2); // output: "Take"
	

	// This will crash after the user inputs anything
	// if no memory is allocated first to input pointer.
	// danger can still be posed since you can go beyond the allocated memory without a crash
	// ideally use a fixed size array instead
	char *input = (char*) malloc(6);
	printf(">>> ");
	scanf("%s", input); 	

	// still contiguous in memory even if beyond whats allocated in the heap
	for (int i = 0; i < strlen(input) + 1; i++) {
		printf("input[%i]: %p\n", i, &input[i]);
	}	


	// Arrays of pointers to chars, address copying
	char *names[5];
	char name[10];
	int count = 0;

	printf(">>>");
	scanf("%s", name);
	names[count] = (char*) malloc(strlen(name) + 1);
	strcpy(names[count], name);

	printf("names[%d]: %s\n", count, names[count]);
	count ++;	


	printf("END");
	return 0;
}

