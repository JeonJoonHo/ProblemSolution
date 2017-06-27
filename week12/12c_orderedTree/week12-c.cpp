#include <iostream>
using namespace std;

int dp[18][18];

int countCase(int last, int n) {
    if (n == 0) return 1;

    int res = 0;
    for (int i = 1; i <= n; i++){
        res += dp[last][i] * countCase(i, n-i);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    for(int i = 1; i <= 16; i++) {
        dp[i][0] = 1;
        dp[1][i] = 1;
    }

    for(int i = 2; i <= 16; i++) {
        for(int j = 1; j <= 17 - i; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    int T;

    cin >> T;

    while(T--) {
        int N, d, a, b, cnt, sum;

        cin >> N >> d;

        a = 1;
        cnt = 1;
        sum = 0;

        for(int i = 0; i <= d; i++) {
            cin >> b;
            cnt *= dp[a][b];
            a = b;
            sum += b;
        }

        if ( (N - sum) > 0) {
            cnt *= countCase(b, N-sum);
        }

        cout << cnt << endl;
    }
}