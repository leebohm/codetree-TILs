#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100001
#define MAX_M 100001

using namespace std;

int n,m;
int arr[MAX_N];
int count_array_in[MAX_M];
int count_array_out[MAX_M];

int distinct_num_in;
int distinct_num_out;

void Push(int idx){
    int num = arr[idx];

    if(count_array_in[num] == 0)
        distinct_num_in++;
    count_array_in[num]++;

    count_array_out[num]--;
    if(count_array_out[num]== 0)
        distinct_num_out--;
}

void Pop(int idx){
    int num = arr[idx];

    count_array_in[num]--;
    if(count_array_in[num]==0)
        distinct_num_in--;
    
    if(count_array_out[num]==0)
        distinct_num_out++;
    count_array_out[num]++;
}

int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    for(int i=1; i<=n; i++){
        if(count_array_out[arr[i]] == 0)
            distinct_num_out++;
        
        count_array_out[arr[i]]++;
    }

    int ans = INT_MAX;

    int j=0; 
    for(int i=1; i<=n; i++){
        while(j+1 <=n && distinct_num_in < m){
            Push(j+1);
            j++;
        }

        if(distinct_num_in < m)
            break;
        
        if(distinct_num_in == m)
            ans = min(ans, j-i+1);
        
        Pop(i);
    }

    if(ans == INT_MAX)
        ans = -1;
    
    cout << ans;
    return 0;
}