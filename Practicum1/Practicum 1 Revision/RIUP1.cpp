#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;
    
    int N; scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        char cmd[100]; scanf("%s", cmd);
        int M; scanf("%d", &M);
        
        if(strcmp(cmd, "add")==0){
            stack_push(&myStack, M);
        }
        else if(strcmp(cmd, "dbl")==0){
            int value = stack_top(&myStack);
            stack_push(&myStack, value*2);
        }
        else if(strcmp(cmd, "six")==0){
            int value = stack_top(&myStack);
            stack_push(&myStack, value+6);
        }
        else if(strcmp(cmd, "del")==0){
            stack_pop(&myStack);
        }
        else if(strcmp(cmd, "total")==0){
            int total = 0;
            
            StackNode *tempNode = myStack._top;
            while(tempNode!=NULL){
                total += tempNode->data;
                tempNode = tempNode->next;
            }
            
            printf("%d\n", total);

        }
    }
    return 0;
}