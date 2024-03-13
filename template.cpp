//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024
//HEADERS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NODE INIT
struct node{
    int value;
    node *next;
    node *prev;
}*front, *back;

//FUNCTIONS INIT
void pushFront(int value);
void pushBack(int value);
void popFront();
void popBack();

//MAIN FUNCTION
int main(){

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
