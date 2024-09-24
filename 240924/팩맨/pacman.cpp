#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

#define Monster tuple<int,int,int> // 몬스터의 위치 방향 정보

int m,max_t ; // m : 초기 몬스터의 마리 수, 진행되는 턴의 수 t
int pr,pc; // 팩맨의 위치를 나타내는 전역변수 

int dx_8[8] = {-1,-1,0, 1,1,1, 0,-1};
int dy_8[8] = {0,-1,-1, -1,0,1, 1,1};

// 상좌하우 우선순위 큰게 큰 인덱스 매칭되도록
int dx_4[4] = {-1,0,1,0};
int dy_4[4] = {0,-1,0,1};

vector<pair<int,int>> board_for_Pacman[5][5]; // 몬스터의 인덱스가 적혀있음 
Monster info[11][26]; // 1번부터 m번까지 몬스터, 각 턴마다 복제되는 몬스터는 t t 값을 다르게 저장함 

priority_queue<int> board_for_Monster[5][5]; // 몬스터 시체의 시간을 담을 거임 죽을 때 t+2 해서 현재 턴 보다 클때 소멸 되는 것. 
// 팩맨 위치는 격자에 표시하지 않음, 그냥 좌표값으로 직접 비교함 

vector<tuple<int,int,int,int>> eggs; // 몬스터알 복제한 것 저장. 

void Print_Board_for_Monster(){
    
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            int num = (int) board_for_Monster[i][j].size();
            if(num == 0)
                cout << 0 << " ";
            else{
                int tmp = board_for_Monster[i][j].top();
                cout << tmp << " ";
            }
        }
        cout << endl;
    }
}

void Print_Num_Board_for_Pacman(){
    for(int i=1; i<=4; i++){
        for(int j=1; j <=4; j++){
            int num = (int) board_for_Pacman[i][j].size();
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Print_Board_for_Pacman(){
    for(int i=1; i<=4; i++){
        for(int j=1; j <=4; j++){
            int num = (int) board_for_Pacman[i][j].size();
            if(num == 0)
                cout << 0 << " ";
            else{
                for(int idx = 0; idx <num; idx++){
                    int x,y;
                    tie(x,y) = board_for_Pacman[i][j][idx];
                    cout << x << " " << y << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

void PrintInfo(){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=2; j++){
            int r,c,d;
            tie(r,c,d) = info[i][j];
            cout << r << " " << c << " " << d << endl;
        }
    }
    cout << endl;
}


void PrintEggs(){
    vector<tuple<int,int,int,int>>::iterator it;
    for(it = eggs.begin(); it != eggs.end(); it++){
        int i,r,c,d;
        tie(i,r,c,d) = *it;
        cout <<i<< " " << r << " " << c << " " << d << endl;
    }
    cout << endl;
}

void MonsterClone(int t){

    for(int i=1; i<=m; i++){
        for(int j=1; j<=t; j++){
            int r,c,d;
            tie(r,c,d) = info[i][j];
            if(r == 0)
                continue;
            eggs.push_back(make_tuple(i,r,c,d));
        }
    }
}
bool InRange(int x, int y){
    return x>=1 && x <=4 && y >= 1 && y <= 4;
}

bool CanGo(int x, int y, int t){
    if(InRange(x,y) == false)   
        return false;
    if(x == pr && y == pc)
        return false;
    if(board_for_Monster[x][y].empty() == false){
        int tmp_t = board_for_Monster[x][y].top();
        if(tmp_t > t)
            return false;
    }
    return true;
}

tuple<int,int,int> OneMonsterMove(int r, int c, int d,int t){

    int nr = r+dx_8[d];
    int nc = c+dy_8[d];
    // 다음 칸이 격자 밖이거나, 팩맨이 있거나, 몬스터 시체가 있는 경우
    for(int i=0; i<7; i++){
        if(CanGo(nr,nc,t) == true){
            return make_tuple(nr,nc,d);
        }
        else{
            d = (d+1) % 8;
            nr = r+dx_8[d];
            nc = c+dy_8[d];
        }
    }
    return make_tuple(r,c,d);
}

void Update_Board_for_pacman(int i, int j, int r, int c, int nr, int nc){
    int num = (int) board_for_Pacman[r][c].size();
    for(int idx=0; idx<num; idx++){
        int tmp_i,tmp_j;
        tie(tmp_i,tmp_j) = board_for_Pacman[r][c][idx];
        if(tmp_i == i && tmp_j == j)
            board_for_Pacman[r][c].erase(board_for_Pacman[r][c].begin()+idx);
    }
    board_for_Pacman[nr][nc].push_back(make_pair(i,j));
}

void MonsterMove(int t){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=t; j++){
            int r,c,d;
            tie(r,c,d) = info[i][j];
            if(r == 0)
                continue;
            int nr,nc,nd;
            tie(nr,nc,nd) = OneMonsterMove(r,c,d,t);
            info[i][j] = make_tuple(nr,nc,nd);
            Update_Board_for_pacman(i,j,r,c,nr,nc);
        }
    }
}

void EatMonster(int i, int j, int k, int t){

    for(int g = 0; g<3; g++){
        if(g==0){
            pr += dx_4[i];
            pc += dy_4[i];
        }
        else if(g==1){
            pr += dx_4[j];
            pc += dy_4[j];
        }
        else if(g==2){
            pr += dx_4[k];
            pc += dy_4[k];
        }
        int num = (int) board_for_Pacman[pr][pc].size();
        for(int h = 0; h < num; h++){
            int idx1, idx2;
            tie(idx1, idx2) = board_for_Pacman[pr][pc][h];
            info[idx1][idx2] = make_tuple(0,0,0);
            board_for_Monster[pr][pc].push(t+2);
        }
        board_for_Pacman[pr][pc].clear();
    }
    
}

void PacmanMove_ijk(int t){

    int max_cnt = 0;
    int fi = -1;
    int fj = -1; 
    int fk = -1;
    for(int i=0; i<4; i++){
        
        int npr1 = pr + dx_4[i];
        int npc1 = pc + dy_4[i];

        if(InRange(npr1,npc1) == true){
            for(int j=0; j<4; j++){
                int npr2 = npr1 + dx_4[j];
                int npc2 = npc1 + dy_4[j];

                if(InRange(npr2, npc2) == true){
                    for(int k=0; k<4; k++){
                        int npr3 = npr2 + dx_4[k];
                        int npc3 = npc2 + dy_4[k];

                        if(InRange(npr3,npc3) == true){
                            if((npr1 != npr2 || npc1 != npc2) && (npr2 != npr3 || npc2 != npc3) && (npr1 != npr3 || npc1 != npc3)){
                                int cnt =0;
                                cnt += (int) board_for_Pacman[npr1][npc1].size();
                                cnt += (int) board_for_Pacman[npr2][npc2].size();
                                cnt += (int) board_for_Pacman[npr3][npc3].size();
                                if(max_cnt < cnt){
                                    max_cnt = cnt;
                                    fi = i; fj= j; fk = k;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    EatMonster(fi,fj,fk,t);
}

void EraseGhostMonster(int t){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            if(board_for_Monster[i][j].empty() != true){
                int val = board_for_Monster[i][j].top();
                if(val < t){
                    while(board_for_Monster[i][j].empty() == true){
                        board_for_Monster[i][j].pop();
                    }
                }
            }            
        }
    }
}

void Hatch(int t){
    int num = (int) eggs.size();
    for(int h=0; h<num; h++){
        int i,r,c,d;
        tie(i,r,c,d) = eggs[h];
        info[i][t] = make_tuple(r,c,d);
        board_for_Pacman[r][c].push_back(make_pair(i,t));
    }
    eggs.clear();
}

void Simulation(){
    for(int t=1; t<=max_t; t++){
        
        // 1. 몬스터 복제 시도
        MonsterClone(t);

        // 2. 몬스터 이동
        MonsterMove(t);

        // 3. 팩맨 이동
        PacmanMove_ijk(t);
        
        // 4. 몬스터 시체 소멸
        EraseGhostMonster(t);

        // 5. 몬스터 복제 완성
        Hatch(t+1);
    }
}


int main() {
    cin >> m >> max_t;
    cin >> pr >> pc;
    int r,c,d;
    for(int i=1; i<=m; i++){
        cin >> r >> c >> d;
        d = (d-1) % 8;
        info[i][1] = make_tuple(r,c,d);
        board_for_Pacman[r][c].push_back(make_pair(i,1));
    }
    Simulation();
    int ans =0;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            ans += (int) board_for_Pacman[i][j].size();
        }
    }
    cout << ans;
    return 0;
}