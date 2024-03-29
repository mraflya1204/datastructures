//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024

#include <stdlib.h>
#include <stdio.h>

struct PQueueNode {
    int data;
    PQueueNode *next;
};

// Default priority: minimum
struct PriorityQueue
{
    PQueueNode *_top;
    unsigned _size;

    void init()
    {
        _top = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_top == NULL);
    }

    void push(int value)
    {
        PQueueNode *temp = _top;
        PQueueNode *newNode = \
            (PQueueNode*) malloc (sizeof(PQueueNode));
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (value >= _top->data) {
            newNode->next = _top;
            _top = newNode;
        }
        else {
            while ( temp->next != NULL && 
                    temp->next->data > value)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            PQueueNode *temp = _top;
            _top = _top->next;
            free(temp);
        }
    }

    int top()
    {
        if (!isEmpty()) return _top->data;
        else exit(-1);
    }

    unsigned size() {
        return _size;
    }
};

int main()
{
    PriorityQueue myQueue;
    myQueue.init();

    int N; scanf("%d", &N);
    int number = N;
    int C; scanf("%d", &C);
    int R; scanf("%d", &R);
    int transferred = 0;
    int treated = 0;

    for(int i = 0; i < N; i++){
        int M; scanf("%d", &M);
        myQueue.push(M);
    }

    for(int i = 0; i < number; i++){
        if(R==0 || C==0){
            transferred++;
            myQueue.pop();
        }
        else if(myQueue.top() <= R){
            R = R - myQueue.top();
            treated++;
            C--;
            myQueue.pop();
        }
        else{
            transferred++;
            myQueue.pop();
        }
    }
    
    if(treated == 0){
        printf("All %d patients are transferred\n", transferred);
    }
    else{
        printf("Patients treated: %d\n", treated);
        printf("Patients transferred: %d\n", transferred);
    }
    return 0;
}