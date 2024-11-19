 // linked list insertion and deletion

#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL, *temp;

struct node* createNode(int data){
  struct node *newNode = (struct node*)malloc (sizeof(struct node));
  newNode -> data = data;
  newNode -> next = NULL;
  return newNode;
// check for empty list

}

void insFront (struct node** head, int num){
  struct node* newNode = createNode(num);
  newNode -> next =*head;
  *head = newNode;
  printf("Node inserted at the front.\n");
}

void insEnd (struct node** head, int num){
  struct Node* newNode = createNode(num);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    }
    printf("Node inserted at the end.\n");
}

void insPos(struct node** head, int num,int pos){
  struct node* newNode = createNode(num);
    if (pos== 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }
    else {
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", pos);
    }
}

void delFront(struct node** head){
   if (*head == NULL) {
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp); //this will delete the content of node
    printf("Node deleted from front.\n");
}

void delEnd(struct node** head){
  if (*head == NULL){
    return;
  }
  struct node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
    }
    else {
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    }
    printf("Node deleted from end.\n");
}

void delPos(struct node** head,int pos){
  if (*head == NULL) {
        return;
    }

    struct node* temp = *head;

    if (pos == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    else{

    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid Position\n");
        return;
    }
    else{
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node deleted from position %d.\n", pos);
      }
    }
}

void display(struct node* head){
  if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    printf("\n\nLinked list: \n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
   int ch=0,num,pos;

  while(ch!=7){
    printf("\nOperations to perform on linked list are:\n");
    printf("\n1.Insertion at front\n2.Insertion at end\n3.Insertion at specific position\n4.Deletion from front\n5.Deletion from end\n6.Deletion from specific position\n7.Exit\n");
    printf("\nEnter the operation to perform: ");
    scanf("%d",&ch);

    switch(ch){

    case 1: {
      printf("Enter data to insert at front: ");
      scanf("%d", &num);
      insFront(&head,num);
      display(head);
      break;
    }
    case 2: {
      printf("Enter data to insert at end: ");
      scanf("%d", &num);
      insEnd(&head,num);
      display(head);
      break;
    }
    case 3: {
      printf("Enter data to insert: ");
      scanf("%d", &num);
      printf("Enter position to insert at: ");
      scanf("%d", &pos);
      insPos(&head,num,pos);
      display(head);
      break;
    }

    case 4: {

      delFront(&head);
      display(head);
      break;
    }

    case 5: {

      delEnd(&head);
      display(head);
      break;
    }

    case 6: {
      printf("Enter the position to delete from: ");
      scanf("%d", &pos);
      delPos(&head,pos);
      display(head);
      break;
    }
    case 7: {

      printf("Exit");
      break;
    }

    default: {
    printf("Enter a choice between 1 to 7\n");
    }
  }
}

return 0;
}
