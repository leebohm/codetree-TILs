#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <tuple>

#define MAX_N 50001 // 채점기의 수 
using namespace std;

int q; // 명령의 수 
int n; // 채점기의 수 

string u;
int t,p,jid;
priority_queue<tuple<int,int,string>> waiting_pq; // -우선순위, -시간, url
pair<string,int> machine[MAX_N]; // index : 채점기 번호, value : 채점할 url, start(시작시간)
priority_queue<int> pq_machine;
map<string,int> history;
set<string> judging;
set<string> waiting_s;

void Print_waiting_s(){
    cout <<"waiting_s" << endl;
    set<string>::iterator it;
    for(it= waiting_s.begin(); it!=waiting_s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void PrintHistory(){
    cout <<"history" <<  endl;
    map<string,int>::iterator it;
    for(it= history.begin(); it!=history.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

void Print_judging(){
    cout << "judging " << endl;
    set<string>::iterator it;
    for(it= judging.begin(); it!= judging.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main() {

    cin >> q;
    for(int i=0; i<q; i++){

        int opt;
        cin >> opt;
        
        if(opt == 100){ // 코드트리 채점기 준비 
            cin >> n >> u;
            waiting_pq.push({-1,0,u});
            waiting_s.insert(u); // 대기큐에는 중복 url이 들어오면 안되니까!
            
            for(int i=1; i<=n; i++)
                pq_machine.push(-i); // 가장 번호가 작은 쉬고 있는 채점기를 찾기 위함

        }
        else if(opt == 200){ // 채점 요청
            cin >> t >> p >> u;
            if(waiting_s.find(u) == waiting_s.end()){
                // 대기큐 셋에 없다면
                waiting_s.insert(u);
                waiting_pq.push({-p,-t,u}); // 우선순위, t, url 순으로 대기 큐에 넣기!
            }
            
        }
        else if(opt == 300){  // 채점 시도
            cin >> t; 
            
            if(pq_machine.empty() == true) // 쉬고 있는 채점기가 없다면 무시하고 넘어간다. 
                continue; 
            int num = pq_machine.top(); // 채점기도 아직 Pop 하지는 않음. 
            num = -num; // 음수 전환
        
            string url_tmp;
            if(waiting_pq.empty() == true) // 기다리고 있는 task가 없다면 pass
                continue;
            tie(ignore,ignore,url_tmp) = waiting_pq.top();  // 아직pop 하지는 않음! 
            
            // 채점이 될 수 있는 조건인지 아닌지 확인
            size_t pos = url_tmp.find('/'); // '/'의 위치를 찾기.
            
            // '/'가 발견되면 그 이전까지의 부분 문자열을 str1에 저장
            string domain = url_tmp.substr(0, pos);

            if(history.find(domain) != history.end()){
                // 기존의 도메인에 대해 판단 
                // t가 start + 3*gap 보다 작으면 채점 불가 . 
                int tmp = history[domain];
                if(t<tmp)
                    continue;
            }
            if(judging.find(domain) == judging.end()){ 
                pq_machine.pop(); // 채점기 실행. 
                waiting_pq.pop(); // 가장 우선순위 높은 task 꺼냄
                waiting_s.erase(url_tmp);

                // history에 있어도 조건에 안 맞고, 현재 진행중인 task중에 동일한 domain이 없다면 채점 시작.
                machine[num] = {url_tmp,t}; // 채점 시작 
                judging.insert(domain);
            }
        }

        else if(opt == 400){ // 채점 종료 
            cin >> t >> jid;

            if(machine[jid].first == "") // jid번 채점기가 진행하던 채점이 없다면 명령 무시된다.
                continue;
            string url_tmp= "";
            int start = 0;
            tie(url_tmp, start) = machine[jid]; // 채점했던 url과 시작 시간
            machine[jid] = {"",-1};
            size_t pos = url_tmp.find('/');
            string domain = url_tmp.substr(0,pos);

            history[domain] = start+3*(t-start); // history에 도메인과 채점요청조건인 시간 삽입. 
            judging.erase(domain);
            pq_machine.push(-jid); // 채점 끝났으니 채점기 pq에 넣어 주기. 
            
        }
        else if(opt == 500){ // 채점 대기 큐 조회
            cin >> t;
            //cout << "i : " << i << endl;
            if(waiting_pq.empty() == true)
                cout << 0 << endl;
            else{
                int tmp = (int) waiting_s.size();
                cout << tmp << endl;
            }
        }

        /*
        Print_waiting_s();
        Print_judging();
        PrintHistory();
        */
    }

    
    return 0;
}

/*

1) 코드트리 채점기 
문제 url : 도메인/문제id 
도메인 : 알파벳 소문자 & . 
문제 id : 1~ 10억 이하 
n 개의 채점기 1~n번
0초에 채점 우선순위가 1이면서 urldl u0인 초기 문제에대한 채점 요청이 들어온다. 

2) 채점 요청
t초에 채점 우선순위가 p이면서 url이 u인 문제에 대한 채점 요청이 들어오게 된다.
채점 task는 채점 대기 큐에 들어가게된다. 
단, 채점 대기 큐에 있는 task 중 정확히 u와 일치하는 url이 단 하나라도 존재한다면 큐에 추가하지 않고 넘어감

3) 채점 시도
t초에 채점 대기 큐에서 즉시 채점이 불가능한 경우를 제외하고 
남은 task 중 우선순위가 가장 높은 채점 task를 골라 채점을 진행한다 

채점이 될 수 없는 조건
- 해당 task의 도메인이 현재 채점을 진행중인 도메인 중 하나라면 불가능. 
- 해당 task의 도메인과 정확히 일치하는 도메인에 대해 
가장 최근에 진행된 채점 시작 시간이 start, 종료 시간이 start+gap였고, 
현재 시간 t가 start + 3*gap 보다 작다면 부적절한 채점이라 의심, 채점 불가. 

우선순위 높은 task 의 조건
- 채점 우선순위 p의 번호가 작을수록 우선순위 높다. 
- 우선순위 동일할 때 , 채점 task가 채점 대기 큐에 들어온 시가닝 더 빠를수록 우선순위가 높다 

t초에 채점이 가능한 task 단 하나라도 있다면 쉬고 있는 채점기 중 
가장 작은 번호의 채점기가 우선순위 가장 높은 task에 대한 채점 시작. 
- 쉬고 있는 채점기 없다면 요청을 무시하고 넘어간다. 

4) 채점 종료
t초에 jid번 채점기가 진행하던 채점이 종료된다. 
jid 채점기는 다시 쉬는 상태가 된다.
jid 번 채점기가 진행하던 채점이 없었다면 이 명령은 무시된다.

5) 채점 대기 큐 조회
시간 t에 채점 대기 큐에 있는 task의 수를 출력

*/