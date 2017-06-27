#include<iostream>
#include<string>
using namespace std;

int map[10][10] = {
        { 0,4,3,3,4,3,2,3,1,2 },
        { 4,0,5,3,2,5,6,1,5,4 },
        { 3,5,0,2,5,4,3,4,2,3 },
        { 3,3,2,0,3,2,3,2,2,1 },
        { 4,2,5,3,0,3,4,3,3,2 },
        { 3,5,4,2,3,0,1,4,2,1 },
        { 2,6,3,3,4,1,0,5,1,2 },
        { 3,1,4,2,3,4,5,0,4,3 },
        { 1,5,2,2,3,2,1,4,0,1 },
        { 2,4,3,1,2,1,2,3,1,0 }
};
int map2[10] = { 4,6,5,3,5,5,6,5,5,4 };


int main() {
    std::ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while (T--) {
        int digit, K;
        string M;

        cin >> digit >> M >> K;

        int *arr = new int[digit];
        int *arr2 = new int[digit];
        int *result = new int[digit];

        std::fill_n(arr2, digit, 9);

        for (int i = 0; i < digit; i++) {
            arr[i] = M[i] - 48;
            result[i] = M[i] - 48;
        }

        int K2 = K;
        int num = 0;

        while (true) {
            if (map[arr[num]][arr2[num]] < K2) {
                if (num == digit - 1) {
                    if ((map2[arr[num]] < K2) || ((arr[num] == 2 || arr[num] == 4) && K2 == 1)) {
                        num--;
                        K2 += map[arr[num]][arr2[num]];
                        arr2[num]--;
                        if (arr2[num] == -1) {
                            arr2[num] = 9;
                            num--;
                            K2 += map[arr[num]][arr2[num]];
                            while (1) {
                                if (arr2[num] != 0)
                                    break;
                                arr2[num] = 9;
                                num--;
                                K2 += map[arr[num]][arr2[num]];
                            }
                            arr2[num]--;
                        }
                        continue;
                    }
                    else {
                        for (int i = 9; i >= 0; i--) {
                            if (map[arr[num]][i] == K2) {
                                result[num] = i;
                                break;
                            }
                        }
                        break;
                    }
                }
                result[num] = arr2[num];
                K2 -= map[arr[num]][arr2[num]];
                num++;
            }
            else if (map[arr[num]][arr2[num]] == K2) {
                result[num] = arr2[num];
                break;
            }
            else {
                if (arr2[num] == 0) {
                    while (1) {
                        if (arr2[num] != 0)
                            break;
                        arr2[num] = 9;
                        num--;
                        K2 += map[arr[num]][arr2[num]];
                    }
                    arr2[num]--;
                    continue;
                }
                arr2[num]--;
            }
        }

        for (int i = 0; i < digit; i++) {
            cout << result[i];
        }
        cout << endl;

    }
}