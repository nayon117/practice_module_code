#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj_list;
vector<bool> vis;
vector<long long> dis;
vector<int> parent;
int n, e;

void dijkstra(int src)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto [par_dis, par_node] = pq.top();
        pq.pop();

        if (par_dis > dis[par_node]) continue;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            long long child_dis = child.second;

            if (dis[par_node] + child_dis < dis[child_node])
            {
                dis[child_node] = dis[par_node] + child_dis;
                parent[child_node] = par_node;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    adj_list.resize(n + 1);
    vis.assign(n + 1, false);
    parent.assign(n + 1, -1);
    dis.assign(n + 1, LLONG_MAX);

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(1);

    if (dis[n] == LLONG_MAX)
    {
        cout << "-1\n";
        return 0;
    }

    int node = n;
    vector<int> path;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";

    return 0;
}
