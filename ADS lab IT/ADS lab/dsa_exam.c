
// queue using array and linkedlist

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int data[MAX];
int front = -1, rear = -1;

void initial() {
    front = -1;
    rear = -1;
}

int isfull() {
return rear == MAX - 1;
}

int isempty() {
    return front == -1 || front > rear;
}

void enqarr(int value) {
if (isfull()) {
        printf("Queue is full\n");
        return;
    }
if (front == -1) front = 0;
rear++;
    data[rear] = value;
    printf("element added\n");
}

void deqarr() {
if (isempty()) {
    printf("Queue empty\n");
    return;
    }
    printf("Dequeued %d\n", data[front]);
    front++;
if (front > rear) {
        front = rear = -1;
    }
}

void displayarr() {
if (isempty()) {
    printf("Queue empty\n");
    return;
    }
printf("Queue: ");
for (int i = front; i <= rear; i++) {
  printf("%d ", data[i]);
    }
printf("\n");
}

struct Node {
    int data;
    struct Node* next;
};

struct llq {
    struct Node* front;
    struct Node* rear;
};

void initial_llq(struct llq* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isempty_llq(struct llq* q) {
    return q->front == NULL;
}

void enqueuellq(struct llq* q, int value) {
struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
newnode->data = value;
newnode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
printf("Enqueued %d\n", value);
}

void dequeuellq(struct llq* q) {
if (isempty_llq(q)) {
        printf("Queue is empty\n");
        return;
    }
struct Node* temp = q->front;
    printf("Dequeued %d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
free(temp);
}

void displayllq(struct llq* q) {
if (isempty_llq(q)) {
        printf("Queue empty\n");
        return;
    }
struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
printf("\n");
}

int main() {
int c, val, queue;
    struct llq llq;

initial();
initial_llq(&llq);

printf("Enter: 1.Array 2.Linked List\n");
scanf("%d", &queue);

do {
printf("Operation:\n");
printf("1.Enqueue 2.Dequeue 3.Display\n");
  scanf("%d", &c);
switch (c) {
case 1:
    printf("Enter data: ");
    scanf("%d", &val);
    if (queue == 1) {
        enqarr(val);
    } else if (queue == 2) {
    enqueuellq(&llq, val);
                }
break;
    case 2:
    if (queue == 1) {
    deqarr();
} else if (queue == 2) {
    dequeuellq(&llq);
                }
break;
  case 3:
    if (queue == 1) {
    displayarr();
} else if (queue == 2) {
displayllq(&llq);
                }
break;
default: printf("invalid\n");
}
} while (c !=3);
    return 0;
}

