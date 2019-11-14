// A+B Format
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int A,B,len;
    string s;
    cin>>A>>B;
    s = to_string(abs(A+B));
    if(A+B<0) cout<<"-";
    len = s.length();
    for(int i=0;i<len;i++){
        cout<<s[i];
        if((len-i)%3==1&&i!=len-1) cout<<",";
    }
    cout<<endl;
    return 0;
}