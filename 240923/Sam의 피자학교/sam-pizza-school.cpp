#include <iostream>
#include <tuple>
using namespace std;
#define MAX_N 102

int n,k; // n : 배열의 크기, k : 최대 최소 값의 차이

int dough[MAX_N][MAX_N];

void PrintDough(){
    for(int i=96; i<=100; i++){
        for(int j=1; j<=n; j++){
            cout << dough[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void RollOut_ij(int row, int col){
    //cout << "row : " << row << "  col : " << col << endl; 
    int tmp1[row+1][col+1] = {0};
    for(int i=1; i<=row; i++)
        for(int j=1; j<=col; j++)
            tmp1[i][j] = 0;

    for(int i=1; i <=row; i++){
        for(int j=1; j<=col; j++){
            tmp1[i][j] = dough[(100-row)+i][j];
            //cout << i << " " << j << " " << (100-row)+i << " " << j <<  endl;
        }
    }
    int tmp2[n+1] = {0};
    for(int i=1; i<=n; i++)
        tmp2[i] = 0;

    for(int i=col+1; i<=n; i++){
        tmp2[i-col] = dough[100][i];
    }
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            dough[99-col+j][row+1-i] = tmp1[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        dough[100][i] = tmp2[i];
    }
    
}
pair<int,int> RollOut(){
    for(int i=1; i<=10; i++){
        if(i==1){
                RollOut_ij(i,1);
                continue;
            }
        for(int j=0; j<2; j++){
            if(j == 0){
                if(n - (i*i-1) < i)
                    return make_pair(i-1,i-1);
                RollOut_ij(i,i-1);
                
            }
            else if(j == 1){
                if(n - (i*i) < i)
                    return make_pair(i-1,i);
                RollOut_ij(i,i);
            }
        }
    }
}
void FindMin(){
    int minval = 3001;
    for(int i=1; i<=n; i++)
        minval = min(minval, dough[100][i]);
    for(int i=1; i<=n; i++){
        if(dough[100][i] == minval)
            dough[100][i] += 1;
    }
}

bool InRange(int x, int y){
    return x >= 1 && x <=100 && y >= 1 && y <=n;
}

void LastPush(int row, int col){

    int tmp3[n+1] = {0};
    for(int i=1; i<=n; i++)
        tmp3[i] = 0;

    int idx = 1;

    
    for(int j=1; j<=n; j++){
        for(int i=100; i>=100-row; i--){
            if(dough[i][j] != 0){
                tmp3[idx++] = dough[i][j];
                dough[i][j] = 0;
            }
        }
    }
    for(int i=1; i<idx; i++){
        dough[100][i] = tmp3[i];
    }
}

void PushDough(int row, int col){

    int tmp4[n+1][n+1] = {0};

    for(int i=100-row; i<=100; i++)
        for(int j=1; j<=n; j++)
            tmp4[i][j] = 0;

    // 아래, 오른쪽 하고만 비교 
    int dx[2] = {1,0};
    int dy[2] = {0,1};

    for(int i=100-row; i<=100; i++){
        for(int j=1; j<=n; j++){
            if(dough[i][j] == 0)
                continue;
            for(int dir = 0; dir < 2; dir++){
                int nx = i+dx[dir];
                int ny = j+dy[dir];
                if(InRange(nx,ny) == true){
                    if(dough[nx][ny] != 0){
                        //cout << i << " " <<  j << " :  " << dough[i][j] << " , " << nx << " " << ny << " : " << dough[nx][ny] << " " ;
                        int a = dough[i][j];
                        int b = dough[nx][ny];
                        int d = abs(a-b) / 5;
                        if(dough[i][j] < dough[nx][ny]){
                            tmp4[nx][ny] -= d;
                            tmp4[i][j] += d;
                        }
                        else if (dough[i][j] > dough[nx][ny]){
                            tmp4[nx][ny] += d;
                            tmp4[i][j] -= d;
                        }

                    }
                }
            }
        }
    }

    for(int i=100-row; i<=100; i++){
        for(int j=1; j<=n; j++){
            if(tmp4[i][j] != 0)
                dough[i][j] += tmp4[i][j];
        }
    }

    LastPush(row, col);

}

void FoldDough(){
    int n_2 = n/2;
    int n_4 = n/4;
    int tmp5[3][n_2+1] = {0};
    int tmp6[5][n_4+1] = {0};
    for(int i=1; i<=2; i++)
        for(int j=1; j<=n_2; j++)
            tmp5[i][j] = 0;
    
    for(int i=1; i<=4; i++)
        for(int j=1; j<=n_4; j++)
            tmp6[i][j] = 0;

    for(int j=1; j<=n_2; j++)
        tmp5[1][n_2+1-j] = dough[100][j];
    for(int j=1; j<=n_2; j++)
        tmp5[2][j] = dough[100][j+n_2];
    
    for(int i=1;i<=2; i++){
        for(int j=1; j<=n_4; j++){
            tmp6[3-i][n_4+1-j] = tmp5[i][j];
        }
    }
    
    for(int i=3;i <=4; i++){
        for(int j=1; j<=n_4; j++){
            tmp6[i][j] = tmp5[i-2][n_4+j];
        }
    }

    
    for(int i=1; i<=4; i++){
        for(int j=1; j<=n_4; j++){
            dough[i+96][j] = tmp6[i][j];
        }
    }
    
    for(int i=n_4+1; i<=n; i++)
        dough[100][i] = 0;
}

void LastPush2(){

    int tmp7[n+1] = {0};
    for(int i=1;i<=n; i++)
        tmp7[i] = 0;

    int idx = 1;

    int n_4 = n/4;
    for(int j=1; j<=n_4; j++){
        for(int i=100; i>=97; i--){
            if(dough[i][j] != 0){
                tmp7[idx++] = dough[i][j];
                dough[i][j] = 0;
            }
        }
    }
    for(int i=1; i<idx; i++){
        dough[100][i] = tmp7[i];
    }
}

void PushDough2(){
    int n_4 = n/4;
    int tmp8[101][n_4+1] = {0};

    for(int i=97; i<=100; i++)
        for(int j=1; j<=n_4; j++)
            tmp8[i][j]= 0;

    // 아래, 오른쪽 하고만 비교 
    int dx[2] = {1,0};
    int dy[2] = {0,1};

    for(int i=97; i<=100; i++){
        for(int j=1; j<=n_4; j++){
            for(int dir = 0; dir < 2; dir++){
                int nx = i+dx[dir];
                int ny = j+dy[dir];
                if(InRange(nx,ny) == true ){
                    if(dough[nx][ny] != 0){
                        int a = dough[i][j];
                        int b = dough[nx][ny];
                        int d = abs(a-b) / 5;
                        //cout <<  d << " " << i <<" "<<  j << " " <<  a << " " << b << " " << endl;
                        if(dough[i][j] < dough[nx][ny]){
                            tmp8[nx][ny] -= d;
                            tmp8[i][j] += d;
                        }
                        else if (dough[i][j] > dough[nx][ny]){
                            tmp8[nx][ny] += d;
                            tmp8[i][j] -= d;
                        }  
                    }
                }
            }
        }
    }


    for(int i=97; i<=100; i++){
        for(int j=1; j<=n_4; j++){
            if(tmp8[i][j] != 0){
                dough[i][j] += tmp8[i][j];
            }
        }
    }

    LastPush2();

}

int FindDiff(){
    int minval = 3001;
    int maxval = 0;
    for(int i=1; i<=n; i++){
        minval = min(minval, dough[100][i]);
        maxval = max(maxval, dough[100][i]);
    }
    return abs(minval - maxval);
}
int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> dough[100][i];

    int cnt = 1;

    while(true){
        FindMin();
        int row = 0; 
        int col = 0;
        tie(row,col) = RollOut();

        PushDough(row, col);
        FoldDough();

        PushDough2();
        int diff = FindDiff();
        if(diff <= k)
            break;

        cnt++;
    }

    cout << cnt;

    return 0;
}