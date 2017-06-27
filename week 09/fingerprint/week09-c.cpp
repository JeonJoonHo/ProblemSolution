#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--) {
        int result = 0;

        vector<pair<int, int>> create;
        vector<pair<int, int>> compare;
        bool createTable[1001][1001] = {0, };

        int createNumber;
        cin >> createNumber;
        for (int i = 0; i < createNumber; i++) {
            int x, y;
            cin >> x >> y;

            pair<int, int> add = make_pair(x,y);

            create.push_back(add);
            createTable[x][y] = true;
        }

        int compareNumber;
        cin >> compareNumber;

        for (int i = 0; i < compareNumber; i++) {
            int x, y;
            cin >> x >> y;

            pair<int, int> add = make_pair(x,y);

            compare.push_back(add);
        }

        int temp1_x, temp1_y;

        for(int a = 0; a < createNumber; a++) {
            for (int i = 0; i < createNumber; i++) {
                temp1_x = create[a].first - compare[i].first;
                temp1_y = create[a].second - compare[i].second;

                int trueCount = 0;
                int falseCount = 0;

                for(int k = 0; k < compareNumber; k++) {
                    int index = 0;
                    int temp2_x, temp2_y;

                    temp2_x = compare[k].first + temp1_x;
                    temp2_y = compare[k].second + temp1_y;

                    if (temp2_x < 0 || temp2_y < 0 || temp2_x > 1000 || temp2_y > 1000) {
                        falseCount++;
                    }
                    else if (createTable[temp2_x][temp2_y] == false) {
                        falseCount++;
                    }
                    else trueCount++;

                    if (falseCount > createNumber * 0.1) {
                        break;
                    }
                    else if (trueCount >= createNumber * 0.9){
                        result = 1;
                        break;
                    }
                }
            }
        }

        cout << result << endl;
    }

}
