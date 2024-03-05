//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024

//HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NODE STRUCT INIT
struct node{
    int value;
    node *next;
    node *prev;
}*front, *back;

//FUNCTIONS INIT
void pushBack(int value);
void pushFront(int value);
void popBack();
void popFront();

//MAIN FUNCTION
int main(){

}

//FUNCTIONS
void pushFront(int value){
    node newNode = new node;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(FRONT == NULL){
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
    node newNode = new node;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(BACK == NULL){
        front = newNode;
        back = newNode;
    }
    else{
        newNode->prev = back;
        back->next = newNode;
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
    if(back == NULL){
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
