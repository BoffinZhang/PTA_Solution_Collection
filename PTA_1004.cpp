// Counting Leaves
// BFS寻找每层的叶子节点

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 100+10;
int M,N,temp;
vector<int> son[MAXN];
int ans[MAXN],level[MAXN];
int total_level = 0;
void init(){
    memset(ans,0,sizeof(ans));
    level[1]=1;
    total_level = 1;
}
bool input(){
    cin>>N>>M;
    if(N==0) return false;
    int ID,num_of_son,sonID;
    for(int i=0;i<M;i++){
        cin>>ID>>num_of_son;
        for(int i=0;i<num_of_son;i++){
            cin>>temp;
            son[ID].push_back(temp);
        }
    }
    return true;
}
void solve(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(son[cur].size()==0){
            ans[level[cur]]++;
            continue;
        }
        for(int i=0;i<son[cur].size();i++){
            int next = son[cur][i];
            level[next]=level[cur]+1;
            total_level = max(level[next],total_level);
            q.push(next);
        }
    }
    for(int i=1;i<=total_level;i++){
        if(i!=1)cout<<" ";
        cout<<ans[i];
    }
}

int main(){
    init();
    input();
    solve();
    return 0;
}