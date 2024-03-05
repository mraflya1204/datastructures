//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNCTIONS INIT
void pushFront(int value);
void pushBack(int value);
void popFront();
void popBack();

//NODE INIT
struct node{
    int value;
    node *next;
    node *prev;
}*front, *back;

//MAIN FUNCTION
int main(){
    int N; scanf("%d", &N);
    int counter = N;

    for(int i = 0; i < N; i++){
        int value; scanf("%d", &value);
        pushFront(value);
    }
    
    node *startNode = front;
    
    for(int i = 0; i < N; i++){
        node *tempNode = startNode;
        for(int j = i+1; j < N; j++){
            if(startNode->value >= tempNode->next->value){
                counter++;
                tempNode = tempNode->next;
            }
            else{
                break;
            }
        }
        startNode = startNode->next;
        tempNode = startNode;
    }
    
    printf("%d", counter);
    
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
