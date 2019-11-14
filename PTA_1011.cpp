// 1011 World Cup Betting
// 选出每行的最大值，对应字母，输出乘积即可
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    double a[3][3],ans=1;
    char m[4] = "WTL";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        double t_max = 0;
        int cur = -1;
        for(int j=0;j<3;j++){
            if(t_max<a[i][j]){
                cur = j;
                t_max = a[i][j];
            }
        }

        printf("%c ",m[cur]);
        ans = ans*a[i][cur];
    }
    ans = 2*(ans*0.65-1);
    printf("%.2lf",ans);
    return 0;
}