// 1010 Radix
// 找到num2的最小基数，使得num1=num2

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

typedef long long ll;
string s1, s2;
ll num1, tag, radix1;

int max_element(string s) {
    int res = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= '9' && s[i] >= '0')
            res = max(res, s[i] - '0');
        else if (s[i] <= 'z' && s[i] >= 'a')
            res = max(res, s[i] - 'a' + 10);
    }
    return res;
}

int to_num(char c) {
    if (c <= '9' && c >= '0')
        return c - '0';
    else
        return c - 'a' + 10;
}

ll T_radix(string s, int radix) {
    ll sum = 0, r = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        sum += to_num(s[i]) * r;
        r = r * radix;
    }
    return sum;
}

int main() {
    cin >> s1 >> s2 >> tag >> radix1;
    if (tag == 2) swap(s1, s2);
    num1 = T_radix(s1, radix1);
    // 确定边界lb 和 rb
    ll lb, rb, mid, ans = -1;
    lb = max_element(s2) + 1;
    rb = max(num1, lb);
    while (lb <= rb) {
        mid = (lb + rb) / 2;
        ll num2 = T_radix(s2, mid);
        if (num2<0||num2 > num1) {
            rb = mid - 1;
        } else if (num1 > num2) {
            lb = mid + 1;
        } else {
            ans = mid;
            break;
        }
    }

    if (ans != -1)
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}