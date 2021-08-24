#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
        if(numerator % denominator == 0) {
            return to_string(numerator / denominator);
        }
        
        string integerPart{to_string(numerator / denominator)};
        integerPart += '.';
        numerator %= denominator;
        string decimalPart;
        unordered_map<int, int> occurred;
        for(int i = 0; numerator % denominator != 0; i++)
        {
            if(occurred.count(numerator))
            {
                decimalPart.insert(decimalPart.begin() + occurred[numerator], '(');
                decimalPart += ')';
                break;
            }
            occurred[numerator] = i;
            numerator *= 10;
            decimalPart += to_string(numerator / denominator);
            numerator %= denominator;
        }
        return integerPart + decimalPart;
}

int main() { int t;  cin >> t; while(t--) {
    int x, y;   cin >> x >> y;
    cout << fractionToDecimal(x, y) << '\n';
}}