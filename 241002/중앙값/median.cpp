#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 100001

using namespace std;

int t,m;
int arr[MAX_N];

void FindMedian(){

    int median = arr[0];
    priority_queue<int> max_pq;
    priority_queue<int> min_pq;
    cout << median << " ";

    for(int i=1; i<m; i++){
        if(i%2 == 1){
            if(arr[i] < median)
                max_pq.push(arr[i]);
            else 
                min_pq.push(-arr[i]);
        }

        else{
            int new_cand;
            if((int) max_pq.size() > (int) min_pq.size()){
                new_cand = max_pq.top();
                max_pq.pop();
            }
            else{
                new_cand = -min_pq.top();
                min_pq.pop();
            }

            int nums[] = {median, arr[i], new_cand};
            sort(nums, nums+3);

            max_pq.push(nums[0]);
            median = nums[1];
            min_pq.push(-nums[2]);

            cout << median << " ";
        }
    }
    cout << endl;
}

int main(){

    cin >> t;
    while(t--){
        cin >>m;
        for(int i=0; i<m; i++)
            cin >> arr[i];
        
        FindMedian();
    }
    return 0;
}