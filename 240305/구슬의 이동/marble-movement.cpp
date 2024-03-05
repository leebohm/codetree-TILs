#include <iostream>
#include <tuple>
#include <vector>

#define ASCII 128
using namespace std;

int n,m,t,k;

int mapper[ASCII];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int board[50][50];

vector<pair<int,int>> index;
typedef tuple<int,int,int,int> marbles_info;
vector<marbles_info> marbles;

bool InRange(int x, int y){
    return 0 <= x && x<n && y>=0 && y<n;
}

void ResetBoard(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            board[i][j] = 0;
}

void Check_num(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] >k){
                index.push_back(make_pair(i,j));
            }
        }
    }
}

marbles_info Move(marbles_info marble){
    int r,c,d,v;
    tie(r,c,d,v) = marble;

    int nr = r+dx[d];
    int nc = c+dy[d];
    
    if(InRange(nr,nc)){
        marble = make_tuple(nr,nc,d,v);
    }
    else{
        d = 3-d;
        nr = r + dx[d];
        nc = c + dy[d];
        marble = make_tuple(nr,nc,d,v);
    }

    return marble;
}

void Bomb(){
    
    // index는 k가 넘는 구슬의 좌표들의 배열 
    for(int i=0; i <(int) index.size(); i++){
        
        int x,y;
        tie(x,y) = index[i];
        int num = board[x][y];
        // num 개 중에 num-k 개의 구슬을 지워야 함.... 
        // 우선순위 일단 v 큰것. 그다음 구슬 번호가 큰 것. 
        // num 이 k보다 작거나 같아지면 끝남. 
        while(num != k){

            int fin_r = 0;
            int fin_c = 0;
            int r,c,v; 
            int min_v = 11;
            int min_j = 2500;   

            for(int j=(int) marbles.size()-1; j >=0 ; j--){
                tie(r,c,ignore,v) = marbles[j];

                if(r==x && c==y && min_v > v && min_j > j){
                    min_v = v;
                    min_j = j;
                    fin_c = c;
                    fin_r = r;
                }
            }

            for(int j = min_j; j<(int) marbles.size()-1; j++){
                marbles[j] = marbles[j+1];
            }
            num--;
            

        }
        
    }
}

int main() {

    mapper['U'] = 0;
    mapper['D'] = 3;
    mapper['L'] = 1;
    mapper['R'] = 2;

    cin >> n >> m >> t >> k;
    
    int r,c,v;
    char d;

    for(int i=0; i<m; i++){
        cin >> r >> c >> d >> v;
        r--; c--;
        int dir = mapper[d];
        marbles.push_back(make_tuple(r,c,dir,v));
    }
    int x,y;
    while(t--){ // 시뮬레이션 1초마다 돌아감 
        ResetBoard();
        index.clear();
        // 구슬 1개씩 시뮬레이션 
        for(int i=0; i<(int) marbles.size(); i++){

            tie(ignore,ignore,ignore, v) = marbles[i];
            
            // 1초에 v 만큼 가는 것 반영
            for(int j=0; j<v;j++){
                marbles_info temp = Move(marbles[i]);
                marbles[i] = temp;
            }
            
            // 구슬 1개 다 이동 후 board에 반영
            tie(x,y,ignore,ignore) = marbles[i];
            board[x][y]++;
        }
        // 1초 동안 모든 구슬 다 이동 후 board 상태 파악 
        Check_num();
        Bomb();

    }
    
    cout << (int) marbles.size();

    // 여기에 코드를 작성해주세요.
    return 0;
}