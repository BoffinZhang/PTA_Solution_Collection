// PTA 1008 Elevator
// 模拟
#include<iostream>
using namespace std;

int main(){
    int stay,N,next,ans;
    stay = 0,ans = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>next;
        if(next>stay){
            ans+=(next-stay)*6+5;
            stay = next;
        }
        else if(next<stay){
            ans+=(stay-next)*4+5;
            stay = next;
        }
        else ans+=5;
    }
    cout<<ans<<endl;
    return 0;
}