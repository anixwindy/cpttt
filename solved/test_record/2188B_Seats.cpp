// CF2188B  Seats   rating 1000   存檔 2026-10-15
// https://codeforces.com/contest/2188/problem/B
//
// Created by user on 2026/1/30.
//
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    // ============ 在這裡寫你的解題code ============

    ll n;
    string s;
    cin >> n;
    cin >> s;
    vi p;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') p.pb(i);
        ////  存「索引」
        //請看這張圖：假設輸入字串 s = "00101"，掃描
        //s[2] 是 '1'！觸發 p.pb(2)。
        //現在清單 p = {2}。//這個2 是原字串裡的位址索引
    }

    if (p.empty()) {
            cout<< (n + 2) / 3<<endl;

    } else {
        vll p2;//虛擬哨兵，也是 陣列 []
        p2.push_back(-2);
        for(int x : p) p2.push_back(x);
        //示意圖[-2   p   n+1]
        //for(int a:b) 从数组b依次取出元素赋值给整形变量a，循环执行for中语句
        //一樣for(int i = 0; i < p.size(); i++) p2.push_back(p[i]);
        p2.push_back(n + 1);

        // 初始人數不變
        ll res = p.size();

        // 用一個迴圈跑完所有區間（包括邊界）
        //i=1 因為要 減前一位 算距離
        for (int i = 1; i < p2.size(); i++) {
            ll blank = p2[i] - p2[i-1] - 1;//總和=尾+頭+1 (國高中數學)
            res += (blank) / 3;//示意[k 000 u ] 可以補人
        }
        cout << res << endl;

    }


    // ============================================
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;  // 如果題目只有一組測試,就把這行註解掉

    while(t--) {
        solve();
    }

    return 0;
}
