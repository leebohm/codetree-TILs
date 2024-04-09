#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
int n;
priority_queue<pair<int,int>> pq;
int score, t;
vector<pair<int,int> > vec;

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> score >> t;
        pq.push(make_pair(-t,score));
    }

    int curr_time = 0;
    int total_score = 0;

    while(pq.empty() == false){
        tie(t,score) = pq.top();
        t = -t;
        if(curr_time < t){
            pq.pop();
            total_score += score;
            curr_time++;
        }
        else{
            pq.pop();
        }
        
    }
    cout << total_score;
    // 여기에 코드를 작성해주세요.
    return 0;
}