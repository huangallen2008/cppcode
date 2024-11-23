#include <cassert>
#include <cstdio>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;

int n;
vector<int> graph[MAX_N];
int vis[MAX_N];

// dp[i][j in 0/1/2] = max number of nodes chosen by B in the subtree
// rooted in i if:
//      j = 0  ->  i is chosen by A
//      j = 1  ->  i is not chosen by A, there is no path from i to a node chosen by A
//      j = 2  ->  i is not chosen by A, there is a path from i to a node chosen by A
int dp[MAX_N][3];

inline void checkMax(int &a, int b) {
    a = max(a, b);
}

void dfs(int node) {
    vis[node] = true;
    
    dp[node][2] = -1;
    
    vector<int> sons;
    for (auto it : graph[node])
        if (!vis[it]) {
            sons.push_back(it);
            dfs(it);
        }
        
    // Compute dp[node][0]
    for (auto it : sons) {
        dp[node][0] += max(dp[it][1], dp[it][2] + 1);
    }
    
    // Compute dp[i][2]: exactly one of the sons needs to be in dp[son][0] or dp[son][2],
    // the rest should be in dp[son][1]
    int sonSum = 0;
    for (auto it : sons) {
        sonSum += dp[it][1];
    }
    for (auto it : sons) {
        checkMax(dp[node][2], sonSum - dp[it][1] + max(dp[it][0], dp[it][2]));
    }
    
    // Compute dp[i][1]:
    // Case 1: all sons are in dp[son][1].
    for (auto it : sons) {
        dp[node][1] += dp[it][1];
    }
    // Case 2: at least two sons are in dp[son][0] or dp[son][2].
    if (sons.size() < 2) return;
    sonSum = 0;
    for (auto it : sons) {
        sonSum += max(max(dp[it][0], dp[it][1]), dp[it][2]);
    }
    
    vector<int> lostScore;
    for (auto it : sons) {
        lostScore.push_back(max(max(dp[it][0], dp[it][1]), dp[it][2]) - max(dp[it][0], dp[it][2]));
    }
    sort(lostScore.begin(), lostScore.end());
    checkMax(dp[node][1], 1 + sonSum - lostScore[0] - lostScore[1]);
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        
        cin >> a >> b;
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        assert(a != b);
        --a; --b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++) cout<<dp[i][0]<<' ';cout<<'\n';
    for(int i=0;i<n;i++) cout<<dp[i][1]<<' ';cout<<'\n';
    for(int i=0;i<n;i++) cout<<dp[i][2]<<' ';cout<<'\n';
    dfs(0);
    cout << max(max(dp[0][0], dp[0][1]), dp[0][2]) << "\n";
}
