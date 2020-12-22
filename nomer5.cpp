#include<stdio.h>
#include<stdlib.h>

struct Node { 
	int angka; 
	struct Node* next; 
} *head, *tail;

Node *initialize ( int angka){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->angka = angka;
	newNode->next=NULL;
	return newNode;
}

void printDariBelakang(int angka) {
	int len = 0;
	struct Node *temp = head;
	int i = 0;
	while(temp != NULL){
		temp = temp->next;
		len++;
	}
	if(angka>len){
		return;
	}
	temp = head;
	for (i = 1; i < len - angka + 1; i++) 
		temp = temp->next;
		
	printf("%d", temp->angka);
}

void print() {
	Node *current = head;
	while(current){
		printf("%d ", current->angka);
		current = current->next;
	}
	printf("\n");
}

void pushHead(int angka) {
	Node *temp = initialize(angka);
	
	if(head == NULL) head =  temp;
	else {
		Node *current = head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = temp;
	}
}

void disposeMemory(){
	Node *temp;
	while(head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main()
{
	pushHead(5);
	pushHead(6);
	pushHead(7);
	print();

	printDariBelakang(1);
	disposeMemory();

	return 0;
}
