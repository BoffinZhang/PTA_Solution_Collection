// 1007 Maximum Subsequence Sum
// 最大子序列和 简单DP

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXK = 10000+10;

int a[MAXK],K,max_sum=0,first,last;
void init(){
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&a[i]);
    }
    first = a[0],last = a[K-1];
}

bool isAllNeg(){
    for(int i=0;i<K;i++){
        if(a[i]>=0) return false;
    }
    return true;
}

int main(){
    init();
    if(isAllNeg()){
        cout<<"0 "<<a[0]<<" "<<a[K-1]<<endl;
        return 0;
    }
    int cur_sum,s,t;
    s = 0,t = 0;
    cur_sum = 0;
    while(t<K){
        cur_sum+=a[t];
        if(cur_sum<0){
            cur_sum = 0;
            s = t+1;
        }
        if(cur_sum>max_sum){
            max_sum = cur_sum;
            first = s;
            last = t;
        }
        t++;
    }
    cout<<max_sum<<" "<<a[first]<<" "<<a[last]<<endl;
    return 0;
}