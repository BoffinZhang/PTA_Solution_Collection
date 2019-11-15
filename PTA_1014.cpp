// 1014 Waiting in Line
// 模拟调度
// 维护一条优先队列，用于处理全部的“用户交易”，进行处理的时间调度，重载小于号：结束时间-窗口ID
// 维护N个队列，处理每个窗口前的交易
// 每处理掉一个用户，它的下一个进入优先队列，同时一个新用户跨过黄线进入队列尾

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAXN = 1000 + 10;
struct CustomerQ {
    int endTime, queueId, customerId;
    CustomerQ() {}
    CustomerQ(int e, int q, int id) {
        endTime = e;
        queueId = q;
        customerId = id;
    }
    bool operator<(const CustomerQ& C) const {
        if (endTime != C.endTime)
            return endTime > C.endTime;
        else
            return queueId > C.queueId;
    }
};

int customerTime[MAXN], query[MAXN];
priority_queue<CustomerQ> cq;
queue<int> q[30];
int N, M, K, Q, ans[MAXN];
int TOTAL_WAITING = 0;
int CURRENT_CUSTOMER = 1;

void input() {
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= K; i++) {
        cin >> customerTime[i];
    }
    for (int i = 1; i <= Q; i++) {
        cin >> query[i];
    }
}

void solveCustomer() {
    // 总队列弹出第一个完成的顾客
    CustomerQ cur = cq.top();
    cq.pop();
    int qId = cur.queueId;
    int endTime = cur.endTime;
    ans[cur.customerId] = endTime;
    // 这个顾客弹出窗口队列，下一个人加入总队列，同时新的顾客跨过黄线加入窗口队列
    q[qId].pop();

    if (CURRENT_CUSTOMER <= K) {
        q[qId].push(CURRENT_CUSTOMER);
        CURRENT_CUSTOMER++;
    }

    if (!q[qId].empty()) {
        int next = q[qId].front();
        cq.push(CustomerQ(endTime + customerTime[next], qId, next));
    }
}

// 安排最初的排队情况
void arrangeCustomer() {
    for (int i = 1; i <= N; i++) {
        if (CURRENT_CUSTOMER > K) return;
        cq.push(CustomerQ(customerTime[CURRENT_CUSTOMER], i, CURRENT_CUSTOMER));
        q[i].push(CURRENT_CUSTOMER);
        CURRENT_CUSTOMER++;
        if (CURRENT_CUSTOMER > K) return;
    }
    for (int i = 2; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (CURRENT_CUSTOMER > K) return;
            q[j].push(CURRENT_CUSTOMER);
            CURRENT_CUSTOMER++;
            if (CURRENT_CUSTOMER > K) return;
        }
    }
}

void print_ans(int num) {
    int startTime = ans[num] - customerTime[num];

    int h = ans[num] / 60 + 8;
    int m = ans[num] % 60;
    // if ((h == 17 && m > 0) || h > 17)
    //     printf("Sorry\n");
    // else
    //     printf("%02d:%02d\n", h, m);
    if (startTime >= 540)            // 凡是在17:00及之后被移到队首的，均Sorry
        printf("Sorry\n");
    else
        printf("%02d:%02d\n", h, m);
}

void solve() {
    input();
    arrangeCustomer();
    while (!cq.empty()) {
        solveCustomer();
    }
    for (int i = 1; i <= Q; i++) {
        print_ans(query[i]);
    }
}

int main() {
    // freopen("in.data","r",stdin);
    solve();
    return 0;
}