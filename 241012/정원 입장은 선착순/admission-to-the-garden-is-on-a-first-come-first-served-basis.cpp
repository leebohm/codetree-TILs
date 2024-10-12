#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
tuple<int, int, int> people[MAX_N + 1];
priority_queue<tuple<int, int, int> > pq;  

int ans;

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> t;

        // 이후 정원에 먼저 도달한 사람이
        // 앞에 나올 수 있도록 a, 번호, t 순으로 넣어줍니다.
        // 두 번째 위치에
        // 번호를 넣어주는 이유는
        // 나중에 여러 사람이 기다릴 때
        // 가장 번호가 작은 사람을 뽑기 위해서 입니다.
        people[i] = make_tuple(a, i + 1, t); 
    }

    // 구현 편의상 마지막 사람을 한 명 더 추가해줍니다.
    people[n] = make_tuple(INT_MAX, n + 1, 0);

    // 정렬을 진행합니다.
    sort(people, people + n + 1);

    // 정원에 도착한 순서대로 사람들을 보며
    // 현재 정원에 있는 사람이 언제 나오게 되는지를 계속 계산해줍니다.
    // 이때 우선순위 큐를 이용하여 기다리고 있는 사람들의 정보를 관리하여
    // 정원에서 사람이 나온 즉시 기다리던 사람 중 
    // 번호가 가장 작은 학생이 바로 들어갈 수 있도록 합니다.
    // 번호가 작은 학생이 먼저 나오기 위해
    // 최솟값이 나오는 우선순위 큐가 필요하므로
    // -를 붙여줘야함에 유의합니다.
    int exit_time = 0;
    for(int i = 0; i <= n; i++) {
        // 각 사람을 순서대로 입장시킵니다.
        int a, num, t;
        tie(a, num, t) = people[i];

        // 지금 입장한 사람보다
        // 현재 정원에서 빠져나오는 사람의 시간이 더 앞서다면
        // 계속 정원 입장을 진행해줍니다.
        while(a > exit_time && !pq.empty()) {
            // 기다리던 사람 중에 가장 우선순위가 높은 사람을 골라줍니다.
            int next_a, next_t;
            tie(ignore, next_a, next_t) = pq.top();
            pq.pop();

            // 해당 사람이 얼마나 기다렸는지를 계산하여
            // 최댓값을 갱신해줍니다.
            ans = max(ans, exit_time - next_a);
            // 연속하여 일어난 일이므로
            // 그 다음 사람의 정원 퇴장 시간은
            // next_t만큼 더해진 값이 됩니다.
            exit_time += next_t;
        }

        // 계속 정원 입장을 진행했음에도
        // 지금 입장한 사람이 대기 없이 들어갈 수 있다면
        // 우선순위 큐에 넣지 않고 바로 정원에 입장시킵니다.
        if(a > exit_time)
            exit_time = a + t;
        // 그렇지 않다면
        // 대기 리스트에 넣어줍니다.
        else
            pq.push(make_tuple(-num, a, t));
    }

    cout << ans;
    return 0;
}