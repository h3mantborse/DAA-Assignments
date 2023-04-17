#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    vector<pair<int, int>>* adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int primMST(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int Graph::primMST(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    pq.push(make_pair(0, start));
    dist[start] = 0;
    int res = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        res += dist[u];
        for(auto& it: adj[u]) {
            int v = it.first;
            int weight = it.second;
            if(!visited[v] && dist[v] > weight) {
                dist[v] = weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return res;
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    int start;
    cin >> start;
    int res = g.primMST(start);
    cout << res << endl;
    return 0;
}
