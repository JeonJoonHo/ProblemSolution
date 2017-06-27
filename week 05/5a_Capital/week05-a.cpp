#include <iostream>
#include <algorithm>
using namespace std;

int T;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> T;

    int testCase = 0;
    while (true) {
        int city[502][502] = { 0 };
        int result[502] = { 0 };
        int minLength[502] = { 0 };

        int cityNumber, roadNumber;

        cin >> cityNumber >> roadNumber;

        for (int i = 1; i <= cityNumber; i++) {
            cin >> city[0][i];  //0번째 인덱스에 인구 수 저장
        }

        for(int i = 1; i <= cityNumber; i++){
            for (int j = 1; j <= cityNumber; j++){
                if(i == j){
                    city[i][j] = 0;
                }
                else {
                    city[i][j] = 1000;
                }
            }
        }


        for (int i = 1; i <= roadNumber; i++) {
            int aCity, bCity; // aCity와 bCity의 도로 연결 여부
            cin >> aCity >> bCity;

            city[aCity][bCity] = 1;  // aCity와 bCity의 도로가 연결 됨
            city[bCity][aCity] = 1;
        }

        for (int k = 1; k <= cityNumber; k++)
        {
            for (int i = 1; i <= cityNumber; i++)
            {
                for (int j = 1; j <= cityNumber; j++)
                {
                    if (city[i][k] + city[k][j] < city[i][j])
                    {
                        city[i][j] = city[i][k] + city[k][j];    // 최단 거리
                    }
                }
            }
        }

        for (int i = 1; i <= cityNumber; i++) {
            for (int j = 1; j <= cityNumber; j++) {
                city[i][cityNumber + 1] += city[i][j];
                if (minLength[i] < city[i][j]) {
                    minLength[i] = city[i][j];
                }
            }
        }

        int res = 999999999;

        for (int i = 1; i <= cityNumber; i++) {
            result[i] = ((cityNumber - 1) * minLength[i]) + city[i][cityNumber + 1];
            if(res > result[i]){
                res = result[i];
            }
        }

        int people[502][2] = { 0 };
        int peo = 0;
        for (int i = 1; i <= cityNumber; i++) {
            if (res == result[i]) {
                people[i][0] = city[0][i];
                people[i][1] = i;
                if (peo < people[i][0]) {
                    peo = people[i][0];
                }
            }
        }

        for (int i = 1; i <= cityNumber; i++) {
            if (peo == people[i][0]) {
                cout << people[i][1] << endl;
            }
        }

        testCase++;
        if (T == testCase) {
            break;
        }
    }

}
