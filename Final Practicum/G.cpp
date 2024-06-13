#include <iostream>
#include <vector>
#include <queue>
#define LONG_MAX 2147483647
using namespace std;

void insertEdge(vector<pair<long, long>> adjList[], long v1, long v2, long weight);
void dijkstra(vector<pair<long, long>> adjList[], long V, vector<long>& result, long start);

int main() {
        long N; cin >> N;
        long V; cin >> V;
        long T; cin >> T;
        vector<pair<long, long>> adjList[N + 1]; 

        for (int i = 0; i < V; i++) {
            long a, b;
            cin >> a >> b;
            insertEdge(adjList, a, b, 1);
        }
        
        for(int i = 0 ; i < T; i++){
            int start; cin >> start;
            int destination; cin >> destination;
            vector<long> result(N + 1, LONG_MAX);
            dijkstra(adjList, N + 1, result, start); 
            cout << result[destination] << "\n";
        }
        
        

    return 0;
}


void insertEdge(vector<pair<long, long>> adjList[], long v1, long v2, long weight) {
    adjList[v1].push_back(make_pair(v2, weight));
    adjList[v2].push_back(make_pair(v1, weight));
}


void dijkstra(vector<pair<long, long>> adjList[], long V, vector<long>& result, long start){
    vector<bool> visited(V, false);
    priority_queue <pair<long, long>, 
                    vector <pair<long, long>>, 
                    greater <pair<long, long>> > pq;
    
    pq.push(make_pair(0, start));
    result[start] = 0;

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        if(visited[temp.second]) continue;

        visited[temp.second] = true;

        for(auto vertex: adjList[temp.second]){
            long nextVertex = vertex.first;
            long weight = vertex.second;

            if(temp.first + weight < result[nextVertex]) {
                result[nextVertex] = temp.first + weight;
                pq.push(make_pair(result[nextVertex], nextVertex));
            }
        }
    }
}