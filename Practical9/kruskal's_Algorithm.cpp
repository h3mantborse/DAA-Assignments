#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100005;

struct edge {
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<edge> edges;
int parent[MAXN], rnk[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (rnk[px] < rnk[py]) parent[px] = py;
    else if (rnk[px] > rnk[py]) parent[py] = px;
    else {
        parent[py] = px;
        rnk[px]++;
    }
}

int kruskal(int n) {
    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
        return a.w < b.w;
    });
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rnk[i] = 0;
    }
    int res = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (auto& e : edges) {
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            res += e.w;
            pq.push(make_pair(min(e.u, e.v), max(e.u, e.v)));
        }
    }
    while(!pq.empty()) {
        auto e = pq.top();
        pq.pop();
        cout << e.first << " " << e.second << endl;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
    }
    int res = kruskal(n);
    cout << "Total weight of MST: " << res << endl;
    return 0;
}
