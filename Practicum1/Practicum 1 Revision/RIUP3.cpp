/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
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
    
    int howmany; scanf("%d", &howmany);
    
    for(int a = 0; a < howmany; a++)
    {    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    int M; scanf("%d", &M);
    
    for(int i = 0; i < M; i++){
        char input; scanf(" %c", &input);
        
        stack_push(&myStack, input);
    }
    
    int stackSize = stack_size(&myStack);
    StackNode *tempNode = myStack._top;
    int output[stackSize];
    int j = 0;
    for(int i = 0; i < stackSize; i++){
        if(tempNode->data != '0'){
            int value = tempNode->data - '0' + ('a' - 1);
            output[j] = value;
            tempNode = tempNode->next;
            j++;
        }
        else if(tempNode->data == '0'){
            int total = 0;
            
            total += (tempNode->next->data - '0') * 1;
            total += (tempNode->next->next->data - '0') * 10;
            total += 96;
            
            output[j]=total;
            j++;
            
            tempNode = tempNode->next->next->next;
            i += 2;
            
        }
        else{
            tempNode = tempNode->next;
            j++;
        }
    }
    for(int i = j-1; i >= 0; i--){
        printf("%c", output[i]);
    }
    printf("\n");
}
    
    return 0;
}