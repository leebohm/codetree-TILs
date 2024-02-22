#include <iostream>
#include <algorithm>

#define MAX_N 20
#define DIR_NUM 4

using namespace std;

int n;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0<= y && y<n;
}

int GetScore(int x, int y, int k, int l){
    int dx[DIR_NUM] = {-1,-1,1,1};
    int dy[DIR_NUM] = {1,-1,-1,1};
    int move_num[DIR_NUM] = {k,l,k,l};

    int sum_of_nums = 0; 

    for(int d= 0; d <DIR_NUM; d++)
        for(int q = 0; q < move_num[d]; q++){
            x += dx[d]; y +=dy[d];

            if(!InRange(x,y)) return 0;

            sum_of_nums += grid[x][y];
        }
    return sum_of_nums;
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    int ans = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=1; k<n; k++)
                for(int l=1; l<n; l++)
                    ans = max(ans, GetScore(i,j,k,l));

    cout << ans;
    return 0;
}