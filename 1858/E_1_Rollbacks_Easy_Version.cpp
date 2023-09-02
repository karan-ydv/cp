#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree
{
    int n; vector<int> t;
    Segtree(int n) : n(n)
    {
        t.resize(n << 1);
    }
    int range_sum(int l, int r) {  // sum on interval [l, r)
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) (res += t[l++]);
            if(r & 1) (res += t[--r]);
        }
        return res;
    }
    void modify(int p, int v) {  // set value at position p
        for(t[p += n] = v; p > 0; p >>= 1)
            t[p >> 1] = (t[p] + t[p^1]);
    }
};

const int N = 20;
vector<int> pos(N, N);
vector<int> arr(N);

// st[i] = 1 if arr[i] is not present in array before i, else st[i] = 0
Segtree st(N);

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  stack<pair<char, int>> stk;
  stack<array<int, 4>> stk2;

  int q; cin >> q;

  int r = 0;
  while(q --> 0)
  {
    int x;
    char ch;
    cin >> ch;

    clog << ch << " : ";

    if (ch == '?')
    {
      clog << r << '\n';
      cout << st.range_sum(0, r) << '\n';
      continue;
    }
    if (ch == '!')
    {
      auto [a, b] = stk.top();
      stk.pop();

      clog << a << ' ' << b << '\n';

      if (a == '-')
        r += b;
      else
      {
        r--;
        auto [x, px, y, py] = stk2.top();
        stk2.pop();
        if (pos[x] != px)
        {
          pos[x] = px;
        }
        if (pos[y] != py)
        {
          pos[y] = py;
        }
      }
      continue;
    }

    cin >> x;
    stk.push({ch, x});

    clog << x << " -> ";

    if (ch == '-') {
      r -= x;
      // cout << "\n";
    }
    
    if (ch == '+')
    {
      clog << pos[x] << ' ' << r << " <- ";
      stk2.push({x, pos[x], arr[r], pos[arr[r]]});
      if (pos[x] > r)
      {
        st.modify(r, 1);
        pos[x] = r;
      }
      if (pos[arr[r]] == r)
      {
        st.modify(r, 0);
        pos[arr[r]] = N;
      }
      arr[r++] = x;
    }

    for(int i = N; i < 2 * N; i++)
      clog << st.t[i] << " ";
    clog << '\n';
  }
}


// 1 1 1 2
// 1 0 0
