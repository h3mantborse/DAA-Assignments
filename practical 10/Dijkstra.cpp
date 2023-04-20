#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // Pair of node and distance

void dijkstra(vector<vector<pii>>& graph, int start, vector<int>& distances) {
    int n = graph.size();
    distances.resize(n, numeric_limits<int>::max()); // Initialize distances to infinity
    distances[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min heap for nodes to visit
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second; // Node with smallest distance
        pq.pop();

        for (pii neighbor : graph[u]) {
            int v = neighbor.first; // Neighbor node
            int weight = neighbor.second; // Distance between u and v

            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}
