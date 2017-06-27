#include <iostream>
#include <math.h>
using namespace std;

int T;

int main(){
    std::ios::sync_with_stdio(false);

    cin >> T;

    int testcase = 0;
    while(true){
        int DP[301][301] = {0, };
        int card[301] = {0, };
        int M, N;   //카드 개수 임의의 수

        cin >> M >> N;

        int length =  1 + log2(N);

        for(int i = 1; i <= length; i++){
            card[i] = pow(2, i-1);
        }

        DP[0][0] = 1;
        for(int i = 1; i <= length; i++){
            DP[i][0] = 1;
            for(int j = 1; j <= N; j++){
                for(int k = 0; k <= M; k++){
                    if(card[i] * k > j){
                        break;
                    }
                    DP[i][j] += DP[i-1][j - card[i] * k];
                }
            }
        }

        cout << DP[length][N] << endl;
        testcase++;
        if(testcase == T){
            break;
        }
    }
}