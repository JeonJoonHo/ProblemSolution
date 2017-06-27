#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool predicate(pair<int, int> cmp1, pair<int, int> cmp2) {
    if (cmp1.first == cmp2.first)
        return cmp1.second < cmp2.second;
    return cmp1.first < cmp2.first;
}
bool predicate1(pair<int, int> cmp1, pair<int, int> cmp2){
    if (cmp1.first == cmp2.first)
        return cmp1.second > cmp2.second;
    return cmp1.first > cmp2.first;
}

bool predicate2(pair<int, int> cmp1, pair<int, int> cmp2){
    if (cmp1.second == cmp2.second)
        return cmp1.first > cmp2.first;
    return cmp1.second < cmp2.second;
}

bool predicate3(pair<int, int> cmp1, pair<int, int> cmp2) {
    if (cmp1.second == cmp2.second)
        return cmp1.first < cmp2.first;
    return cmp1.second > cmp2.second;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, result, x, y, temp;
        result = 0;

        cin >> N >> M;

        vector<pair<int, int>> location(M);

        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            location[i].first = x;
            location[i].second = y;
        }

        if (N == 45) {
            sort(location.begin(), location.end(), predicate);
            while (location.size() != 1) {
                for (int k = 0; k < location.size() - 1; k++) {
                    if (location[k].second <= location.back().second)
                        result++;
                }
                location.pop_back();
            }
        }
        else if (N == 90) {
            sort(location.begin(), location.end(), predicate);
            location.resize(M + 1);
            location[M].first = -1;
            location[M].second = -1;
            result = M * (M - 1) / 2;
            temp = 1;
            for (int i = 0; i < M; i++) {
                if (location[i].first == location[i + 1].first)
                    temp++;
                else {
                    result += temp * (temp - 1) / 2;
                    temp = 1;
                }
            }
        }
        else if (N == 135) {
            sort(location.begin(), location.end(), predicate3);
            while (location.size() != 1) {
                for (int k = 0; k < location.size() - 1; k++) {
                    if (location[k].first <= location.back().first)
                        result++;
                }
                location.pop_back();
            }
        }
        else if (N == 180) {
            sort(location.begin(), location.end(), predicate3);
            location.resize(M + 1);
            location[M].first = -1;
            location[M].second = -1;
            result = M*(M - 1) / 2;
            temp = 1;
            for (int i = 0; i < M; i++) {
                if (location[i].second == location[i + 1].second)
                    temp++;
                else {
                    result += temp * (temp - 1) / 2;
                    temp = 1;
                }
            }
        }
        else if (N == 225) {
            sort(location.begin(), location.end(), predicate1);
            while (location.size() != 1) {
                for(int k = 0; k < location.size() - 1; k++) {
                    if (location[k].second >= location.back().second)
                        result++;
                }
                location.pop_back();
            }
        }
        else if (N == 270) {
            sort(location.begin(), location.end(), predicate1);
            location.resize(M + 1);
            location[M].first = -1;
            location[M].second = -1;
            result = M*(M - 1) / 2;
            temp = 1;
            for (int i = 0; i < M; i++) {
                if (location[i].first == location[i + 1].first)
                    temp++;
                else {
                    result += temp * (temp - 1) / 2;
                    temp = 1;
                }
            }
        }
        else if (N == 315) {
            sort(location.begin(), location.end(), predicate3);
            while (location.size() != 1) {
                for (int k = 0; k < location.size() - 1; k++) {
                    if (location[k].first <= location.back().first)
                        result++;
                }
                location.pop_back();
            }
        }
        else if (N == 360) {
            sort(location.begin(), location.end(), predicate2);
            location.resize(M + 1);
            location[M].first = -1;
            location[M].second = -1;
            result = M*(M - 1) / 2;
            temp = 1;
            for (int i = 0; i < M; i++) {
                if (location[i].second == location[i + 1].second)
                    temp++;
                else {
                    result += temp * (temp - 1) / 2;
                    temp = 1;
                }
            }
        }
        cout << result << endl;

    }
}