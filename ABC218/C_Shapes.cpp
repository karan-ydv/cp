#include <bits/stdc++.h>
using namespace std;

int n;
void rotateMatrix(string mat[])
{
	// Consider all squares one by one
	for (int x = 0; x < n / 2; x++) {
		// Consider elements in group
		// of 4 in current square
		for (int y = x; y < n - x - 1; y++) {
			// Store current cell in
			// temp variable
			int temp = mat[x][y];

			// Move values from right to top
			mat[x][y] = mat[y][n - 1 - x];

			// Move values from bottom to right
			mat[y][n - 1 - x]
				= mat[n - 1 - x][n - 1 - y];

			// Move values from left to bottom
			mat[n - 1 - x][n - 1 - y]
				= mat[n - 1 - y][x];

			// Assign temp to left
			mat[n - 1 - y][x] = temp;
		}
	}
}

bool match(string s[], string t[])
{
    for(int x = 0; x < n; x++)
    for(int y = 0; y < n; y++)
    {
        bool flag = true;
        for(int i = 0; flag and i < n; i++)
        for(int j = 0; flag and j < n; j++)
        {
            if(s[(x + i) % n][(y + j) % n] != t[i][j])
                    flag = false;
        }
        if(flag)    return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s[n], t[n];
    for(auto &x: s) cin >> x;
    for(auto &x: t) cin >> x;
    
    bool flag = match(s, t);

    // for(auto x: s)  cerr << x << '\n'; cerr << '\n';
    for(int i = 0; !flag and i < 3; i++) {
        rotateMatrix(s);
        flag |= match(s, t);
        // for(auto x: s)  cerr << x << '\n'; cerr << '\n';
    }
    flag ? cout << "Yes" : cout << "No";
}