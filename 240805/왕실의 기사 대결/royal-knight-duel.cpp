#include <iostream>
#include <set>
#include <queue>

#define MAX_L 41
#define MAX_N 31

using namespace std;

int l,n,q; // l : 체스판 크기, n : 기사의 수, q : 명령의 수
// 체스판 정보 0:빈칸, 1: 함정, 2:벽

int board[MAX_L][MAX_L];
int knights_pos[MAX_L][MAX_L];
set<int> knights_s;
queue<int> knights_q;
bool flag = true;
queue<int> have_to_move;

struct Knight{
    int r,c,h,w,k,origin_k;
    bool state;
    Knight(int r, int c, int h, int w, int k):r(r),c(c),h(h),w(w),k(k),origin_k(k),state(true){}
};

Knight *knights[MAX_N] = {};

// 위쪽, 오른쪽, 아래쪽, 왼쪽
int dx[4] = {-1, 0,1,0};
int dy[4] = {0,1,0,-1};

bool InRange(int x,int y){
    return x >=1 && x <=l && y>=1 && y<=l;
}

void PrintKnightsPos(){
    for(int i=1; i<=l; i++){
        for(int j=1; j<=l; j++){
            cout << knights_pos[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
// nr,nc : 이동될 위치의 r,c 좌표, w,h : 기사 범위 ,i : 기존 기사의 번호 

void check(int nr, int nc, int h, int w, int i){
    
    flag = true;

    for(int x= nr; x < nr+h; x++){
        for(int y = nc; y < nc+w; y++){
            if(InRange(x,y) == false || board[x][y] == 2){ // 벽을 만나면 0을 반환
                flag = false;
                break;
            }
            else if(knights_pos[x][y] != i && knights_pos[x][y] != 0){
                if(knights_s.find(knights_pos[x][y]) == knights_s.end()){
                    knights_q.push(knights_pos[x][y]);
                    knights_s.insert(knights_pos[x][y]);
                }
            }
        }
    }
}

void move(int num, int dir){
    int cr = knights[num]->r;
    int cc = knights[num]->c;
    int h = knights[num]->h;
    int w = knights[num]->w;
    for(int x = cr; x < cr+h; x++){
        for(int y =cc; y < cc+w; y++){
            if(knights_pos[x][y] == num)
                knights_pos[x][y] = 0; // 다 지우기.
        }
    }
    int nr = cr + dx[dir];
    int nc = cc + dy[dir];

    for(int x = nr; x < nr+h; x++){
        for(int y = nc; y < nc+w; y++){
            knights_pos[x][y] = num;
        }
    }
    knights[num]->r = nr;
    knights[num]->c = nc;
}

void check_life(int i){
    if(knights[i]->state == false) // 사라진 기사는 신경쓰지 않음!
        return;
    int cnt = 0; // 함정의 수
    int r = knights[i]->r;
    int c = knights[i]->c;
    int h = knights[i]->h;
    int w = knights[i]->w;
    for(int x = r; x<r+h; x++){
        for(int y = c; y<c+w; y++){
            if(board[x][y] == 1 && knights_pos[x][y] == i){
                cnt++;
            }
        }
    }
    knights[i]->k -= cnt; // 체력에서 함정의 수 빼기
    
    if(knights[i]->k <=0){
        knights[i]->state = false;

        for(int x = r; x<r+h; x++){
            for(int y = c; y<c+w; y++){
                knights_pos[x][y] = 0;
            }
        }
    }
}

int cal_ans(){
    int org = 0;
    int res = 0;
    for(int i=1; i<=n; i++){
        if(knights[i]->state == true){
            res += knights[i]->k;
            org += knights[i]->origin_k;
        }
    }
    return org-res;
}

void printKnights_k(){
    for(int i=1; i<=n; i++){
        cout <<"i : " << i << " " << knights[i]->k << " ";
    }
    cout << endl;
}

int main() {
    
    cin >> l >> n >> q;
    
    for(int i=1; i<=l; i++){
        for(int j=1; j<=l; j++){
            cin >> board[i][j]; // 체스판 정보 입력받기 
        }
    }

    for(int i=1; i<=n; i++){
        int r,c,h,w,k;
        cin >> r >> c >> h >> w >> k;
        
        knights[i] = new Knight(r,c,h,w,k); // 기사 정보 입력 받기 
        for(int x = r; x<r+h;x++){ // 기사의 범위 표현해두기 
            for(int y= c; y<c+w; y++){
                knights_pos[x][y] = i;
            }
        }
    }

    for(int i=1;i<=q;i++){ // 왕의 명령 입력받기
        int num, dir;
        cin >> num >> dir;
        int origin_num = num;
        if(knights[num]->state == false) // 체스판에서 사라진 기사에게 명령을 내리면 아무 반응 없음
            continue;

        knights_s = {};
        knights_q = {};
        knights_q.push(num);
        knights_s.insert(num);

        while(knights_q.empty() == false){
            num = knights_q.front();
            knights_q.pop();

            check(knights[num]->r+dx[dir],knights[num]->c+dy[dir], knights[num]->h, knights[num]->w, num);
            if(flag == false)
                break;
        }

        if(flag == true){
            set<int>::iterator it;
            it = knights_s.begin();
            for(it; it != knights_s.end(); it++){
                num = *it;
                move(num,dir);
            }
        } // 이제 이동완료! 체력 닳아야함
        
        if(flag == true){
            set<int>::iterator it;
            it = knights_s.begin();
            for(it; it != knights_s.end(); it++){
                num = *it;
                if(origin_num != num){
                    check_life(num);
                }
            }
        }
    }

    int ans = cal_ans();

    cout << ans;

    return 0;
}