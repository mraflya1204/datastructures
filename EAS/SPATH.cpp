#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <climits>
using namespace std;

void insertEdge(vector<pair<int, int>> adjList[], int v1, int v2, int weight);
void dijkstra(vector<pair<int, int>> adjList[], int V, vector<int>& result, vector<int>& pred, int start);
void printPath(const vector<int>& pred, int start, int end, const vector<int>& mustVisit);

bool isMustVisit(int node, const vector<int>& mustVisit);

int main() {
    int N; cin >> N;
    int V; cin >> V;
    vector<pair<int, int>> adjList[V];

    for (int i = 0; i < V; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        insertEdge(adjList, a, b, weight);
    }

    int startPoint; cin >> startPoint;
    int endPoint; cin >> endPoint;
    
    int M; cin  >> M;
    vector<int> mustVisit(M);
    for(int i = 0; i < M; i++){
        cin >> mustVisit[i];
    }
    
    int totalWeight = 0;
    
    if(M==0){
        vector<int> result; 
        vector<int> pred(V, -1); 
        cout << startPoint;
        dijkstra(adjList, V, result, pred, startPoint);
        printPath(pred, startPoint, endPoint, mustVisit);
        totalWeight+=result[endPoint];
        
    }
    else{
        for(int i = 0; i < M+1; i++){
            vector<int> result; 
            vector<int> pred(V, -1); 
            
            if(i == 0){
                cout << startPoint;
            }
            if(i == M){
                dijkstra(adjList, V, result, pred, startPoint);
                printPath(pred, startPoint, endPoint, mustVisit);
                totalWeight+=result[endPoint];
            }
            else{
                dijkstra(adjList, V, result, pred, startPoint);
                printPath(pred, startPoint, mustVisit[i], mustVisit);
                totalWeight+=result[mustVisit[i]];
            }
            startPoint = mustVisit[i];
        }
    }
    
    cout << "\n" << totalWeight;
    

    return 0;
}

void insertEdge(vector<pair<int, int>> adjList[], int v1, int v2, int weight) {
    adjList[v1].push_back(make_pair(v2, weight));
    adjList[v2].push_back(make_pair(v1, weight));
}

void dijkstra(vector<pair<int, int>> adjList[], int V, vector<int>& result, vector<int>& pred, int start) {
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    result = vector<int>(V, INT_MAX);

    pq.push(make_pair(0, start));
    result[start] = 0;

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();

        int current = temp.second;
        if (visited[current]) continue;

        visited[current] = true;

        for (auto vertex : adjList[current]) {
            int nextVertex = vertex.first;
            int weight = vertex.second;

            if (result[current] + weight < result[nextVertex]) {
                result[nextVertex] = result[current] + weight;
                pq.push(make_pair(result[nextVertex], nextVertex));
                pred[nextVertex] = current; 
            }
        }
    }
}

void printPath(const vector<int>& pred, int start, int end, const vector<int>& mustVisit) {
    if (end == start) {
        return;
    } 
    else {
        printPath(pred, start, pred[end], mustVisit);
        if (isMustVisit(end, mustVisit)) {
            cout << "-(" << end << ")";
        } else {
            cout << "-" << end;
        }
    }
}

bool isMustVisit(int node, const vector<int>& mustVisit) {
    for (int mustVisitNode : mustVisit) {
        if (mustVisitNode == node) {
            return true;
        }
    }
    return false;
}
