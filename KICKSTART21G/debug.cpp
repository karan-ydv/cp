#include <bits/stdc++.h>
using namespace std;

struct token {
    char op{'~'};
    int val{0};
    token() {}
    token(char c) : op(c) {}
    token(int v) : val(v) {}
};

map<char, int> precedence{
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2}
};

vector<token> to_postfix(string& s)
{
    stack<token> stk;
    vector<token> postfix;
    stk.push(token{'#'});
    char prev = '!';
    for(char c: s) {
        if(c == ' ') continue;
        if(isdigit(c))
        {
            if(!isdigit(prev))
                postfix.push_back(token{});
            (postfix.back().val *= 10) += c - '0';
        }
        else if(c == '(')
            stk.push(token{c});
        else if(c == ')')
        {
            while(stk.top().op != '(')
            {
                postfix.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while(precedence[c] <= precedence[stk.top().op])
            {
                postfix.push_back(stk.top());
                stk.pop();
            }
            stk.push(token{c});
        }
        prev = c;
    }
    while(stk.top().op != '#') {
        postfix.push_back(stk.top());
        stk.pop();
    }
    for(auto &x: postfix) {
        if(x.op == '~') cerr << x.val << ' ';
        else            cerr << x.op << ' ';
    } cerr << '\n';
    return postfix;
}
int eval(int a, int b, char op) {
    switch (op)
    {
        case '+':   return a + b;
        case '-':   return a - b;
        case '*':   return a * b;
        case '/':   return a / b;
    }
    return 0;
}
int evaluate_postfix(vector<token> v)
{
    stack<int> stk;
    for(auto &x: v)
    {
        if(x.op == '~')
            stk.push(x.val);
        else
        {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(eval(a, b, x.op));
        }
    }
    return stk.top();
}
class Solution {
public:
    int calculate(string s) {
        return evaluate_postfix(to_postfix(s));
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    cout << Solution().calculate(s);
}