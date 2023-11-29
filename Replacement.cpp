#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int getNum() {
    int res = 0;
    char c;
    int b = 0;
    while (1) {
        c = getchar_unlocked();
        if (c == '-') b = 1;
        if (c == ' ' || c == '\n') continue;
        else break;
    }
    if (c != '-') res = c - '0';
    while (1) {
        c = getchar_unlocked();
        if (c >= '0' && c <= '9') res = 10 * res + c - '0';
        else break;
    }
    if (b == 1) res *= -1;
    return res;
}

int main() {
    int n;
    n = getNum();

    vector<int> barisan(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        barisan[i] = getNum();
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && barisan[i] > barisan[st.top()]) {
            res[st.top()] = barisan[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    return 0;
}