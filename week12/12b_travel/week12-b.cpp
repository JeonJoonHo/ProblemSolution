#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_SIZE 9999999

int travelNumber[10001];
int moveCheck[10001];
long long int result;

priority_queue<pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > que;
vector< pair<int, int> > bus[10001];

void move(int index){
    moveCheck[index] = 1;

    for(auto item : bus[index]){
        if(moveCheck[item.second] == 0 && travelNumber[item.second] > item.first){
            travelNumber[item.second] = item.first;
            que.push( pair<int,int>(travelNumber[item.second],item.second) );
        }
    }

    int nextCity;
    while(!que.empty()){
        if(moveCheck[que.top().second] == 0){
            nextCity = que.top().second;
            result += que.top().first;
            que.pop();
            move(nextCity);
        }
        else{
            que.pop();
        }
    }

    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, N, M;
    cin >> T;

    while(T--){
        result = 0;

        for(int i = 0; i < 10001; i++){
            bus[i].clear();
        }
        
        cin >> N >> M;

        fill(travelNumber, travelNumber+10001, MAX_SIZE);

        int city1, city2, time;
        for(int i = 0; i < M; i++){
            cin >> city1 >> city2 >> time;
            
            pair<int, int> temp = make_pair(time,city2);
            bus[city1].push_back(temp);

            pair<int, int> temp1 = make_pair(time,city1);
            bus[city2].push_back(temp1);

            moveCheck[city1] = 0;
            moveCheck[city2] = 0;
        }

        move(0);

        cout << result << endl;
    }
}