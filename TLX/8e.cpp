//Made by Muhammad Rafly Abdillah @DataStructuresIUP2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N; scanf("%d", &N);
    int arr[N];
    int counter = 0;

    for(int i = 0; i < N; i++){
        scanf("%d\n", &arr[i]);
    }

    for(int i = 0; i < N-1; i++){
        if(arr[i] >= arr[i+1]){
            counter += arr[i];
        }
        else counter += arr[i+1];
    }
    printf("%d\n", counter);
}
