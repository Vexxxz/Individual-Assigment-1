#include <stdio.h>
#include <malloc.h>

struct Data {
    int age;
    Data* next;
}	*head = NULL , *tail = NULL;

struct Data *initialize(int age) {
    Data *newNode = (Data*)malloc(sizeof(Data));

    newNode -> age = age;
    newNode -> next = NULL;

    return newNode; 
};

void pushHead(int age) {
    struct Data* newNode = initialize(age);

    if (!head ) head = tail = newNode;
    else {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int age) {
    struct Data* newNode = initialize(age);

    if (!head) head = tail = newNode;
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void pushMid(int age) {
    struct Data* newNode = initialize(age);
    
	if (!head) head = tail = newNode;
    else if (newNode->age <= head->age) pushHead(age);
    else if (newNode->age >= tail->age ) pushTail(age);
    else {
        struct Data *current = head;

		while (current) {
			if (newNode->age < current->next->age) break;
			current = current->next;
		}
		newNode -> next = current -> next;
		current -> next = newNode;
	}   
}
void popHead() {
    if (!head) return;
	else {
		struct Data* current = head;
		head = head -> next;
		free(current);
		current = NULL;
	}
}
void popTail() {
    if (!head) return;
    else if (head == tail) {
        free(head);
        head = tail = NULL;
    }
    else {
        struct Data* current = head;
        while (current)
        {
            if (current -> next = tail) break;
            current = current -> next;
        }
        free(tail);
        tail = current;
        tail -> next = NULL;
    }
}

void popMid(int age)
{
    if (!head) return;
    else if (age == head -> age ) popHead();
    else if (age == tail -> age) popTail();
    else 
    {
        struct Data* current = head;
        while (current)
        {
           if (current -> next -> age == age) break;
            current = current->next;
        } 
        if (!current->next) return;
        struct Data* temp = current -> next;
        current -> next = temp -> next;
        free(temp);
        temp = NULL;
    }
}


void removeData()
{
    struct Data* current = head;
    while(current != NULL) {
        if (current->age == current->next->age) {
            if (!current->next) return;
            struct Data* temp = current->next;
            current -> next = temp->next;
            free(temp);
            temp = NULL;
        }
        current = current -> next;
    }
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
    for (int i = 10 ; i < 20; i++)
	pushTail(i);
	pushMid(13);
	pushMid(15);
	pushMid(12);
    
	print();
	removeData();
	print();

    return 0;
}
