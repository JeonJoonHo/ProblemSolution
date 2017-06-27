#include <iostream>
#include <string.h>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//int gameBoard[2501][2501];

struct Game{
    int value;
    pair <int, int> location;
};

bool predicate(const Game& g1, const Game& g2)
{
    // 이름으로비교
    return ( g1.value < g2.value );
}

int main(){
    std::ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while(T--){
        int M, N, K; //M : 행 N : 열 K : 게임 수

        cin >> M >> N;

        vector < Game > gameBoard;
        Game game;

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cin >> game.value;
                game.location = make_pair(i,j);

                gameBoard.push_back(game);
            }
        }

        sort(gameBoard.begin(), gameBoard.end(), predicate);

        cin >> K;

        while(K--){
            int L; //L : 카드 덱 개수
            list <int> A;
            list <int> B;

            int Alocation[1][2] = {0, };
            int Blocation[1][2] = {0, };

            int AHP, BHP ,HP , Mlocate, Nlocate;

            cin >> L;

            for(int i = 0; i < L; i++){
                int number;
                cin >> number;
                A.push_back(number);
            }
            for(int i = 0; i < L; i++){
                int number;
                cin >> number;
                B.push_back(number);
            }
            cin >> HP;

            AHP = HP;
            BHP = HP;

            cin >> Mlocate >> Nlocate;

            Alocation[0][0] = Mlocate;
            Alocation[0][1] = Nlocate;

            Blocation[0][0] = Mlocate;
            Blocation[0][1] = Nlocate;

            int gameOrder = 1;

            while(true){
                if(gameOrder == 1) {
                    int gameNumber = 1;
                    bool check = false;
                    for (int i = 0; i < 2; i++) {
                        int number = A.front();
                        A.pop_front();
                        gameNumber *= number;
                        A.push_back(number);
                    }

                    int low = 0;
                    int high = M * N - 1;
                    int mid;

                    while(low <= high) {
                        mid = (low + high) / 2;

                        game = gameBoard[mid];

                        if(game.value > gameNumber) high = mid - 1;
                        else if(game.value < gameNumber) low = mid + 1;
                        else {
                            if (Alocation[0][0] > game.location.first) Alocation[0][0] -= game.location.first;
                            else if (Alocation[0][0] <= game.location.first) Alocation[0][0] = game.location.first - Alocation[0][0];
                            if (Alocation[0][1] > game.location.second) Alocation[0][1] -= game.location.second;
                            else if (Alocation[0][1] <= game.location.second) Alocation[0][1] = game.location.second - Alocation[0][1];

                            AHP -= Alocation[0][0] + Alocation[0][1];

                            Alocation[0][0] = game.location.first;
                            Alocation[0][1] = game.location.second;

                            check = true;

                            break;
                        }
                    }

                    if(AHP <= 0){
                        cout << "A" << endl;
                        break;
                    }
                    gameOrder = 2;
                }

                else if(gameOrder == 2) {
                    int gameNumber = 1;
                    bool check = false;
                    for (int i = 0; i < 2; i++) {
                        int number = B.front();
                        B.pop_front();
                        gameNumber *= number;
                        B.push_back(number);
                    }


                    int low = 0;
                    int high = M * N - 1;
                    int mid;

                    while(low <= high) {
                        mid = (low + high) / 2;

                        game = gameBoard[mid];

                        if(game.value > gameNumber) high = mid - 1;
                        else if(game.value < gameNumber) low = mid + 1;
                        else {
                            if (Blocation[0][0] > game.location.first) Blocation[0][0] -= game.location.first;
                            else if (Blocation[0][0] <= game.location.first) Blocation[0][0] = game.location.first - Blocation[0][0];
                            if (Blocation[0][1] > game.location.second) Blocation[0][1] -= game.location.second;
                            else if (Blocation[0][1] <= game.location.second) Blocation[0][1] = game.location.second - Blocation[0][1];

                            BHP -= Blocation[0][0] + Blocation[0][1];

                            Blocation[0][0] = game.location.first;
                            Blocation[0][1] = game.location.second;

                            check = true;

                            break;
                        }
                    }
                    if(BHP <= 0) {
                        cout << "B" << endl;
                        break;
                    }
                     gameOrder = 1;
                }
            }


        }

    }
}