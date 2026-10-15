// CF2195C  Dice Roll Sequence   rating 1100   存檔 2026-10-15
// https://codeforces.com/contest/2195/problem/C
// ⚠ AI 給的版本(滾動陣列 dp[2][7]),不是我寫的

#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9 + 7;
const int MAXN = 300005;

int a[MAXN];
int dp[2][7]; // 只有兩層：0 代表「偶數層」，1 代表「奇數層」

void solve() {
    int n;
    if (!(cin >> n)) return;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    // 1. 初始化第一層 (i = 1)
    // 我們手動填入 i=1 的狀況，這是滾動的起點
    for (int j = 1; j <= 6; ++j) {
        dp[1][j] = (a[1] == j ? 0 : 1);
    }

    // 2. 開始滾動轉移 (從 i = 2 走到 n)
    for (int i = 2; i <= n; ++i) {
        int now = i % 2;      // 當前這一層
        int prev = (i - 1) % 2; // 上一層

        for (int v = 1; v <= 6; ++v) {
            dp[now][v] = INF; // 每一層計算前，先把當前狀態設為無限大
            int cost = (a[i] == v ? 0 : 1);

            for (int u = 1; u <= 6; ++u) {
                // 判斷骰子相鄰規則：非同面 (u!=v) 且 非對面 (u+v!=7)
                if (u != v && u + v != 7) {
                    dp[now][v] = min(dp[now][v], dp[prev][u] + cost);
                }
            }
        }
    }

    // 3. 找出最後一層的最小值
    int final_layer = n % 2;
    int ans = INF;
    for (int j = 1; j <= 6; ++j) {
        ans = min(ans, dp[final_layer][j]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
