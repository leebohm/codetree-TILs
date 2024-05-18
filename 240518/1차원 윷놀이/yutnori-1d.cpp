#include <iostream>
#include <algorithm>

#define MAX_N 12
#defien MAX_K 4

using namespace std;

int n,m,k;
int nums[MAX_N], pieces[MAX_K];
int ans;

int Calc(){
    int score = 0;
    for(int i=0; i<k; i++)
        score += (pieces[i] >= m);
    return score;
}

void FindMax(int cnt){

    ans = max(ans, Calc());

    if(cnt == n)
        return ;
    
    for(int i=0; i<k; i++){

        if(pieces[i] >= m)
            continue;
        pieces[i] += nums[cnt];
        FindMax(cnt + 1);
        pieces[i] -= nums[cnt];
    }
}

int main(){
    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    for(int i=0; i<k; i++)
        pieces[i] = 1;
    
    FindMax(0);

    cout << ans;
    return 0;
}