#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <cmath>
#define int long long
using namespace std;
const int N = 1e5+7;
int n, m, a, b;
vector<int> adj[N], path[N];
bool ready[N];
 
signed main() {
    //input, fill
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i = 2; i <= n; i++){
        ready[i] = false;
    }
 
    //bfs
    queue<int> q;
    q.push(1);
    path[1].push_back(1);
    ready[1] = true;
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j: adj[i]){
            if(!ready[j]){
                ready[j] = true;
                path[j] = path[i];
                path[j].emplace_back(j);
                q.push(j);
            }
        }
    }
 
    //consider
    if(!ready[n]) cout << "IMPOSSIBLE" << '\n';
    else{
        cout << path[n].size() << '\n';
        cout << 1;
        for(int k: path[n]) if(k != 1) cout << ' ' << k;
        cout << '\n';
    }
 
    return 0;
}