// 变种Dijkstra求解最短路条数和最大节点和
#include<iostream>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;

const int MAXN = 500 + 10;
const int INF = 1e9;

int G[MAXN][MAXN];
int N,M,c1,c2;
int value[MAXN],dis[MAXN],vis[MAXN];
int num[MAXN];    // 消防队数量
int road[MAXN];   // 最短路的条数
void init(){
    fill(dis,dis+MAXN,INF);
    memset(value,0,sizeof(value));
    memset(G,-1,sizeof(G));
    memset(vis,0,sizeof(vis));
}

void input(){
    cin>>N>>M>>c1>>c2;
    for(int i=0;i<N;i++){
        cin>>value[i];
    }
    for(int i=0;i<M;i++){
        int s,t,v;
        cin>>s>>t>>v;
        G[s][t] = v;
        G[t][s] = v;
    }
}

void dijkstra(){
    dis[c1] = 0;
    num[c1] = value[c1];
    vis[c1] = 1;
    road[c1] = 1; 
    // 刷新周围点的距离
    for(int i=0;i<N;i++){
        if(G[c1][i]>=0){
            dis[i]=min(dis[i],dis[c1]+G[c1][i]);
            num[i] = num[c1]+value[i];
            road[i] = road[i]+road[c1];
        }
    }

    int min_dis = INF,next_node;
    for(int i=0;i<N;i++){
        // 选出距离最小的节点
        min_dis = INF;
        next_node = -1;
        for(int i=0;i<N;i++){
            if(!vis[i]&&dis[i]<min_dis){
                min_dis = dis[i];
                next_node = i;
            }
        }
        // 更新这个点的访问情况
        if(next_node==-1) break;
        vis[next_node] = 1;
        // 用这个点更新相邻点的最短距离
        for(int i=0;i<N;i++){
            if(G[next_node][i]>=0&&!vis[i]){
                if(dis[i]>dis[next_node]+G[next_node][i]){
                    dis[i] = dis[next_node]+G[next_node][i];
                    num[i] = num[next_node]+value[i];
                    road[i] = road[next_node];
                }
                else if(dis[i]==dis[next_node]+G[next_node][i]){
                    num[i] = max(num[i],num[next_node]+value[i]);
                    road[i] = road[i]+road[next_node];
                }
            }
        }
    }
    cout<<road[c2]<<" "<<num[c2]<<endl;
}

int main(){
    init();
    input();
    dijkstra();
    return 0;
}