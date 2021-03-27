// C++ implementation of above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print the required points which 
// minimizes the sum of Manhattan distances 
void minDistance(int n, int k, vector<vector<int> >& point) 
{ 

	// Sorting points in all k dimension 
	for (int i = 0; i < k; ++i) 
		sort(point[i].begin(), point[i].end()); 

	// Output the required k points 
	for (int i = 0; i < k; ++i) 
		cout << point[i][(ceil((double)n / 2) - 1)] << " "; 
} 

int main() 
{ 
	int n, k = 2;	cin >> n;
	vector<vector<int> > point(n, vector<int>(2)); 
	for(int i = 0; i < n; i++) {
		cin >> point[i][0] >> point[i][1];
	}
	minDistance(n, k, point);
} 
