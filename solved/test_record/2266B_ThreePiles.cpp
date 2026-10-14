// Alice and Bob / 三堆石頭 賽局 (CF, 題號自己補)
// 坑1:賦值是拍照不是連線 -- ffin 先算完,之後改 x 是白改的。
// 坑2:「落後就不拿」是錯的 -- c 夠大時 Alice 拿光會超車。反例 a=0 b=1 c=3 -> 2。
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
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    // 候選①:Alice 第一手拿光 c。礦場空了,雙方只能拿 0 -> 立刻結束。
    ll takeAll  = llabs(a + c - b);
    // 候選②:Alice 拿 0。此時 Bob 拿任何石頭都只會讓 |A-B| 變大,
    //         所以 Bob 也拿 0 -> 連兩手 0 -> 結束,石頭數維持原樣。
    ll takeNone = llabs(a - b);

    // Alice 是 max 玩家,先手,兩個結局她都能單方面選 -> 挑大的。
    cout << max(takeAll, takeNone) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;                 // ← 單筆測資的題目,把這行註解掉
    while (T--) solve();
    return 0;
}
