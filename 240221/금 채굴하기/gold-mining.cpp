#include <iostream>
#include <algorithm>
#include <cstdlib>

#define MAX_NUM 20

using namespace std;

int n,m;
int grid[MAX_NUM][MAX_NUM];

int GetArea(int k){
    return k*k + (k+1)*(k+1);
}

bool InRange(int x, int y){
    return x>=0 && x < n && y>=0 && y<n;
}

int GetNumOfGold(int row, int col, int k){
    int num_of_gold = 0; 
    int dx[4] = {1,1,-1,-1}, dy[4] = {-1,1,1,-1};

    num_of_gold += grid[row][col];

    for(int curr_k = 1; curr_k <= k; curr_k++){
        int curr_x = row - curr_k, curr_y = col;

        for(int curr_dir = 0; curr_dir < 4; curr_dir++){
            for(int step = 0; step < curr_k; step++){
                if(InRange(curr_k,curr_y)) {
                    num_of_gold += grid[curr_x][curr_y];
                }
                curr_x = curr_x + dx[curr_dir];
                curr_y = curr_y + dy[curr_dir];
            }
        }
    }
    return num_of_gold;
}

int main() {
    int max_gold = 0;


    cin >> n >> m;

    for(int row = 0; row < n; row++)
        for(int col = 0; col < n; col++)
            cin >> grid[row][col];

    for(int row = 0; row <n; row++){
        for(int col = 0; col < n;col++){
            for(int k=0; k<=2*(n-1) ; k++){
                int num_of_gold = GetNumOfGold(row, col, k);

                if(num_of_gold * m >= GetArea(k))
                    max_gold = max(max_gold, num_of_gold);
            }
        }
    }

    cout << max_gold;
    
}