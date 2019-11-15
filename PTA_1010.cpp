// 1010 Radix
// 找到num2的最小基数，使得num1=num2

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<utility>
#include<cstring>
using namespace std;

int max_element(string s){
    int res = -1;
    for(int i=0;i<s.size();i++){
        int t = 0;
        if(s[i]<='9'&&s[i]>='0') res = max(res,s[i]-'0');
        else if(s[i]<='z'&&s[i]>='a') res = max(res,s[i]-'a'+10);
    }
    return res;
}

int to_num(char c){
    if(c<='9'&&c>='0') return c-'0';
    else return c-'a'+10;
}

int T_radix(string s,int radix){
    int sum = 0,r = 1;
    for(int i=s.size()-1;i>=0;i--){
        sum+=to_num(s[i])*r;
        r = r*radix;
    }
    return sum;
}


int main(){
    string s1,s2;
    long long num1,num2,tag,radix1;
    cin>>s1>>s2>>tag>>radix1;
    if(tag==2) swap(s1,s2);
    num1 = T_radix(s1,radix1);
    long long  max_radix = max_element(s2);
    long long t = 2;
    for(long long i=max(max_radix+1,t);i<=max(num1+10,t);i++){
        num2 = T_radix(s2,i);
        if (num1 == num2)
        {
            cout << i << endl;
            return 0;
        }
        if(num2>num1) break;
    }
    cout<<"Impossible"<<endl;
    return 0;
}