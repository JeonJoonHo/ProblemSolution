#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXARRAY 6

bool map[MAXARRAY][MAXARRAY];
bool check[MAXARRAY][MAXARRAY];

stack< int > location[MAXARRAY][MAXARRAY];

void find(int y, int x, int before, int size) {
    int checkX[] = { 0, 1, -1, 0, 0 };
    int checkY[] = { 0, 0, 0, 1, -1 };

    if (map[y][x] == true || check[y][x] == true) return;
    if (y < 0 || y >= size || x < 0 || x >= size) return;

    location[y][x].push(location[y - checkY[before]][x - checkX[before]].top() + 1);
    check[y][x] = true;

    for (int i = 1; i <= 4; i++) {
        find(y + checkY[i], x + checkX[i], i, size);
        if (i == 4) check[y][x] = false;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--) {
        int N, M, result;
        int X, Y;

        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        for (int g = 0; g < M; g++) {
            cin >> Y >> X;

            for (int i = 0; i < MAXARRAY; i++) {
                for (int j = 0; j < MAXARRAY; j++) {
                    while (!location[i][j].empty()) {
                        location[i][j].pop();
                    }
                }
            }

            result = 0;

            location[Y][X].push(0);
            find(Y, X, 0, N);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    while(!location[i][j].empty()) {
                        result = max(result, location[i][j].top());
                        location[i][j].pop();
                    }
                }
            }
            cout << result<< endl;

        }
    }
}