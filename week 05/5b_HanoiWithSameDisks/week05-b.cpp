#include <iostream>
#include <list>
using namespace std;

int cnt, T, fin;
list<int> result;

void moveHanoi(int n,int from,int to, int *hanoi) {
    int c;

    if(cnt == fin){
        return ;
    }
    else {
        if (n <= 1) {
            for (int i = 0; i < hanoi[n]; i++) {
                if (cnt == fin) {
                    return;
                }
                if (to == 2) {
                    result.push_front(n);
                } else if (from == 2) {
                    result.pop_front();
                }
                cnt++;
            }
        } 
	else {
            c = 6 - from - to;
            moveHanoi(n - 1, from, c, hanoi);

            for (int i = 0; i < hanoi[n]; i++) {
                if (cnt == fin) {
                    return;
                }
                if (to == 2) {
                    result.push_front(n);
                } else if (from == 2) {
                    result.pop_front();
                }
                cnt++;
            }
            moveHanoi(n - 1, c, to, hanoi);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> T;

    int testcase = 0;
    while(true) {
        int hanoi[11] = { 0 };
        cnt = 0;
        int circleNumber;
        result.clear();

        cin >> circleNumber;

        for(int i = 1; i <= circleNumber; i++){
            cin >> hanoi[i];
        }

        cin >> fin;

        moveHanoi(circleNumber, 1, 3, hanoi);

        if(result.empty()){
            cout << 0 << endl;
        }
        else {
            result.sort();
            list<int>::iterator iter;
            cout << endl;
            for (iter = result.begin(); iter != result.end(); iter++){
                cout << *iter << ' ';
            }
        }
        testcase++;
        if(T == testcase){
            break;
        }
    }
}