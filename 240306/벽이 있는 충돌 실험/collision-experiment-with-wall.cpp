#include <iostream>
#include <tuple>
#include <vector>

#define ASCII 128
using namespace std;

int t;
int n,m;
int x,y;
char dir;
int mapper[ASCII];
int temp[50][50];

typedef tuple <int,int,int> Marble;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
vector<Marble> marbles;
vector<Marble> temp_marbles;

bool InRange(int x, int y){
    return x>=0 && x <n && y>= 0 && y<n;
}
void ResetTemp(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = 0;
}

void Move(int idx){
    int r,c,d;
    tie(r,c,d) = marbles[idx];
    int nx = r+dx[d];
    int ny = c+dy[d];
    //cout << r << c <<d << "rcd " << endl;
    if(InRange(nx,ny)){
        marbles[idx]= make_tuple(nx,ny,d);
        temp[nx][ny]++;
    }
    else{
        marbles[idx] = make_tuple(r,c,3-d);
        temp[r][c]++;
    }
}
void RemoveMarbles(int x, int y){
    temp_marbles.clear();
    for(int i=0; i<(int) marbles.size(); i++){
        int a,b,d;
        tie(a,b,d) = marbles[i];
        if(a != x || b != y){
            //cout << a << b << x<< y <<"abxy" << endl;
            temp_marbles.push_back(make_tuple(a,b,d));
        }
    } 
    marbles = temp_marbles;
}

void CheckNum(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(temp[i][j] >=2){
                //cout << i << j << endl;
                RemoveMarbles(i,j);
            }
        }
    }
}
void Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}
void MoveAll(){

    for(int j=0; j<2*n; j++){
        //cout << (int) marbles.size() << endl;
        ResetTemp();
        for(int i=0; i<(int) marbles.size(); i++){
            Move(i);
            //Output();
            //cout << endl;
        }
        CheckNum();
    }
}

int main() {
    
    mapper['U'] = 0;
    mapper['R'] = 1;
    mapper['L'] = 2;
    mapper['D'] = 3;

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n >> m;
        marbles.clear();
        for(int j=0;j<m; j++){
            cin >> x >> y >> dir;
            x--; y--;
            int d = mapper[dir];
            marbles.push_back(make_tuple(x,y,d));
        }
        MoveAll();
        cout << (int) marbles.size() << endl;
    }

    return 0;
}