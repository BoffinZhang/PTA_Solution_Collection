// 1009 Product of Polynomials
// 多项式乘积，开两个1000的数组，然后二重循环即可

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN = 1000+10;
double eps = 1e-5;
double a[MAXN],b[MAXN],c[2*MAXN];
void input(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int N, s;
    double t;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s>>t;
        a[s]=t;
    }

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s>>t;
        b[s]=t;
    }
}

void output(){
    int num = 0;
    for(int i=2000;i>=0;i--){
        if(abs(c[i]-0)>eps) num++;
    }
    cout<<num;
    for(int i=2000;i>=0;i--){
        if(abs(c[i]-0)>eps) printf(" %d %.1lf",i,c[i]);
    }
}

int main(){
    input();
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            c[i+j] +=a[i]*b[j];
        }
    }
    output();
    return 0;
}