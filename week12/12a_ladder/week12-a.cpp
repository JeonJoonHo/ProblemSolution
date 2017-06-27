#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int T;

    cin >> T;

    while(T--) {
        vector< pair<int, int> > level;
        int N, levels, startNumber, ring;

        cin >> N >> levels;

        for(int i = 0; i < levels; i++) {
            int number;
            cin >> number;

            pair<int, int> temp = make_pair(number, number+1);

            level.push_back(temp);
        }

        cin >> startNumber >> ring;

        int start = startNumber;
        int end = ring;

        int* store = new int[levels];

        int result = 0;

        for(int i = levels - 1; i >= 0; i--) {
            store[i] = end;
            if (level[i].first == end) {
                end++;
            }
            else if (level[i].second == end){
                end--;
            }
        }

        for(int i = 0; i < levels; i++) {
            if (level[i].first == start) {
                start++;
            }
            else if (level[i].second == start){
                start--;
            }
            if (start - store[i] == 1 || start - store[i] == -1) {
                if (i != levels - 1) {
                    result = 1;
                    break;
                }
            }
        }

        cout << result << endl;

        delete[] store;
    }
}