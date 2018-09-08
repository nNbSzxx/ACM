#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

struct node {
    long long minn, maxx;
    node () {}
    node (long long mi, long long ma): minn(mi), maxx(ma) {}
    node operator+ (const node& rhs) {
        return node(minn + rhs.minn, maxx + rhs.maxx);
    }
    node operator- (const node& rhs) {
        return node(minn - rhs.maxx,
                    maxx - rhs.minn);
    }
    node operator* (const node& rhs) {
        long long mi = LLONG_MAX;
        long long ma = LLONG_MIN;
        long long t = minn * rhs.minn;
        mi = min(t, mi); ma = max(t, ma);
        t = minn * rhs.maxx;
        mi = min(t, mi); ma = max(t, ma);
        t = maxx * rhs.minn;
        mi = min(t, mi); ma = max(t, ma);
        t = maxx * rhs.maxx;
        mi = min(t, mi); ma = max(t, ma);
        return node(mi, ma);
    }
    node operator^ (const node& rhs) {
        long long mi = max(minn, 0LL) * 1;
        long long ma = maxx * rhs.maxx;
        return node(mi, ma);
    }
};

node calculate(node operator1, node operator2, char operand)
{
    node ans;
    switch(operand) {
        case '+' :
            ans = operator1 + operator2;
            break;
        case '-' :
            ans = operator1 - operator2;
            break;
        case '*' :
            ans = operator1 * operator2;
            break;
        case 'd' :
            ans = operator1 ^ operator2;
            break;
    }
    return ans;
}
node doCalculate(stack<node> &sNum, stack<char> &sOperator)
{
    node operator1 = sNum.top(); sNum.pop();
    node operator2 = sNum.top(); sNum.pop();
    char operand = sOperator.top(); sOperator.pop();
    return calculate(operator2, operator1, operand);
}
bool isNum(char c)
{
    if (c <= '9' && c >= '0') return true;
    else return false;
}
bool isOperand(char c)
{
    if (c == '+' || c == '-' || c == 'd' || c == '*' || c == '(' || c == ')' || c == '=') return true;
    else return false;
}
int getWeigh(char c)
{
    if (c == '(') return 10;
    if (c == '+' || c == '-') return 1;
    if (c == '*') return 2;
    if (c == 'd') return 4;
}
int getWeigh(stack<char> &sOperator)
{
    if (sOperator.top() == '(') return 0;
    if (sOperator.top() == '+' || sOperator.top() == '-') return 1;
    if (sOperator.top() == '*') return 2;
    if (sOperator.top() == 'd') return 3;
}

int main()
{
    stack<node> sNum;
    stack<char> sOperand;
    char s[110];
    while (~scanf(" %s", s)) {
        while (!sNum.empty()) {
            sNum.pop();
        }
        while (!sOperand.empty()) {
            sOperand.pop();
        }
        int len = strlen(s);
        s[len] = '=';
        s[len + 1] = '\0';
        long long num = 0;
        int isLastNum = 0;
        for (int i = 0; i <= len; i ++) {
            char c;
            c = s[i];
            if (isNum(c)) {
                num = num * 10 + (c - '0');
                isLastNum = 1;
            }
            if (isOperand(c)) {
                if (isLastNum) {
                    sNum.push(node(num, num));
                    num = 0;
                }
                isLastNum = 0;
                if (c == '=') {
                    while (!sOperand.empty()) {
                        sNum.push(doCalculate(sNum, sOperand));
                    }
                    break;
                } else if (c == ')') {
                    while (!sOperand.empty() && sOperand.top() != '(') {
                        sNum.push(doCalculate(sNum, sOperand));
                    }
                    sOperand.pop();
                } else {
                    int weighNow = getWeigh(c);
                    while (!sOperand.empty() && weighNow <= getWeigh(sOperand)) {
                        sNum.push(doCalculate(sNum, sOperand));
                    }
                    sOperand.push(c);
                }
            }
        }
        printf("%lld %lld\n",sNum.top().minn, sNum.top().maxx);
    }
    return 0;
}
