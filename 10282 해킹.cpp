//
// Created by msi on 2022-02-06.
//
#include <bits/stdc++.h>
using namespace std;

#define MAX 20000
#define INF 99999999

vector<int> dijkstra(int start, int V, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int nCost = cost + adj[cur][i].second;
            if (nCost < dist[next]) {
                dist[next] = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int v, e, k;
        cin >> v >> e >> k;
        vector<pair<int, int>> adj[MAX];

        for (int i = 0; i < e; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            // adj[from - 1].push_back(make_pair(to - 1, cost));
            adj[to - 1].push_back(make_pair(from - 1, cost));
        }

        vector<int> dist = dijkstra(k - 1, v, adj);
        int time = 0;
        int number = 0;
        for (int i = 0; i < v; i++) {
            if (dist[i] != INF) {
                time = max(time, dist[i]);
                number++;
            }
        }
        cout << number << " " << time << "\n";
    }
    return 0;
}