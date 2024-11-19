/*// stack using array
#include <stdio.h>
int stack[7];
int n,num=0;
int top =-1;

int main(){
  printf("Enter total elements: ");
  scanf("%d",&n);

  while(num!=4){
    printf("Operation to perform on stack are:\n");
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit");
    printf("\nEnter operation to perform: ");
    scanf("%d",&num);

    switch(num){

    case 1: {

      push();
      break;
    }
    case 2: {

      pop();
      break;
    }
    case 3: {

      peek();
      break;
    }
    case 4: {

      printf("Exit");
      break;
    }
    default: {
    printf("Enter a choice between 1 to 4\n");
    }
  }
}


return 0;
}

void push(){
    int data;
  if (top==n){
    printf("Stack is full\n");
  }
  else {
        printf("Enter data:\n");
  scanf("%d",&data);
    top = top+1;
    stack[top] = data;
  }
  printf("Element is pushed\n");
}

void pop(){
  if (top==-1){
    printf("Stack is empty\n");
  }
  else {
    printf ("Element removed %d\n",stack[top]);  // first print the top then delete
    top = top-1;
  }
}

void peek(){
  if (top==-1){
    printf("Stack is empty\n");
  }
  else {
    printf("\nTop element is: %d\n",stack[top]);
  }
}


// stack using linked list

#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

int main(){
    int num=0;

  while(num!=4){
    printf("\nOperations to perform on stack are:\n");
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    printf("\nEnter operation to perform: ");
    scanf("%d",&num);

    switch(num){

    case 1: {

      push();
      break;
    }
    case 2: {

      pop();
      break;
    }
    case 3: {

      peek();
      break;
    }

    case 4: {

      display();
      break;
    }
    case 5: {

      printf("Exit");
      break;
    }

    default: {
    printf("Enter a choice between 1 to 5\n");
    }
  }
}


return 0;
}

void push(){
    int data;
  struct node *ptr = (struct node*) malloc (sizeof(struct node));
  if (ptr==NULL){
    printf("Stack is full\n");
  }
  else {
        printf ("Enter value to push: ");
        scanf("%d",&data);

        if(head==NULL){
            ptr ->data = data;
            ptr ->next = NULL;
            head = ptr;
        }
        else {
            ptr -> data = data;
            ptr ->next = head;
            head = ptr;
        }
        printf("Element pushed in the stack\n");
  }

}

void pop()
{
    int val;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        val = head->data;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Element is popped\n");

    }
}

void peek(){
    if(head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else {
       printf("\nTop element is: %d\n",head->data);
    }
}
void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}*/


/*#include<stdio.h>
#include<stdlib.h>

struct node {
  int val;
  struct node* next;
};

struct node *head;

int main(){
  int num=0;
  while (1){
  printf("enter op 1 to 5: ");
  scanf("%d",&num);

  switch(num){
case 1:{
    push();break;
  }
  case 2:{
    pop();break;
  }
  case 3:{
    peek();break;
  }
  case 4:{
    display();break;
  }
  case 5:
    return 0;
  default:{
  printf("enter 1 to 5");}
     return 0;
  }

}

return 0;}

void push(){
  int val;
  struct node *ptr = (struct node*) malloc(sizeof(struct node));

  if (ptr==NULL){
    printf("overflow");
  }
  else {
        printf("enter val");
    scanf("%d",&val);
    if (head==NULL){
        ptr ->val = val;
        ptr->next= NULL;
  head =ptr;
    }
    else {
        ptr->val=val;
        ptr->next=head;
        head=ptr;
    }
  }
}

void pop(){
  int val;
  struct node *ptr;
  if (head==NULL){
    printf("empty");
  }
  else{
    val = head->val;
    ptr  = head;
    head =head->next;
    free(ptr);
  }
}

void peek(){
  struct node *ptr;
  if (head==NULL){
    printf("empty");
  }
  else{
    printf("top: %d",head->val);
  }
}

void display(){
struct node *ptr;
ptr = head;

if(ptr==NULL){
    printf("empty");
}
else{
    while(ptr!=NULL){
        printf("stack : %d\t",ptr->val);
        ptr=ptr->next;
    }
}
}*/



// queue using array and linkedlist

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//queue using Array
typedef struct {
    int items[MAX];
    int front, rear;
} ArrayQueue;

void initArrayQueue(ArrayQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFullArrayQueue(ArrayQueue* q) {
    return q->rear == MAX - 1;
}

int isEmptyArrayQueue(ArrayQueue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueueArrayQueue(ArrayQueue* q, int value) {
    if (isFullArrayQueue(q)) {
        printf("Queue is full (Array)\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d (Array)\n", value);
}

void dequeueArrayQueue(ArrayQueue* q) {
    if (isEmptyArrayQueue(q)) {
        printf("Queue is empty (Array)\n");
        return;
    }
    printf("Dequeued %d (Array)\n", q->items[q->front]);
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

void displayArrayQueue(ArrayQueue* q) {
    if (isEmptyArrayQueue(q)) {
        printf("Queue is empty (Array)\n");
        return;
    }
    printf("Queue (Array): ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Queue using Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} LinkedListQueue;

void initLinkedListQueue(LinkedListQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmptyLinkedListQueue(LinkedListQueue* q) {
    return q->front == NULL;
}

void enqueueLinkedListQueue(LinkedListQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", value);
}

void dequeueLinkedListQueue(LinkedListQueue* q) {
    if (isEmptyLinkedListQueue(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Dequeued %d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void displayLinkedListQueue(LinkedListQueue* q) {
    if (isEmptyLinkedListQueue(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with switch case menu
int main() {
    int choice, value, queueType;
    ArrayQueue arrayQueue;
    LinkedListQueue linkedListQueue;

    initArrayQueue(&arrayQueue);
    initLinkedListQueue(&linkedListQueue);

    printf("Enter: \n1. Array\n2. Linked List\n");
    scanf("%d", &queueType);

    do {
        printf("\nOperation:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (queueType == 1) {
                    enqueueArrayQueue(&arrayQueue, value);
                } else if (queueType == 2) {
                    enqueueLinkedListQueue(&linkedListQueue, value);
                }
                break;
            case 2:
                if (queueType == 1) {
                    dequeueArrayQueue(&arrayQueue);
                } else if (queueType == 2) {
                    dequeueLinkedListQueue(&linkedListQueue);
                }
                break;
            case 3:
                if (queueType == 1) {
                    displayArrayQueue(&arrayQueue);
                } else if (queueType == 2) {
                    displayLinkedListQueue(&linkedListQueue);
                }
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid\n");
        }
    } while (choice != 4);

    return 0;
}
*/
