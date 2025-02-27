#include <bits/stdc++.h>
using namespace std;

int par[100005];
int group_size[100005];

void dsu_init(int n)
{
  for (int i = 1; i <= n; i++)
  {
    par[i] = -1;
    group_size[i] = 1;
  }
}

int dsu_find(int node)
{
  if (par[node] == -1)
    return node;

  int leader = dsu_find(par[node]);
  par[node] = leader;
  return leader;
}

void dsu_union(int node1, int node2)
{
  int leader1 = dsu_find(node1);
  int leader2 = dsu_find(node2);
  if (group_size[leader1] > group_size[leader2])
  {
    par[leader2] = leader1;
    group_size[leader1] += group_size[leader2];
  }
  else
  {
    par[leader1] = leader2;
    group_size[leader2] += group_size[leader1];
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  dsu_init(n);

  while (m--)
  {
    int u, v;
    cin >> u >> v;
    int par_u = dsu_find(u);
    int par_v = dsu_find(v);

    if (par_u != par_v)
    {
      dsu_union(u, v);
    }
  }
  
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
      int par_1 = dsu_find(1);
      int par_i = dsu_find(i);
      if(par_1 != par_i){
        cnt++;
        dsu_union(1,i);
        ans.push_back(i);
      } 
    }
    cout << cnt << endl;
    for(auto it:ans){
      cout << "1" << " " << it << endl;
    }


  return 0;
}
