// 1006 Sign In and Sign Out
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

struct Date{
    int h,m,s;
    Date(){}
    Date(int _h,int _m,int _s):h(_h),m(_m),s(_s){}
    void set(int _h,int _m,int _s){
        h = _h;
        m=_m;
        s=_s;
    }
    bool operator<(const Date& d)const{
        if(h!=d.h) return h<d.h;
        else if(m!=d.m) return m<d.m;
        return s<d.s;
    }
};

int main(){
    Date max_d(-1,0,0),min_d(25,0,0);
    string first_login,last_logout;
    string t;
    Date t_login,t_logout;
    int N;
    scanf("%d",&N);

    for (int i = 0; i < N; i++)
    {
        cin>>t;
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        t_login.set(h,m,s);
        if(t_login<min_d){
            min_d = t_login;
            first_login = t;
        }
        scanf("%d:%d:%d",&h,&m,&s);
        t_logout.set(h,m,s);
        if(max_d<t_logout){
            max_d = t_logout;
            last_logout = t;
        }
    }
    cout<<first_login<<" "<<last_logout<<endl;
    return 0;
}