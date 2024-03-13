//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NODE INIT
struct node{
    long long int value;
    node *next;
    node *prev;
}*front, *back;

//FUNCTIONS INIT
void pushFront(int value);
void pushBack(int value);
void popFront();
void popBack();
int size(node *front);
bool contains(long long int value);

//MAIN FUNCTION
int main(){
    int N; scanf("%d", &N);

    for(int i = 0; i < N; i++){
        long long int M; scanf("%lld", &M);

        if(contains(M) != 1){
            pushBack(M);
        }
    }

    int listSize = size(front);
    printf("%d", listSize);
}

//FUNCTIONS
void pushFront(int value){
    node *newNode = new node();

    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(front == NULL){
        front = newNode;
        back = newNode;
    }
    else{
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    return;
}

void pushBack(int value){
    node *newNode = new node();

    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(back == NULL){
        front = newNode;
        back = newNode;
    }
    else{
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
    }
    return;
}

void popFront(){
    if(front == NULL){
        return;
    }
    else if(front == back){
        front = NULL;
        back = NULL;
    }
    else{
        node *tempNode = front;
        front = front->next;
        front->prev = NULL;
        free(tempNode);
    }
    return;
}

void popBack(){
    if(front == NULL){
        return;
    }
    else if(front == back){
        front = NULL;
        back = NULL;
    }
    else{
        node *tempNode = back;
        back = back->prev;
        back->next = NULL;
        free(tempNode);
    }
    return;
}

int size(node *front){
    node *temp = front;
    int value = 0;

    while(temp != NULL){
        value++;
        temp = temp->next;
    }
    return value;
}

bool contains(long long int value){
    node *temp = front;
    while(temp != NULL){
        if(temp->value == value){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
