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
    int numberOfCases; scanf("%d", &numberOfCases);

    for(int i = 0; i < numberOfCases; i++){
        char command[100]; scanf("%s", command);
        int value; scanf("%d", &value);

        if(strcmp(command, "push_front")==0){
            pushFront(value);
        }
        else if(strcmp(command, "push_back")==0){
            pushBack(value);
        }
        else if(strcmp(command, "pop_front")==0){
            popFront();
        }
        else if(strcmp(command, "pop_back")==0){
            popBack();
        }
    }

    node *tempNode = front;
    while(tempNode!= NULL){
        printf("%d\n", tempNode->value);
        tempNode = tempNode->next;
    }
}

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