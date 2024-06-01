#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

void insertEdge(vector<int> adjList[], int v1, int v2);
void DFS(vector<int> adjList[], int V, int start, vector<int>& traversalOrder);

int main(){
    int V;
    scanf("%d", &V);
    vector<int> adjList[V];
    char listOfNames[V][100];

    for(int i = 0; i < V; i++){
        scanf(" %s", listOfNames[i]);
    }

    while(1){
        char cmd[100];
        scanf(" %s", cmd);

        if(strcmp(cmd, "ADD") == 0){
            char firstName[100]; scanf(" %s", firstName);
            char secondName[100]; scanf(" %s", secondName);
            int a = -1;
            int b = -1;

            for(int j = 0; j < V; j++){
                if(strcmp(firstName, listOfNames[j])==0){
                    a = j;
                    break;
                }
            }
            for(int k = 0; k < V; k++){
                if(strcmp(secondName, listOfNames[k])==0){
                    b = k;
                    break;
                }
            }
            if (a != -1 && b != -1)
                insertEdge(adjList, a, b);
        }
        else if(strcmp(cmd, "CHECK")==0){
            int circleCheck = -1;
            char firstName[100]; scanf(" %s", firstName);
            char secondName[100]; scanf(" %s", secondName);
            int a = -1;
            int b = -1;

            for(int j = 0; j < V; j++){
                if(strcmp(firstName, listOfNames[j])==0){
                    a = j;
                    break;
                }
            }
            for(int k = 0; k < V; k++){
                if(strcmp(secondName, listOfNames[k])==0){
                    b = k;
                    break;
                }
            }

            if (a != -1 && b != -1) {
                circleCheck = 0;
                vector<int> traversalOrder;
                DFS(adjList, V, a, traversalOrder);

                for(auto i = traversalOrder.begin(); i < traversalOrder.end(); ++i){
                    if(*i == b){
                        circleCheck = 1;
                        break;
                    }
                }

                if(circleCheck == 1){
                    printf("Healthy circle!\n");
                }
                else{
                    printf("Toxic circle, be friends please!\n");
                }
            }
        }
        else if(strcmp(cmd, "EXIT")==0){
            break;
        }
    }
    return 0;
}

void insertEdge(vector<int> adjList[], int v1, int v2){
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
}


void DFS(vector<int> adjList[], int V, int start, vector<int>& traversalOrder) {
    vector<bool> visited(V, false);
    stack<int> stack;

    visited[start] = true;
    stack.push(start);
    
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        traversalOrder.push_back(current);

        for (int i = 0; i < adjList[current].size(); ++i) {
            int neighbor = adjList[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}
