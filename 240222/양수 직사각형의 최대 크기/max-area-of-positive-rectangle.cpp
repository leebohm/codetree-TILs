#include <iostream>

using namespace std;

#define MAX_NM 20

int n,m;
int arr[MAX_NM][MAX_NM];

bool CheckPositive(int x1, int y1, int x2, int y2){
    for(int i=x1; i<=x2; i++)
        for(int j=y1; j<=y2; j++)
            if(arr[i][j]<=0) return false;
    
    return true;
            
}

int GetBoxSize(int x1, int y1, int x2, int y2){
    int boxsize = (x2-x1+1)*(y2-y1+1);
    
    return boxsize;
            
}
int main() {

    cin >> n >>  m;

    for(int i=0; i<n;i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    
    int ans =-1;
    bool flag = true;

    for(int x1 =0; x1 < n; x1++)
        for(int y1 = 0; y1 < m; y1++)
            for(int x2 = x1; x2 < n; x2++)
                for(int y2 =y1; y2 < m; y2++){
                    flag = CheckPositive(x1,y1,x2,y2);
                    if(flag) ans = max(ans,GetBoxSize(x1,y1,x2,y2) );
                }


    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}