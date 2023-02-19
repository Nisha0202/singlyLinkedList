#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

struct node *createNodeList(int n);  // function-to-create-the-list
void displayList(struct node *head); // functionto-display-the-list
struct node *addNodeAtStart(struct node *head,
                            int d); // functionto-add-a-node-in-beginning
struct node *
addNodeAtanyPosition(struct node *head,
                     int p); // functionto-add-a-node-in-any-position
struct node *
deleteFromLast(struct node *head); // functionto-delete-a-node-from-last
struct node *
deleteAtStart(struct node *head); // functionto-delete-a-node-in-beginning
struct node *
deleteNodeAtanyPosition(struct node *head,
                        int p); // functionto-delete-a-node-in-any-position
struct node *revese(struct node *head); // functionto-reverse-list
struct node *
removeDuplicates(struct node *head); // functionto-remove-duplicate-nodes

int main() {
  int choice;
  struct node *head;
  int num, newdata, position;

  while (0 < 1) {

    printf("press 1 to creat a list \n");
    printf("press 2 add a node at beginning \n");
    printf("press 3 add a node to a particular position \n");
    printf("press 4 to delete last node \n");
    printf("press 5 to delete node at beginning \n");
    printf("press 6 to delete node at any position \n");
    printf("press 7 to reverse the list \n");
    printf("press 8 to remove duplicates from the list \n");
    printf("press 0 to EXIST");
    printf("            Choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf(" Input the number of nodes : ");
      scanf("%d", &num);
      head = createNodeList(num);
      break;

    case 2:
      printf(" Input the node you want to enter : ");
      scanf("%d", &newdata);
      head = addNodeAtStart(head, newdata);
      break;

    case 3:
      printf(" Input the position you want to enter data : ");
      scanf("%d", &position);
      head = addNodeAtanyPosition(head, position);
      break;

    case 4:
      head = deleteFromLast(head);
      break;

    case 5:
      head = deleteAtStart(head);
      break;
    case 6:
      printf(" Input the position you want to delete data : ");
      scanf("%d", &position);
      head = deleteNodeAtanyPosition(head, position);
      break;

    case 7:
      head = revese(head);
      break;
    case 8:
      head = removeDuplicates(head);
      break;
    }
    if (choice == 0) {
      printf("       programme stoped");
      exit(0);
    }
  }
  return 0;
}

struct node *createNodeList(int n) {
  struct node *head, *tmp, *tmp1;

  int i = 0;
  head = (struct node *)malloc(sizeof(struct node));

  if (head ==
      NULL) // check whether the head is NULL and if so no memory available
  {
    printf(" Memory not available.");
  } else {
    int input;
    // reads data for the node
    printf(" Input data for node 1 : ");
    scanf("%d", &input);
    head->data = input;
    head->link = NULL; // links  to NULL
    tmp = head;
    i++;
    //  n nodes and adding to linked list
    for (i = 1; i < n; i++) {
      tmp1 = (struct node *)malloc(sizeof(struct node));
      if (tmp1 == NULL) {
        printf(" NO Memory .");
        break;
      } else {
        printf(" Input data for node %d : ", i + 1);
        scanf(" %d", &input);

        tmp1->data = input; // keeping the data
        tmp1->link = NULL;  // links the address tmp1 of t with NULL

        tmp->link = tmp1; // links previous node linked to the newnode
        tmp = tmp->link;
      }
    }
    displayList(head);
    return head;
  }
}

void displayList(struct node *head) {
  printf("\nlinked list : ");

  struct node *tmp;
  if (head != NULL) {
    tmp = head;
    while (tmp != NULL) {
      printf("%d ", tmp->data); // prints the data of current node
      tmp = tmp->link;          // advances the position of current node
    }
  }
  printf("\n...........\n");
}

struct node *addNodeAtStart(struct node *head, int d) {

  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = d;
  newnode->link = head;
  head = newnode;
  displayList(head);
  return head;
}

struct node *addNodeAtanyPosition(struct node *head, int p) {
  int data;
  printf(" Input the node you want to enter : ");
  scanf("%d", &data);
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->link = NULL;

  struct node *tmp;
  if (head != NULL) {
    tmp = head;
    for (int i = 1; i < p - 1; i++) {
      tmp = tmp->link;
    }
    newnode->link = tmp->link;
    tmp->link = newnode;
  }

  displayList(head);
  return head;
}

struct node *deleteFromLast(struct node *head) {
  struct node *tmp;
  struct node *tmp1;
  tmp = head;
  if (head != NULL) {
    while (tmp->link != NULL) {
      tmp1 = tmp;
      tmp = tmp->link;
    }
    if (tmp->link == NULL) {
      tmp1->link = NULL;
      free(tmp);
    }
    displayList(head);
    return head;
  }
}

struct node *deleteAtStart(struct node *head) {
  struct node *tmp;
  tmp = head;
  head = tmp->link;
  free(tmp);
  displayList(head);
  return head;
}

struct node *deleteNodeAtanyPosition(struct node *head, int p) {
  int data;
  struct node *prevn, *current;
  if (head != NULL) {
    prevn = head;
    for (int i = 1; i < p - 1; i++) {
      prevn = prevn->link;
    }
  }
  current = prevn->link;
  prevn->link = current->link;
  free(current);
  displayList(head);
  return head;
}

struct node *revese(struct node *head) {
  struct node *prev = NULL;
  struct node *current = head;
  struct node *next;
  while (current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }
  head = prev;
  displayList(head);
  return head;
}

struct node *removeDuplicates(struct node *head) {
  struct node *current = head, *index = NULL, *temp = NULL;
  while (current != NULL) {
    temp = current;
    index = current->link;

    while (index !=
           NULL) { // If current node's data is equal to index node's data
      if (current->data == index->data) {
        // index node is pointing to the node which is duplicate of current node
        // Skips the duplicate nodepointing to next node
        temp->link = index->link;
      } else {
        // Temp will point previous node of index.
        temp = index;
      }
      index = index->link;
    }
    current = current->link;
  }
  displayList(head);
  return head;
}
