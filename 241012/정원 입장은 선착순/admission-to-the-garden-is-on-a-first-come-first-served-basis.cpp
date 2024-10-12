#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Person {
    int arrival;   // 도착 시간
    int duration;  // 머무르는 시간
    int id;        // 번호표 (사람 번호)
};

// 우선순위 큐를 위한 비교 함수 (번호가 작은 사람 우선)
struct Compare {
    bool operator()(const Person& p1, const Person& p2) {
        return p1.id > p2.id;
    }
};

int main() {
    int N;
    cin >> N;

    vector<Person> people(N);
    for (int i = 0; i < N; ++i) {
        int a, t;
        cin >> a >> t;
        people[i] = {a, t, i + 1}; // i+1 은 사람의 번호
    }

    // 우선순위 큐: 번호가 작은 사람부터 우선 입장
    priority_queue<Person, vector<Person>, Compare> pq;

    long long current_time = 0;  // 정원에 들어갈 수 있는 현재 시점
    long long max_wait_time = 0; // 가장 오래 기다린 시간

    int i = 0; // 사람을 관리하기 위한 인덱스
    while (i < N || !pq.empty()) {
        // 1. 정원이 비었고, 도착한 사람이 있으면 그 사람을 우선순위 큐에 넣음
        if (i < N && people[i].arrival <= current_time) {
            pq.push(people[i]);
            i++;
            continue;
        }

        // 2. 정원에 사람이 없으면 우선순위 큐에서 가장 번호가 작은 사람을 꺼냄
        if (!pq.empty()) {
            Person next_person = pq.top();
            pq.pop();
            // 대기 시간 계산
            long long wait_time = current_time - next_person.arrival;
            max_wait_time = max(max_wait_time, wait_time);
            // 정원에 들어가고 나가는 시간 업데이트
            current_time += next_person.duration;
        } else {
            // 3. 아무도 정원에 들어갈 수 없는 경우 현재 시간을 다음 사람의 도착 시간으로 이동
            if (i < N) {
                current_time = people[i].arrival;
            }
        }
    }

    cout << max_wait_time << endl;
    
    return 0;
}