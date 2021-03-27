#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
	int t;	cin >> t;
	while(t--)
	{
		bool flag = true;
		string inp;
		for(int i = 0; i < 46; i++)
		{
			int p = v[i];
			cout << p << endl;
			cin >> inp;
			if(inp == "YES")
			{
				if(p * p < 401)
				{
					cout << p * p << endl;
					cin >> inp;
					if(inp == "YES")
					{
						flag = false;
						break;
					}
				}
				for(int j = i + 1; j < 46 and v[j] * p < 401 ; j++)
				{
					cout << v[j] << endl;
					cin >> inp;
					if(inp == "YES")
					{
						flag = false;
						break;
					}
						
				}
				break;
			}
		}
		if(flag)	cout << "1" << endl;
		else		cout << "0" << endl;
	}
}