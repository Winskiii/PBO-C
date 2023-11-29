#include <iostream>
#include <stack>
using namespace std;

int trapWater(int arr[], int n) {
    stack<int> st;
    int result = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            int top = st.top();
            st.pop();
            if (!st.empty()) {
                int distance = i - st.top() - 1;
                int boundedHeight = min(arr[i], arr[st.top()]) - arr[top];
                result += distance * boundedHeight;
            }
        }
        st.push(i);
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << trapWater(arr, n);

    return 0;
}
