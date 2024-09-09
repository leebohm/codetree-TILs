#include <iostream>
#include <unordered_map>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_N 100002
#define MAX_P 2002

int q; // 명령의 수 
int opt; // 명령 조건
int n,m; // n*m 보드의 넓이 
int p; // 토끼의 수 
//int board[MAX_N][MAX_N];
unordered_map<int,int> pid2dist; // pid -> dist
unordered_map<int,int> score; // 고유번호 -> 토끼 점수
int pid[MAX_P];
priority_queue<tuple<int,int,int,int,int>> pq1; // 우선순위 높은 토끼 결정 
int k,s; // k 번의 턴 진행, k번의 턴이 모두 진행된 직후 가장 우선순위가 높은 토끼를 골라 점수 s를 더해주게 된다
pair<int,int> pos[MAX_P]; // 고유번호-> 포즈
unordered_map<int,int> pid2idx;

int dx[4] = {1,-1,0,0}; // 상하좌우
int dy[4] = {0,0,-1,1};

bool InRange(int x, int y){
    return x>=1 && x <=n && y>=1 && y<=m;
}

pair<int,int> Decision_pos(int num,int r, int c){
    priority_queue<tuple<int,int,int>> pq2; // 우선순위 높은 위치 결정
    int dist = pid2dist[num];
    int nx,ny;
    for(int i=0; i<4; i++){
        if(i == 0 && i ==1)
            dist = dist % (n+1);
        else if(i == 2 && i ==3)
            dist = dist % (m+1);
        int dir_tmp = i;
        int tmp_r = r;
        int tmp_c = c;
        for(int j=0; j<dist; j++){ // 나누기!
            nx = tmp_r+dx[dir_tmp];
            ny = tmp_c+dy[dir_tmp];
            if(InRange(nx,ny) == false){ 
                if(dir_tmp == 0){
                    dir_tmp = 1;
                    nx = tmp_r + dx[dir_tmp];
                    ny = tmp_c + dy[dir_tmp];
                }
                else if(dir_tmp== 1){
                    dir_tmp = 0;
                    nx = tmp_r + dx[dir_tmp];
                    ny = tmp_c + dy[dir_tmp];
                }
                else if(dir_tmp == 2){
                    dir_tmp = 3;
                    nx = tmp_r + dx[dir_tmp];
                    ny = tmp_c + dy[dir_tmp];
                }
                else if(dir_tmp == 3){
                    dir_tmp = 2;
                    nx = tmp_r + dx[dir_tmp];
                    ny = tmp_c + dy[dir_tmp];
                }
            }
            tmp_r = nx; tmp_c = ny;
        }
        pq2.push(make_tuple(nx+ny,nx,ny));
    }
    int nr,nc;
    tie(ignore,nr,nc) = pq2.top();
    pair<int,int> ret_p = make_pair(nr,nc);
    return ret_p;
}

int main() {
    
    cin >> q;

    for(int i=0;i<q; i++){
        cin >> opt;

        if(opt == 100){
            cin >>  n >> m >> p;
            for(int j=1; j<=p;j++){
                int num, dist;
                cin >> num >> dist; // 고유 번호, 고유 거리 입력받기
                pid[j] = num; pid2idx[num] = j;
                pid2dist[num] = dist;
                pos[num] = make_pair(1,1);
                pq1.push(make_tuple(0,-(1+1),-1,-1,-num));
                score[pid[j]] = 0;
            }
        }

        else if(opt == 200){
            cin >> k >> s;
            unordered_map<int,int> cnt_bunny;
            for(int j=0; j<k; j++){
                // 1. 가장 우선 순위 높은 토끼 결정하기 
                int cnt,bunny,r,c;
                tie(cnt,ignore,r,c,bunny) = pq1.top();
                pq1.pop();
                cnt = -cnt; r = -r; c = -c; bunny = -bunny;
                cnt_bunny[bunny]++;

                // 2. 이동할 위치 결정하기 
                int nr,nc;
                tie(nr,nc) = Decision_pos(bunny,r,c);
                //cout << j << "번째 : " << bunny << " " << nr << " " << nc << endl;

                // 3. 우선순위가 가장 높은 칸으로 이동시키기 
                cnt++; // 점프횟수 증가시키기
                pq1.push(make_tuple(-cnt,-(nr+nc),-nr,-nc,-bunny));
                pos[bunny] = make_pair(nr,nc);
                // 4. 나머지 토끼 점수 올리기. 
                for(int t = 1; t <=p; t++){
                    if(pid[t] != bunny){
                        score[pid[t]] += (nr+nc);
                    }
                }
            }

            // 5. k번의 턴이 모두 진행된 후 우선 순위가 가장 높은 토끼를 골라 점수 s를 더해주기 
            // i) 우선순위 큐에 추가해주기 
            priority_queue<tuple<int,int,int,int>> pq3;
            for(int t = 1;t<=p; t++){
                int r,c;
                tie(r,c) = pos[pid[t]];
                pq3.push(make_tuple(r+c,r,c,pid[t]));
            }
            // ii) 우선순위 가장 높은 토끼를 골라 점수 더해주기
            int num;
            while(pq3.empty() == false){
                tie(ignore,ignore,ignore,num) = pq3.top();
                if(cnt_bunny[num]== 0){
                    pq3.pop();
                }
                else{
                    score[num] += s;
                    break;
                }
            }
            
        }

        else if(opt == 300){
            int pid_t,l;
            cin >> pid_t >> l;
            pid2dist[pid_t] *= l; // 원래 거리에 l배 해준다 
        }
        
        else if(opt == 400){
            // 최고의 토끼 선정, 가장 높은 토끼의 점수 
            int ans = 0;
            for(int t =1;t<=p; t++){
                ans = max(ans, score[pid[t]]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}