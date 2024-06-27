#include <iostream>
#include <climits>

#define MAX_N 100001

using namespace std;

int n,m;
int arr[MAX_N];
int count_in[MAX_N];
int count_out[MAX_N];

int distinct_in;
int distinct_out;

void Push(int idx){
    int num = arr[idx];

    if(count_in[num] == 0)
        distinct_in++;
    count_in[num]++;

    count_out[num]--;
    if(count_out[num] == 0)
        distinct_out--;
}

void Pop(int idx){
    int num = arr[idx];

    if(count_out[num] == 0)
        distinct_out++;
    count_out[num]++;

    count_in[num]--;
    if(count_in[num] == 0)
        distinct_in--;
}

int main(){
    cin >> n>>m;

    for(int i=1;i<=n; i++)
        cin >> arr[i];
    
    for(int i=1; i<=n; i++){
        if(count_out[arr[i]] == 0)
            distinct_out++;
        count_out[arr[i]]++;
    }

    int j =0;
    int ans = INT_MAX;

    for(int i=1; i<=n; i++){
        while(j+1 <=n && distinct_in < m){
            Push(j+1);
            j++;
        }

        if(distinct_in < m)
            break;
        
        if(distinct_out == m)
            ans= min(ans, j-i+1);
        
        count_in[arr[i]]--;
        if(count_in[arr[i]] == 0)
            distinct_in--;
    }

    if(ans == INT_MAX)
        ans = -1;
    cout << ans;

    return 0;
}