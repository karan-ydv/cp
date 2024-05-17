#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int64_t t;
    cin >> t;

    while (t--) {
        int64_t n, k;
        cin >> n >> k;
        vector<int64_t> a(n);

        for (int64_t i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int64_t ans = 0;

        int64_t lo = *min_element(a.begin(), a.end());
        int64_t hi = 1e12 + 1;

        while (lo < hi) {
            int64_t mid = (lo + hi) / 2;

            int64_t sum = 0;
            for (int64_t ai : a) {
                sum += (mid - ai > 0) ? (mid - ai) : 0;
            }

            if (sum > k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        int64_t m = hi - 1;
        int64_t sum1 = 0;
        for (int64_t ai : a) {
            sum1 += ai;
        }

        int64_t sum2 = 0;
        for (int64_t& ai : a) {
            if (ai < m) {
                ai = m;
            }
            sum2 += ai;
        }

        k -= sum2 - sum1;
        for (int64_t ai : a) {
            if (ai > m) k++;
        }

        cout << m * n - (n - 1) + k << '\n';
    }

    return 0;
}
