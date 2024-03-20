#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

int n,k;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int num;
queue<pair<int,int>> bfs_q;
int r,c;
int max_num;

void InitializedVisited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
}
bool InRange(int x, int y){
    return x >= 0 && x <n && y >= 0 && y < n;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    
    if(arr[x][y] >= num || visited[x][y] == true)
        return false;
    return true;
}

void BFS(){
    while(!bfs_q.empty()){
        pair<int,int> curr_pos = bfs_q.front();
        int x = curr_pos.first, y= curr_pos.second;
        bfs_q.pop();

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(CanGo(nx,ny)){
                //cout << "bfs : num : " << num << endl;
                bfs_q.push(make_pair(nx,ny));
                visited[nx][ny] = true;                
            }
        }
    }
}
pair<int,int> FindMaxNum(){
    max_num = 0;
    int x, y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == true){
                if(!(r == i && c == j)){
                    if(max_num < arr[i][j]){
                        x= i, y = j; 
                        max_num = arr[i][j];
                        //cout <<"x,y,max_num : " <<i <<" " << j << " " << max_num << endl;
                    }
                }

            }
        }
    }
    if(max_num == 0)
        return make_pair(-1,-1);
    else{
        r = x; c = y;
        return make_pair(r,c);
    }        
}

void Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

void Simulation(){
    for(int i=0; i<k; i++){       
        InitializedVisited();

        if(r==-1)
            return;

        else{
            visited[r][c] = true;
            bfs_q.push(make_pair(r,c));
            //cout << "else : " << r <<" " << c << endl;
            num = arr[r][c];

            BFS();
        }
        pair<int,int> curr_pos =  FindMaxNum();  
        if(curr_pos.first != -1){
            r = curr_pos.first;
            c = curr_pos.second;
        }
        //cout << r <<" " << c  <<" " << arr[r][c]  << " k : " << i << endl;
       // Output();
    }
}

int main() {

    cin >> n >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >>  arr[i][j];

    cin >> r >> c;
    r--; c--;
  

    Simulation();
    r++; c++;
    cout << r << " " << c ;

    // 여기에 코드를 작성해주세요.
    return 0;
}