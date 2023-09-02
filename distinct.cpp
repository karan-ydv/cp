#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

vector<int> hasVowels(vector<string> strArr, vector<string> query) {
  int n = strArr.size();
  int m = query.size();
  vector<int> result(m), prefix(n + 1, 0);
  string vowels = "aeiou";
  for(int i = 0; i < n; i++)
  {
    bool has_vowels = (vowels.find(strArr[i].front()) != string::npos) &&
                      (vowels.find(strArr[i].back()) != string::npos);
    prefix[i + 1] = prefix[i] + has_vowels;
  }
  for(int i = 0; i < m; i++)
  {
    int l = stoi(query[i].substr(0, query[i].find('-')));
    int r = stoi(query[i].substr(query[i].find('-') + 1));
    result[i] = prefix[r] - prefix[l - 1];
  }
  return result;
}

int main()
{
  vector<string> strArr = {"aab", "a", "bcd", "awe", "bbbbbu"};
  vector<string> query = {"2-3", "4-5"};
  vector<int> result = hasVowels(strArr, query);
  for(int x: result) {
    cout << x << ' ';
  }
}