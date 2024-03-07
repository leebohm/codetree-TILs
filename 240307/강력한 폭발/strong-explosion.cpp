#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int dx1[4] = {-1,-2,1,2};
int dy1[4] = {0,0,0,0};

int dx2[4] = {0,-1,0,1};
int dy2[4] = {1,0,-1,0};

int dx3[4] = {-1,-1,1,1};
int dy3[4] = {1,-1,-1,1};

int n,k;
int arr[20][20];
int temp[20][20];
int answer = 0;

vector<int> vec;
vector<pair<int,int>> bomb_pos;

bool InRange(int x, int y){
    return x >=0 && x <n &&  y>=0 && y < n; 
}

void ResetTemp(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = 0;
        }
    }
}

void Bomb(){
    for(int i=0; i<(int) vec.size(); i++){
        int idx = vec[i];
        int x,y;
        tie(x,y) = bomb_pos[i];
        if(idx == 1){
            temp[x][y]++;
            for(int j=0; j<4; j++){
                int nx = x+dx1[j];
                int ny = y+dy1[j];
                if(InRange(nx,ny)){
                    temp[nx][ny] = 1;
                }
            }
        }

        else if(idx == 2){
            temp[x][y]++;
            for(int j=0; j<4; j++){
                int nx = x+dx2[j];
                int ny = y+dy2[j];
                if(InRange(nx,ny)){
                    temp[nx][ny] = 1;
                }
            }
        }

        else if(idx == 3){
            temp[x][y]++;
            for(int j=0; j<4; j++){
                int nx = x+dx3[j];
                int ny = y+dy3[j];
                if(InRange(nx,ny)){
                    temp[nx][ny] = 1;
                }
            }
        }
    }   
}



void CountNum(){
    for(int i=0; i<n;i++)
        for(int j=0; j<n; j++)
            if(arr[i][j] == 1) k++;
}

int CountBomb(){
    int ans = 0;
    for(int i=0 ;i<n; i++)
        for(int j=0; j<n; j++){
            if(temp[i][j] >=1){
                ans++;
            }
        }
    return ans;
}

void Choose(int cnt){

    if( cnt == k ){
        ResetTemp();
        Bomb();
        answer = max(answer, CountBomb());
        return;
    }

    for( int i=1; i<=3; i++ ){
        vec.push_back(i);
        Choose(cnt+1);
        vec.pop_back();
    }

    return;
}

void FindBombPos(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[i][j] == 1)
                bomb_pos.push_back(make_pair(i,j));

}

int main() {

    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    

    CountNum();
    FindBombPos();
    Choose(0);

    cout << answer;

    // 여기에 코드를 작성해주세요.
    return 0;
}