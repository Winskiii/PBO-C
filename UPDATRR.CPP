#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        int N, Q;
        cin >> N >> Q;
        
        vector<int> arr(N, 0);
        
        for (int i = 0; i < Q; ++i) {
            unsigned long long a, b;
            cin >> a >> b;
            
            arr[a - 1]++;

            if (a - 2 * b >= 1) {
                arr[a - 2 * b - 1]--;
            }

            if (a + 2 * b <= N) {
                arr[a + 2 * b - 1]++;
            }
        }
         for (int i = 1; i < N; i++) {
            arr[i] += arr[i - 1];
    }

        cout << "Case " << tc << ": ";
        for (int i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
