//
// Created by user on 2026/10/9.
//

#if defined(__GNUC__) && !defined(__clang__)
    #include <bits/stdc++.h>          // GCC / MinGW(CLion 走這條)
#else
    #include <algorithm>              // MSVC 沒有 bits/stdc++.h
    #include <array>
    #include <bitset>
    #include <cmath>
    #include <cstring>
    #include <deque>
    #include <functional>
    #include <iostream>
    #include <map>
    #include <numeric>
    #include <queue>
    #include <set>
    #include <string>
    #include <tuple>
    #include <unordered_map>
    #include <unordered_set>
    #include <vector>
#endif

using namespace std;

// ---- 型別:全部用 using ----
using ll  = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
template<class T> using vec = vector<T>;            // macro 做不到的
template<class T> using vec2 = vector<vector<T>>;

// ---- 非型別:只能用 macro ----
#define pb push_back
#define fi first
#define se second
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (int)(x).size()


const ll  INF = LLONG_MAX / 4;
const int MOD = 1000000007;

// ── debug:交出去之前不用刪,它只在本機有作用 ──────────
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif
// ────────────────────────────────────────────────

// 過一晚:x 變成「各位數字的平方和」
// 例:16 → 1² + 6² = 37
ll nxt(ll x) {
    ll s = 0;
    while (x > 0) {
        ll d = x % 10;   // 拿到最後一位
        s += d * d;      // 平方加進總和
        x /= 10;         // 砍掉最後一位
    }
    return s;
}

void solve() {
    int n;
    cin >> n;

    map<ll, ll> cnt;     // cnt[v] = 「目前為止」第 1000 晚顯示 v 的燈塔有幾座
                         // ⚠ 宣告在 solve() 裡面 → 每筆測資自動清空
    ll ans = 0;          // ⚠ 要 ll:n 個全部一樣時,對數 ≈ n²/2,會超過 int
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;

        // ── 第 1 步:把 a 換成「第 1000 晚」的數字 ──
        // ⚠ 這個 for 沒有大括號 → 只有 a = nxt(a); 這一句跑 1000 次
        //    下面的 ans += 和 cnt[a]++ 不在這個迴圈裡,每座燈塔只跑 1 次
        // 例:7 → 49 → 97 → 130 → 10 → 1 → 1 → ... 最後 a = 1
        for (int k = 0; k < 1000; k++) a = nxt(a);   // 走 1000 晚
        // 走完之後,原本的數字就不重要了,只看第 1000 晚的 a

        // ── 第 2 步:數對數(握手比喻)──
        // 燈塔一座一座「走進教室」,每座進門時
        // 跟教室裡「已經在的、同一個數字的」每一座各握一次手
        // 每握一次手 = 一對相同的燈塔
        // cnt[a] 沒出現過時,map 會自動建立成 0,所以第一次遇到會加 0
        ans += cnt[a];   // 新來的這座,跟前面每一座同標籤的都能湊一對

        // ── 第 3 步:把自己記進去,給後面的燈塔配對 ──
        // ⚠ 一定要「先 ans +=,再 ++」
        //    寫反 → 自己會跟自己算成一對,答案多出 n
        cnt[a]++;
    }
    // 例:7 4 16 4 2 → 第 1000 晚是 1 4 16 4 20
    //   燈塔 4 進門時 cnt[4] = 1(燈塔 2),ans += 1 → 答案 1
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T = 1;
    cin >> T;                 // ← 單筆測資的題目,把這行註解掉
    while (T--) solve();
    return 0;
}
