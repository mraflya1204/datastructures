//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNCTIONS INIT
void pushFront(int value);
void pushBack(int value);
void popFront();
void popBack();
void adx(int value);
void dex(int value);

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
        
        if(strcmp(command, "add")==0){
            int valueX, valueY; scanf("%d %d", &valueX, &valueY);
            
            for(int i = 0; i < valueY; i++){
                pushBack(valueX);
            }

            int counter = 0;
            node *tempNode = front;
            while(tempNode != NULL){
                counter++;
                tempNode = tempNode->next;
            }
            printf("%d\n", counter);
        }
        else if(strcmp(command, "del")==0){
            int valueY; scanf("%d", &valueY);

            node *tempNode = back;
            printf("%d\n", tempNode->value);

            for(int i = 0; i < valueY; i++){
                popBack();
            }
        }
        else if(strcmp(command, "adx")==0){
            int valueX; scanf("%d", &valueX);

            adx(valueX);
        }
        else if(strcmp(command, "dex")==0){
            int valueX; scanf("%d", &valueX);

            dex(valueX);
        }
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

void adx(int value){
    node *tempNode = front;
    while(tempNode != NULL){
        tempNode->value = tempNode->value + value;
        tempNode = tempNode->next;
    }
}

void dex(int value){
    node *tempNode = front;
    while(tempNode != NULL){
        tempNode->value = tempNode->value - value;
        tempNode = tempNode->next;
    }
}
