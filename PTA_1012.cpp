// 1012 The Best Rank
// 重写cmp函数，分3种情况排序，注意分数相同对排序的影响

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Stu {
    string id;
    int E, C, M;
    double A;
    Stu() {}
    Stu(int _C, int _M, int _E) {
        E = _E, C = _C, M = _M;
        A = (1.0 * E + C + M) / 3;
    }
    void cal() { A = (1.0 * E + C + M) / 3; }
    bool operator<(const Stu& b) { return id < b.id; }
};

struct BestRank {
    char Subject;
    int N;
};

bool cmpA(const Stu& a, const Stu& b) { return a.A > b.A; }

bool cmpC(const Stu& a, const Stu& b) { return a.C > b.C; }

bool cmpM(const Stu& a, const Stu& b) { return a.M > b.M; }

bool cmpE(const Stu& a, const Stu& b) { return a.E > b.E; }

map<string, BestRank> m;
Stu stu[30010];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> stu[i].id >> stu[i].C >> stu[i].M >> stu[i].E;
        stu[i].cal();
    }
    sort(stu, stu + N, cmpA);
    int sub = 0;
    for (int i = 0, j = 0; i < N; i++, j++) {
        if (i != 0 && stu[i].A == stu[i - 1].A) {
            j--;
            sub++;
        }
        else {
            j+=sub;
            sub = 0;
        }
        if (!m.count(stu[i].id)) {
            BestRank bs;
            bs.Subject = 'A';
            bs.N = j + 1;
            m[stu[i].id] = bs;
        }
    }

    sort(stu, stu + N, cmpC);
    sub = 0;
    for (int i = 0, j = 0; i < N; i++, j++) {
        if (i != 0 && stu[i].C == stu[i - 1].C) {
            j--;
            sub++;
        }
        else {
            j+=sub;
            sub = 0;
        }
        if (j + 1 < m[stu[i].id].N) {
            m[stu[i].id].Subject = 'C';
            m[stu[i].id].N = j + 1;
        }
    }
    sub = 0;
    sort(stu, stu + N, cmpM);
    for (int i = 0, j = 0; i < N; i++, j++) {
        if (i != 0 && stu[i].M == stu[i - 1].M) {
            j--;
            sub++;
        }
        else {
            j+=sub;
            sub = 0;
        }
        if (j + 1 < m[stu[i].id].N) {
            m[stu[i].id].Subject = 'M';
            m[stu[i].id].N = j + 1;
        }
    }
    sub = 0;
    sort(stu, stu + N, cmpE);
    for (int i = 0, j = 0; i < N; i++, j++) {
        if (i != 0 && stu[i].E == stu[i - 1].E) {
            j--;
            sub++;
        }
        else {
            j+=sub;
            sub = 0;
        }
        if (j + 1 < m[stu[i].id].N) {
            m[stu[i].id].Subject = 'E';
            m[stu[i].id].N = j + 1;
        }
    }
    string s;
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (!m.count(s)) {
            cout << "N/A" << endl;
            continue;
        }
        cout << m[s].N << " " << m[s].Subject << endl;
    }
    return 0;
}