#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int card[202][202] = {0,};
vector<string> tokens;
vector<string>::iterator tokens_it;

void Tokenize(const string &str, vector<string> &tokens, const string &delimiters = " ") {
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int T;

    cin >> T;

    while (T--) {
        int N, M, total;


        cin >> N >> M;
        string str;
        getline(cin, str);
        total = 2 * N - 1;
        for (int i = 1; i <= M; ++i) {
            getline(cin, str);
            Tokenize(str, tokens, " ");
            for (tokens_it = tokens.begin(); tokens_it != tokens.end(); tokens_it++) {
                if (card[i][atoi(tokens_it->c_str())] == 1) {
                    card[i][atoi(tokens_it->c_str())] = 0;
                    total -= 2;
                    --card[i][0];
                } else {
                    card[i][atoi(tokens_it->c_str())] = 1;
                    ++card[i][0];
                }
            }
            tokens.clear();
        }

        while (true) {
            for (int i = 1; i <= M; i++) {
                if (total == 1) {
                    break;
                }
                if (card[i][0] == 0) {
                    continue;
                }
                int j = i;
                while (true) {
                    j = (j + 1) % (M + 1);
                    if (card[j][0] == 0) {
                        continue;
                    }
                    if (card[j][0] <= i) {
                        for (int k = N; k >= 0; k--) {
                            if (card[j][k] == 1) {
                                card[j][k] = 0;
                                card[j][0]--;
                                if (card[i][k] == 1) {
                                    card[i][k] = 0;
                                    card[i][0]--;
                                    total -= 2;
                                } else {
                                    card[i][k] = 1;
                                    card[i][0]++;
                                }
                                break;
                            }
                        }
                    } else {
                        int count = 0;
                        for (int k = 1; k <= N; k++) {
                            if (card[j][k] == 1) {
                                ++count;
                                if (count == i) {
                                    card[j][k] = 0;
                                    card[j][0] -= 1;
                                    if (card[i][k] == 1) {
                                        card[i][k] = 0;
                                        card[i][0]--;
                                        total -= 2;
                                    } else {
                                        card[i][k] = 1;
                                        card[i][0]++;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    break;
                }
            }
            if (total == 1) {
                break;
            }
        }
        for (int i = 1; i <= M; i++) {
            if (card[i][0] != 0) {
                cout << i << endl;
                card[i][0] = 0;
                for (int j = 1; j <= N; j++) {
                    if (card[i][j] != 0) {
                        card[i][j] = 0;
                    }
                }
            }
        }
    }
}