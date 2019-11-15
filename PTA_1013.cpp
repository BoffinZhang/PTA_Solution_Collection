// 1013 Battle Over Cities
// 强联通分量数-1 逐个DFS
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2000 + 10;

vector<int> G[MAXN];
bool vis[MAXN];
int N, M, K;
int care[MAXN];
void init() { memset(vis, 0, sizeof(vis)); }

void dfs(int t, int c) {
    int len = G[t].size();
    for (int i = 0; i < len; i++) {
        if (!vis[G[t][i]] && G[t][i] != c) {
            vis[G[t][i]] = 1;
            dfs(G[t][i], c);
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    for (int i = 0; i < K; i++) {
        cin >> care[i];
    }
    for (int i = 0; i < K; i++) {
        init();
        int res = 0;
        for (int j = 1; j <= N; j++) {
            if (j == care[i]) continue;
            if (!vis[j]) {
                vis[j] = 1;
                dfs(j, care[i]);
                res++;
            }
        }
        cout<<res-1<<endl;
    }
    return 0;
}