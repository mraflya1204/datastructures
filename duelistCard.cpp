//DUELIST CARD
//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NODE INIT
struct node{
    int value;
    int max;
    int min;
    node *next;
    node *prev;
}*front, *back;

//FUNCTIONS INIT
void pushFront(int value);
void popFront();
void top();
void max();
void min();

//MAIN FUNCTION 
int main(){
    int N; scanf("%d", &N);

    for(int i = 0; i < N; i++){
        char command[100]; scanf("%s", command);

        if(strcmp(command, "push")==0){
            int value; scanf("%d", &value);
            pushFront(value);
        }
        else if(strcmp(command, "pop")==0){
            popFront();
        }
        else if(strcmp(command, "top")==0){
            top();
        }
        else if(strcmp(command, "min")==0){
            min();
        }
        else if(strcmp(command, "max")==0){
            max();
        }
    }
    return 0;
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
        newNode->max = newNode->value;
        newNode->min = newNode->value;
    }
    else{
        newNode->next = front;
        front->prev = newNode;
        front = newNode;

        newNode->max = newNode->next->max;
        newNode->min = newNode->next->min;

        if(newNode->value > newNode->max){
            newNode->max = newNode->value;
        }
        else if(newNode->value < newNode->min){
            newNode->min = newNode->value;
        }
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

void top(){
    node *newNode = front;
    printf("%d\n", newNode->value);
}

void min(){
    node *newNode = front;
    printf("%d\n", newNode->min);
}

void max(){
    node *newNode = front;
    printf("%d\n", newNode->max);
}
