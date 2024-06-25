#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vertexCount = -1;

long find_parent(vector<long> &parent, long v) {
    if (v == parent[v]) return v;
    return find_parent(parent, parent[v]);
}

void union_set(vector<long> &parent, long vertex1, long vertex2) {
    parent[find_parent(parent, vertex2)] = find_parent(parent, vertex1);
}

void kruskal(vector<pair<long, pair<long, long>>> &result, vector<pair<long, pair<long, long>>> &edgeList) {
    vector<long> parent(vertexCount);
    for (int i = 0; i < vertexCount; i++) parent[i] = i;

    sort(edgeList.begin(), edgeList.end());

    for (auto edge : edgeList) {
        long vertex1 = edge.second.first;
        long vertex2 = edge.second.second;
        if (find_parent(parent, vertex1) != find_parent(parent, vertex2)) {
            result.push_back(edge);
            union_set(parent, vertex1, vertex2);
            if (result.size() == vertexCount - 1) return;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    long totalDistanceInitial = 0;


    vector<pair<long, pair<long, long>>> edgeList;
    for (int i = 0; i < E; ++i) {
        long v1, v2, w;
        cin >> v1 >> v2 >> w;
        edgeList.push_back({w, {v1-1, v2-1}});
        totalDistanceInitial+= w;
    }
    

    vertexCount = V;

    vector<pair<long, pair<long, long>>> result;
    kruskal(result, edgeList);

    long totalDistance = 0;
    for (auto edge : result) {
        totalDistance += edge.first;
    }

    cout << totalDistanceInitial - totalDistance << endl;

    return 0;
}
