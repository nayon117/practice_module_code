#include <bits/stdc++.h>
using namespace std;

int par[1005];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}


void dsu_union(int x, int y) {
    int leader1 = find(x);
    int leader2 = find(y);
    if (leader1 != leader2) {
        par[leader1] = leader2;
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    vector<pair<int, int>> roads;  
    vector<pair<int, int>> extra_roads; 
    
    int cnt = 0;  
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        if (find(u) != find(v)) {
            dsu_union(u, v);
            roads.push_back({u, v});
        } else {
            extra_roads.push_back({u, v});
            cnt++;
        }
    }

    cout << cnt << endl;

    int last_connected = -1;
    int j = 0;
    
   
    for (int i = 1; i <= n; i++) {
        if (par[i] == i) {
            if (last_connected != -1) {
                cout << extra_roads[j].first << " " << extra_roads[j].second << " " << last_connected << " " << i << endl;
                j++;
            }
            last_connected = i;
        }
    }

    return 0;
}
