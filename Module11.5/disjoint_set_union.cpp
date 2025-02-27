//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            if (s == "UNION") {
                int z, x;
                cin >> x >> z;
                unionSet(a, x, z);
            } else {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends

int group_size[105];

/*Complete the functions below*/
int find(int par[], int x) {
     if (par[x] != x) {
        par[x] = find(par, par[x]);  
    }
    return par[x]; 
        
}

void unionSet(int par[], int x, int z) {
     int leader1 = find(par, x);
    int leader2 = find(par, z);
    
    if (leader1 != leader2) {
        if (group_size[leader1] > group_size[leader2]) {
            par[leader2] = leader1;  
            group_size[leader1] += group_size[leader2];  
        } else {
            par[leader1] = leader2;  
            group_size[leader2] += group_size[leader1];  
        }
    }
}
