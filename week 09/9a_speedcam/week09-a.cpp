#include <iostream>
#include <string.h>
using namespace std;

int cityNumber, roadNumber;
long long int totalCity, totalPerson;
long long int sumCity, sumPerson;

int cityIndex[5001][5001];
int map[5001][5001];
long long int result[5001];
int visit[5001];

void DFS(int start, int size){
    visit[start] = 1;

    for(int i = 1; i <= size; i++){
        if(map[start][i] == 1 && visit[i] == 0){
            sumPerson += cityIndex[i][1];
            sumCity += cityIndex[i][2];
            DPS(i, size);
        }
    }
}

int main() {
    int T;

    cin >> T;

    while(T--) {
        totalCity = 0;
        totalPerson = 0;

        cin >> cityNumber >> roadNumber;

        for(int i = 1; i <= cityNumber; i++){
            memset(map[i], 0 , sizeof(int) * 5001);
            memset(cityIndex[i], 0, sizeof(int) * 5001);
        }

        memset(result, 0, sizeof(long long int) * 5001);
        memset(visit, 0, sizeof(int) * 5001);

        for(int i = 1; i <= cityNumber; i++){
            cin >> cityIndex[i][1] >> cityIndex[i][2]; // 1번 째 인구 수, 2번 째 놀이시설 수
            totalPerson += cityIndex[i][1];
            totalCity += cityIndex[i][2];
        }

        for(int i = 1; i <= roadNumber; i++){
            int s, e;
            cin >> s >> e;

            map[s][e] = 1;
        }

        for(int i = 1; i <= cityNumber; i++){
            for(int j = 1; j <= cityNumber; j++) visit[j] = 0;
            sumCity = 0;
            sumPerson = 0;

            sumPerson += cityIndex[i][1];
            sumCity += cityIndex[i][2];

            DPS(i, cityNumber);

            result[i] = (sumPerson * (totalCity - sumCity)) + ((totalPerson - sumPerson) * sumCity);
        }

        long long int maxNumber = 0;
        for(int i = 1; i <= cityNumber; i++){
            long long int number = result[i];
            if(maxNumber < number){
                maxNumber = number;
            }
        }

        cout << maxNumber << endl;
    }
}