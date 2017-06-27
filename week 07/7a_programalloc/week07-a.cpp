#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--) {
        int M, N, result;
        cin >> M >> N;

        vector<pair<int, int>> program;

        int* dp = new int[N];

        for (int i = 0; i < N; i++) {
            int s, f;
            cin >> s >> f;

            program.push_back(pair<int, int>(s, f));
            dp[i] = 1;
        }

        sort(program.begin(), program.end());

        result = dp[0];
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (program[j].second <= program[i].first && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > result) result = dp[i];
        }

        cout << result << endl;

        delete[] dp;
    }
}