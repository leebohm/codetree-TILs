#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define INF 1987654321
#define MAX_N 50000
#define MAX_D 300

int q;
int n;

set<int> is_in_readyq[MAX_D+1];

priority_queue<int,vector<int>, greater<int>> rest_judger;

int judging_domain[MAX_N+1];

int s[MAX_D+1];
int g[MAX_D+1];
int e[MAX_D+1];

map<string,int> domainToIdx;
int cnt;

int ans;

struct Url{
    int tme,id;
    int num;

    bool operator<(const Url&b) const{
        if(id !=b.id) return id > b.id;
        return tme > b.tme;
    }
};

priority_queue<Url> url_pq[MAX_D+1];

void Init(){
    string url;
    cin >> n >> url;

    for(int i=1; i<=n; i++) rest_judger.push(i);

    int idx = 0;
    size_t pos = url.find('/');
    
    string domain = url.substr(0,pos);
    int num = stoi(url.substr(pos+1));

    if(!domainToIdx[domain]){
        cnt++;
        domainToIdx[domain] = cnt;
    }
    int domain_idx = domainToIdx[domain];

    is_in_readyq[domain_idx].insert(num);

    Url newUrl;
    newUrl.tme = 0;
    newUrl.id = 1;
    newUrl.num = num;
    url_pq[domain_idx].push(newUrl);

    ans++;
}


void NewUrl(){
    int tme, id;
    string url;
    cin >> tme >> id >> url;

    size_t pos = url.find('/');

    string domain = url.substr(0,pos);
    int num = stoi(url.substr(pos+1));

    if(!domainToIdx[domain]){
        cnt++;
        domainToIdx[domain] = cnt;
    }

    int domain_idx = domainToIdx[domain];
    if(is_in_readyq[domain_idx].find(num)!=is_in_readyq[domain_idx].end()){
        return;
    }

    is_in_readyq[domain_idx].insert(num);

    Url newUrl;
    newUrl.tme = tme;
    newUrl.id = id;
    newUrl.num = num;
    url_pq[domain_idx].push(newUrl);

    ans++;

}

void Assign(){
    int tme;
    cin >> tme;

    if(rest_judger.empty()) return;

    int min_domain = 0;
    Url minUrl;
    minUrl.id = INF;

    for(int i=1; i<=cnt ;i++){
        if(e[i] > tme) continue;

        if(!url_pq[i].empty()){
            Url curUrl = url_pq[i].top();

            if(minUrl < curUrl){ // 우선순위 높은 것, < 는 내 id가 상대방보다 크면 내가 작은것. 
                minUrl = curUrl; // 상대방이 나보다 id 작으면 내가 작은것.
                min_domain = i; // 우선순위 제일 높은 것인데 왜 min으로 햇을까.. 아무튼id 제일작은것
            }
        }
    }

    if(min_domain){
        int judger_idx = rest_judger.top(); rest_judger.pop();

        url_pq[min_domain].pop();

        s[min_domain] = tme;
        e[min_domain] = INF;

        judging_domain[judger_idx] = min_domain;

        is_in_readyq[min_domain].erase(is_in_readyq[min_domain].find(minUrl.num));

        ans--;
    }
}

void Finish(){
    int tme, id;
    cin >> tme >> id;

    if(judging_domain[id] == 0) return;

    rest_judger.push(id);
    int domain_idx = judging_domain[id];
    judging_domain[id] = 0;

    g[domain_idx] = tme-s[domain_idx];
    e[domain_idx] = s[domain_idx] + 3*g[domain_idx];
}

void Check(){
    int tme;
    cin >> tme;
    cout << ans <<"\n";
}

int main(){
    cin >> q;
    while(q--){
        int query;
        cin >> query;

        if(query == 100){
            Init();
        }
        if(query == 200){
            NewUrl();
        }
        if(query == 300){
            Assign();
        }
        if(query == 400){
            Finish();
        }
        if(query == 500){
            Check();
        }
    }
}