#include <stdio.h>
#include <stdlib.h>

// NODE INIT
struct node {
    int start;
    int end;
    struct node *next;
    struct node *prev;
} *front, *back;

// FUNCTIONS INIT
void pushBack(int start, int end);
void popFront();

// MAIN FUNCTION
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        pushBack(start, end);
    }

    struct node *tempNode = front;
    while (tempNode != NULL) {
        if (tempNode->next != NULL && tempNode->end >= tempNode->next->start) {
            if (tempNode->end > tempNode->next->end) {
                tempNode->end = tempNode->end;
            } 
            else {
                tempNode->end = tempNode->next->end;
            }

            struct node *tempTempNode = tempNode->next;
            tempNode->next = tempNode->next->next;
            if (tempNode->next != NULL)
                tempNode->next->prev = tempNode;
            free(tempTempNode);
        } else {
            tempNode = tempNode->next; // Move to the next node
        }
    }
    
    struct node *tempNode2 = front;
    while (tempNode2 != NULL) {
        printf("%d %d\n", tempNode2->start, tempNode2->end);
        tempNode2 = tempNode2->next;
    }

    return 0;
}

// FUNCTIONS
void pushBack(int start, int end) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->start = start;
    newNode->end = end;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        back = newNode;
        newNode->prev = NULL;
    } else {
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
    }
}

void popFront() {
    if (front == NULL) {
        return;
    } else {
        struct node *tempNode = front;
        if (front == back) {
            front = NULL;
            back = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }
        free(tempNode);
    }
}
