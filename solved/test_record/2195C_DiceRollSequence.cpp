// CF2195C  Dice Roll Sequence   rating 1100   存檔 2026-10-15
// https://codeforces.com/contest/2195/problem/C
// 我的版本(記憶化遞迴,上面這份) : AC  156 ms  52700 KB ← 記憶體太大
// AI 給的版本(滾動陣列 dp[2][7]) : 2195C_DiceRollSequence_AI.cpp。⚠ 那份不是我寫的
//
// Created by user on 2026/2/16.
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

const ll INF = 1e9+7;
const ll MAXN = 300008;
ll n,a[MAXN];
ll memo[MAXN][7];


int  solve(int i , int last) {
    if (i>n) return 0;
    if (memo[i][last]!=-1)return memo[i][last];
    int res =INF;
    for (int j = 1; j <=6; ++j) {
        if (last == 0||(j!=last && j+last !=7)) {
            int cost  =(a[i]== j?0:1);
            res =min(res,solve(i+1,j)+cost);
        }
    }
    return memo[i][last]=res;
}

void solve02() {

    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        for (int j = 0; j <=6; ++j) {
            memo[i][j] = -1;

        }

    }cout<<solve(1,0)<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve02();
    }

    return 0;
}
