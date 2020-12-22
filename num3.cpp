#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int idx = 0;

struct Data
{
    int age;
    Data* next;
}	*head = NULL , *tail = NULL;

struct Data *createNode(int age) {
    Data *newNode = (Data*)malloc(sizeof(Data));

    newNode->age = age;
    newNode->next = NULL;

    return newNode; 
}

void pushTail(int age) {
    struct Data* newNode = createNode(age);

    if (!head) head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
    idx++;
}

void printMiddle() {
    int mid = ceil(idx/2);
    struct Data* current = head;
    while (mid--) current = current->next;
    printf("%d\n", current->age);
}

void print() {
    struct Data* current = head;
    while (current) {
        printf("%d ", current->age);
        current = current->next;
    }
    puts("");
}

int main()
{
	for (int i = 1; i < 10; i++)
	pushTail(i);
	print();
	printMiddle();

	return 0;
}
