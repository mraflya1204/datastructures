#include <stdio.h>
#include <stdlib.h>

typedef struct BusNode {
    int capacity;
    struct BusNode* next;
} BusNode;

typedef struct {
    BusNode* front;
    BusNode* rear;
    int size;
} BusQueue;

void initQueue(BusQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void enqueue(BusQueue* queue, int capacity) {
    BusNode* newNode = (BusNode*)malloc(sizeof(BusNode));
    newNode->capacity = capacity;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(BusQueue* queue) {
    int capacity = queue->front->capacity;
    BusNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return capacity;
}

void freeQueue(BusQueue* queue) {
    while (queue->front != NULL) {
        BusNode* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    queue->rear = NULL;
    queue->size = 0;
}

int main() {
    int N, K;
    scanf("%d", &N);
    
    BusQueue* queues = (BusQueue*)malloc(N * sizeof(BusQueue));
    for (int i = 0; i < N; ++i) {
        int M;
        scanf("%d", &M);
        initQueue(&queues[i]);
        for (int j = 0; j < M; ++j) {
            int capacity;
            scanf("%d", &capacity);
            enqueue(&queues[i], capacity);
        }
    }
    
    scanf("%d", &K);
    
    int sum = 0;
    int busesNeeded = K;
    
    while (busesNeeded > 0) {
        int maxCapacity = 0;
        int selectedQueue = -1;
        for (int i = 0; i < N; ++i) {
            if (queues[i].size > 0 && queues[i].front->capacity > maxCapacity) {
                maxCapacity = queues[i].front->capacity;
                selectedQueue = i;
            }
        }
        if (maxCapacity == 0 || selectedQueue == -1) {
            break;
        }
        sum += dequeue(&queues[selectedQueue]);
        busesNeeded--;
    }
 
    printf("%d\n", sum);
    
    for (int i = 0; i < N; ++i) {
        freeQueue(&queues[i]);
    }
    free(queues);
    
    return 0;
}
