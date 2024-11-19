// queue using array
#include<stdio.h>
#define MAX 10

int rear = -1;
int front = 0;

int enQueue(int a[],int val){
//if queue is empty
if (front==0 && rear==MAX-1){
    printf ("\nQueue is full");
  }

else {
    if (rear==-1){
    a[++rear] = val;
  }
  else a[++rear] = val;
  printf("\nElement inserted at the rear");
 }
}

int deQueue (int a[],int val){
  if(rear==-1){
    printf("\nQueue is empty");
  }

  else {
    printf("\nElement %d deleted from front",a[front]);
    front++;
  }
  if (front>rear){
    front =0;
    rear=-1;
  }
}

int display(int a[]){
  if(rear==-1){
    printf("\nQueue is empty");
  }

  else {
    for(int i = front; i<=rear; i++){
        printf("\nQueue elements are: %d--",a[i]);
    }
  }
}

int main(){
  int a[MAX];
  int num;
  int val;
  printf("\nOperations to perform on queue using array are:\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Exit\n");
  printf("\nEnter choice: ");
  scanf("%d",&num);

  while(1){

  switch(num){

    case 1:
    printf("\nEnter data to insert: ");
    scanf("%d",&val);
    enQueue(a,val);
    break;

    case 2:
    printf("\nEnter data to delete: ");
    scanf("%d",&val);
    deQueue(a,val);
    break;

    case 3:
    display(a);
    break;

    case 4:
    printf("Exit");
    break;

    default:
        printf("\nInvalid choice");
  }
}
  return 0;

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
