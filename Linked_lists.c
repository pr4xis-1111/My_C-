#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *pushfront(Node *top);
void printlist(Node *top);
void freelist(Node *top);
Node *popFront(Node *head);
Node *pushBack(Node *rear, int value);
Node *find(Node *head, int value);
Node *deleteValue(Node *head, int value);
Node *reverse(Node *head);

int main(void){
    int length;
    Node *tail, *head = NULL;
    scanf("%d", &length);
    for (int i = 0; i < length; i++){
        head = pushfront(head);
        if (head->next == NULL) tail = head;
    }
    head = reverse(head);
    printlist(head);
    /* Search Algorithm
    Node *x = (find(head, 50));
    if (x != NULL) printf("%d\n",x->value);
    else printf("Not found\n");
    */
    freelist(head);
}


void printlist(Node *top){
    while (top != NULL){
        printf("%d\n", top->value);
        top = top->next;
    }
}

void freelist(Node *top){
    while (top != NULL){
        Node *x = top;
        top = top->next;
        free(x);
    }
}

Node *pushfront(Node *top){
    Node *front = malloc(sizeof *front);
    if (front == NULL) return top;
    int linkval = 0;
    printf("Enter pushfront value:");
    scanf("%d", &linkval);
    front->next = top;
    front->value = linkval;
    return front;
}

Node *popFront(Node *top){
    if (top == NULL) return NULL;
    Node *x = top;
    top = top->next;
    free(x);
    return top;
}

Node *pushBack(Node *rear, int value){
    if (rear){
    Node *back = malloc(sizeof *back);
    rear->next = back;
    back->next = NULL;
    back->value = value;
    return back;
    }
    return rear;
}

Node *find(Node *head, int number){
    while (head != NULL){
        if (head->value == number){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

Node *deleteValue(Node *top, int number){
    Node *current, *head = top;
    if (top == NULL) return NULL;
    while (top != NULL && top->value == number) top = head = popFront(head);
    while (top != NULL){
        if (top->next == NULL) return head;
        if ((top->next)->value == number){
            current = (top->next);
            top->next = current->next;
            free(current);
        }
        else top = top->next;
    }
    return head;
}

Node *reverse(Node *head){
    if (head == NULL) return head;
    Node *previous = head, *current = head->next, *nextptr;
    if (current != NULL) nextptr = head->next->next;
    while (previous != NULL && current != NULL ) {
        current->next = previous;
        previous = current;
        if (nextptr == NULL) break;
        current = nextptr;
        nextptr = nextptr->next;
    }
    head->next = NULL;
    return previous;
}



