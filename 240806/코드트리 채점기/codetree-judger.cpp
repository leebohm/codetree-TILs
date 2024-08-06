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
    int cnt = 0;
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
            
            if(pq_machine.empty() == true){
                // 쉬고 있는 채점기가 없다면 무시하고 넘어간다. 
                continue; 
            }

            if(waiting_pq.empty() == true){ // 기다리고 있는 task가 없다면 pass
                continue;
            }

            int num = pq_machine.top(); pq_machine.pop();
            num = -num; // 음수 전환
        
            string url_tmp; int a,b;

            tie(a,b,url_tmp) = waiting_pq.top();  
            priority_queue<tuple<int,int,string>> waiting_pq_tmp;  // 기록 용도 
            
            // 채점이 될 수 있는 조건인지 아닌지 확인
            size_t pos = url_tmp.find('/'); // '/'의 위치를 찾기.
            
            // '/'가 발견되면 그 이전까지의 부분 문자열을 str1에 저장
            string domain = url_tmp.substr(0, pos);

            bool flag = false;
            
            while(flag == false){
                if(waiting_pq.empty() == true)
                    break;
                else if(history.find(domain) != history.end()){ // history에 최근에 작업한 domain이야?
                    int tmp = history[domain];
                    if(t<tmp){ // 채점 불가. 
                        waiting_pq.pop();
                        waiting_pq_tmp.push({a,b,url_tmp}); // 채점 불가하므로 일단 pq_tmp에 넣어놓기. 
                        tie(a,b,url_tmp) = waiting_pq.top();
                        pos = url_tmp.find('/'); 
                        domain = url_tmp.substr(0, pos); // 다음 우선순위로 domain 업데이트 
                    }
                    else{
                        waiting_pq.pop();
                        flag = true;
                    }
                }
                else if(judging.find(domain) != judging.end()){ // 현재 작업중인 domain 중에 있어? 
                    // 채점 불가 
                    waiting_pq.pop();
                    waiting_pq_tmp.push({a,b,url_tmp}); // 채점 불가하므로 일단 pq_tmp에 넣어놓기. 
                    tie(a,b,url_tmp) = waiting_pq.top();
                    pos = url_tmp.find('/'); 
                    domain = url_tmp.substr(0, pos); // 다음 우선순위로 domain 업데이트 
                }
                else{
                    waiting_pq.pop();
                    flag = true;
                }
            } 

            // 이제 채점 시도. 
            if(flag == true){
                waiting_s.erase(url_tmp);
                machine[num] = {url_tmp,t}; 
                judging.insert(domain);
            }
            else if(flag == false){
                pq_machine.push(-num);
            }

            while(waiting_pq_tmp.empty() == false){
                tie(a,b,url_tmp) = waiting_pq_tmp.top(); waiting_pq_tmp.pop();
                waiting_pq.push({a,b,url_tmp});
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
            cnt++;
            cin >> t;
            if(waiting_pq.empty() == true)
                cout << 0 << endl;
            else{
                int tmp = (int) waiting_s.size();
                cout << tmp << endl;
            }
        }
        /*
        if(i>=115){
            cout << "i : " << i << endl;
            cout << "waiting_s size : " << (int) waiting_s.size() << endl;
            cout << "judging size : " << (int) judging.size() << endl;
            cout << "hisotry size : " << (int) history.size() << endl;
        }

        cout <<" i : " << i << " opt : " << opt << endl;
        Print_waiting_s();
        Print_judging();
        PrintHistory();
        */

    }

    
    return 0;
}