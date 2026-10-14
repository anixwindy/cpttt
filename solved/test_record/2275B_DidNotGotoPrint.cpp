//
// Created by user on 2026/10/8.
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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    //n 個文件  文件字串s
    vector<int> mm;
    vector<int> printed(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];

        if (c == '1') {
            mm.pb(i);
        } else if (c == '2') {
            if (!mm.empty()) {
                printed[mm.back()] = 1;
                mm.pop_back();
            } else {
                printed[i] = 1;
            }
        } else {
            printed[i] = 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!printed[i]) ans.pb(i);
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;                 // ← 單筆測資的題目,把這行註解掉
    while (T--) solve();
    return 0;
}
