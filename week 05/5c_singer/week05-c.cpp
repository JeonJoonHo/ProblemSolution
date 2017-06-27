#include <iostream>
using namespace std;

int T;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> T;

    int testcase = 0;
    while(true){
        bool musician[1001][1001] = { 0 };
        int cnt[1001] = { 0 };
        int order[1001] = { 0 };
        int PD, singer;
        cin >> singer >> PD;

        for(int i = 0; i < PD; i++){
            int num, next;
            cin >> num;

            int prev = 0;
            for(int j = 0; j < num; j++){
                cin >> next;
                if(musician[prev][next]){
                    prev = next;
                    continue;
                }
                musician[prev][next] = 1;
                if(j == 0){
                    musician[prev][next] = 0;
                }
                else {
                    cnt[next]++;
                }
                prev = next;
            }
        }

        int i;
        for (i = 1; i <= singer; ++i){
            int j, temp;
            for(j = 1; j<=singer; j++){
                if(cnt[j] == 0){
                    cnt[j] = -1;
                    break;
                }
            }

            if(j > singer){
                break;
            }

            temp = j;
            order[i] = temp;

            for(j = 1; j <=singer; j++){
                if(temp != j){
                    if (musician[temp][j]){
                        musician[temp][j] = 0;
                        cnt[j]--;
                    }
                }
            }
        }

        if (i != singer + 1){
            cout << 0 << endl;
        }
        else {
            for (int k = 1; k <= singer; ++k)
            {
                cout << order[k] << " ";
            }
            cout << endl;
        }

        testcase++;
        if(testcase == T){
            break;
        }
    }
}
