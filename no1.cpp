#include <stdio.h>
#include <stdlib.h>

struct Data1 {
    int angkapertama;
    Data1* next1;
}	*head1 = NULL, *tail1 = NULL;

struct Data2 {
    int angkakedua;
    Data2* next;
} *head = NULL, *tail = NULL;

struct Data1* initialize(int angka) {
    struct Data1* newData = (Data1*)malloc(sizeof(Data1));

    newData->angkapertama = angka;
    newData->next1 = NULL;

    return newData;
}

struct Data2* createNode(int angka) {
    struct Data2* newNode = (Data2*)malloc(sizeof(Data2));

    newNode->angkakedua = angka;
    newNode->next = NULL;

    return newNode;
}

void pushHead(int angka) {
    struct Data2* newNode = createNode(angka);

    if (!head ) head = tail = newNode;
    else {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int angka) {
    struct Data2* newNode = createNode(angka);

    if (!head) head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(int angka) {
    struct Data2* newNode = createNode(angka);
    if (!head) head = tail = newNode;
    else if (newNode->angkakedua < head->angkakedua) pushHead(angka);
    else if (newNode->angkakedua > tail->angkakedua ) pushTail(angka);
    else {
        struct Data2 *current = head;
        while (current) {
            if (newNode->angkakedua < current->next->angkakedua) break;
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
	}
}

void pushTail1(int angka) {
    struct Data1* newData = initialize(angka);
    if (!head1) head1 = tail1 = newData;
    else {
        tail1->next1 = newData;
        tail1 = newData;
    }
}

void print() {
    struct Data2* current = head;
    while (current) {
        printf("%d ", current->angkakedua);
        current = current->next;
    }
    puts("");
}

void print2() {
    struct Data1* current = head1;
    while (current) {
        printf("%d ", current->angkapertama);
        current = current->next1;
    }
    puts("");
}

void popHead() {
    if (!head1) return;
    else {
        struct Data1* current = head1;
        head1 = head1->next1;
        free(current);
        current = NULL;
    }
}

void merge() {
    struct Data1* current = head1;
    while(current) {
        pushMid(current->angkapertama);
        current=  current->next1;
        popHead();
    }
}

int main()
{
    pushTail1(10);
    pushTail1(100);
    pushTail1(1000);
    print2();
    pushTail(9);
    pushTail(99);
    pushTail(999);
    print();
    merge();
    print();

    return 0;
}
