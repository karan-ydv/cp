#include <bits/stdc++.h>
#define int long long
using namespace std;

char grid[10][10];

void print()
{
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 7; j++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	
}
char winner(char P)
{
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 7; j++) {
			int x = i, y = j, ctr = 0, c = 0;
			for(; x <= 6 and y <= 7 and ctr < 4; ctr++)
				c += (grid[x][y++] == P);
			if(c == 4)	return true;
		}
	}
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 7; j++) {
			int x = i, y = j, ctr = 0, c = 0;
			for(; x <= 6 and y <= 7 and ctr < 4; ctr++)
				c += (grid[x++][y] == P);
			if(c == 4)	return true;
		}
	}
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 7; j++) {
			int x = i, y = j, ctr = 0, c = 0;
			for(; x <= 6 and y <= 7 and ctr < 4; ctr++)
				c += (grid[x++][y++] == P);
			if(c == 4)	return true;
		}
	}
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 7; j++) {
			int x = i, y = j, ctr = 0, c = 0;
			for(; x <= 6 and y >= 1 and ctr < 4; ctr++)
				c += (grid[x++][y--] == P);
			if(c == 4)	return true;
		}
	}
	return false;
}

void place(int c, char P)
{
	for(int i = 1; i <= 7; i++) {
		if(grid[i][c] != 'R' and grid[i][c] != 'Y')
			return grid[i][c] = P, void();
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 1; i <= 42; i++) {
		int c;	cin >> c;
		if(i & 1)	place(c, 'R');
		else		place(c, 'Y');
		// print();
		if(winner('R'))
			return cout << "RED " << i, 0;
		
		if(winner('Y'))
			return cout << "YELLOW " << i, 0;
	}
	return cout << "DRAW", 0;
}