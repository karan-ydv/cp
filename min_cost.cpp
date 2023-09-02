#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s, int k) {
    int i = 0, n = s.length();
    int count[n]{0};
    for (int j = 0; j < n; ++j, ++i) {
        s[i] = s[j];
        count[i] = i > 0 && s[i - 1] == s[j] ? count[i - 1] + 1 : 1;
        if (count[i] == k) i -= k;
    }
    return s.substr(0, i);
}

int main()
{
  int k; string s;
  cin >> k >> s;
  cout << reduce_string(s, k, 0);
}
