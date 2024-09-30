#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

#define MAX_N 100001
using namespace std;

int n;
vector<tuple<int, int, int > > lines;
int arr[MAX_N];
priority_queue<int> pq;

int main() {

    cin >> n;
    
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        lines.push_back(make_tuple(x,1,i));
        lines.push_back(make_tuple(y,-1,i));
    }

    sort(lines.begin(), lines.end());


    for(int i=1; i<=n;i++)
        pq.push(-i);

    for(int i=0;i<2*n; i++){
        int x,v,idx;
        tie(x,v,idx) = lines[i];
        if(v == 1){
            int tmp = pq.top();
            pq.pop();
            tmp = -tmp;
            arr[idx] = tmp;
        }
        else if(v==-1){
            int tmp = arr[idx];
            pq.push(-tmp);
        }
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}