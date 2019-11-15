// Spell It Right 
// 换成英文输出
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

string n2s[10] = {"zero","one","two","three","four",
                    "five","six","seven","eight","nine"};
long long sum;
string s;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        sum +=s[i]-'0';
    }
    s = to_string(sum);
    for(int i=0;i<s.size();i++){
        if(i>0) cout<<" ";
        cout<<n2s[s[i]-'0'];
    }
    return 0;
}
