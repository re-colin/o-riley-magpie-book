#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIST_LEN 10

typedef struct _Person {
        char *name;
        int age;
        int height;

} newPerson;

void initializeList(newPerson *list[LIST_LEN]) {
        for (int i = 0; i < LIST_LEN; i++) {
                (list)[i] = NULL;
        }
}

void printList(newPerson *list[LIST_LEN]) {
        for (int i = 0; i < LIST_LEN; i++) {
                printf("list[%d]  %p\n", i, list[i]);
        }
        printf("\n");
}

int main() {

        newPerson *ptrPerson = malloc(sizeof(newPerson));

        ptrPerson->name = malloc(sizeof("Colin")+1);
        (*ptrPerson).name = "Colin";

        ptrPerson->age = 17;
        ptrPerson->height = 5;


        printf("\nnewPerson->name:   %p  %s\n", ptrPerson->name, ptrPerson->name);
        printf("newPerson->age:    %p  %d\n", &ptrPerson->age, ptrPerson->age);
        printf("newPerson->height: %p  %d\n\n", &ptrPerson->height, ptrPerson->height);

        // Size of structure. 16 bytes by default.
        printf("size of ptrPerson: %lu\n", sizeof(*ptrPerson));

        // "Pool of Persons"
        // array of pointers to a struct instance.
        newPerson *list[LIST_LEN];

        initializeList(list);
        printList(list);

        newPerson *ptrPerson2 = malloc(sizeof(newPerson));
        ptrPerson2->name = "Lake";
        ptrPerson2->age = 17;

        list[0] = ptrPerson2;
        printList(list);

        printf("list[0]->name: %s\n", list[0]->name);
        printf("list[0]->age: %d\n", list[0]->age);
        printf("list[0]->height: %d\n", list[0]->height);


        return 0;
}
