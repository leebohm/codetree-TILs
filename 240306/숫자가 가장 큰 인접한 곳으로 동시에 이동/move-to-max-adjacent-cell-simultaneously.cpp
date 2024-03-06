#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n,m,t;
int r,c;
vector<int> r_vec;
vector<int> c_vec;
vector<int> r_tmp;
vector<int> c_tmp;
int arr[20][20];
int temp[20][20];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

pair<int,int> FindMax(int x, int y){
    
    int max_num =0;
    int fin_x = -1; int fin_y = -1;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(InRange(nx,ny) && max_num < arr[nx][ny]){
            fin_x = nx; fin_y = ny;
            max_num = arr[nx][ny];
        }
    }
    return make_pair(fin_x, fin_y);
}

void ResetTemp(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j]=0;
}



void Move(int x, int y, int idx){
    int nx, ny;
    tie(nx,ny) = FindMax(x,y);
    r_vec[idx] = nx;
    c_vec[idx] = ny;
    temp[nx][ny]++;
}

void Move_all(){
    for(int i=0; i<m; i++){
        Move(r_vec[i],c_vec[i],i);
    }
}

void Remove_marbles(int x, int y){

    r_tmp.clear();
    c_tmp.clear();

    for(int i=0; i< (int) r_vec.size(); i++){
        if(x != r_vec[i] || y != c_vec[i]){
            r_tmp.push_back(r_vec[i]);
            c_tmp.push_back(c_vec[i]);
        }
    }
    r_vec = r_tmp;
    c_vec = c_tmp;
}

void Check_marbles(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(temp[i][j] > 1){
                Remove_marbles(i,j);
                m = m-temp[i][j];
            }
        }
    }
}
void Simulation(){
    while(t--){
        ResetTemp();
        Move_all();
        Check_marbles();
    }
}

int main(){
    
    cin >> n >> m >> t;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<m; i++){
        cin >> r >> c;
        r--; c--;
        r_vec.push_back(r);
        c_vec.push_back(c);
    }

    Simulation();

    cout << (int) r_vec.size();
    return 0;
}