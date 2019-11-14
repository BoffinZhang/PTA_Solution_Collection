//1002 A+B for Polynomials
#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

map<int,double> A;
map<int,double> B; 
int K;
int maxN = 0;
int n,a;
int main(){
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>n>>a;
        maxN = max(n,maxN);
        if(!A.count(n)){
            A[n]=a;
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>n>>a;
        maxN = max(n,maxN);
        if(!B.count(n)){
            B[n]=a;
        }
    }
}