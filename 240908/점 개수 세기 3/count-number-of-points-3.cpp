#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>

#define MAX_NUM 100001

using namespace std;

int n,q;
int arr[MAX_NUM];
pair<int,int> queries[MAX_NUM];

set<int> nums;
unordered_map<int,int> mapper;

int main(){

    cin >> n >> q;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=0; i<q; i++){
        int a,b;
        cin >> a >> b;
        queries[i] = make_pair(a,b);
    }

    for(int i=0; i<n; i++)
        nums.insert(arr[i]);
    
    int cnt = 1;
    for(set<int>::iterator it = nums.begin(); it != nums.end(); it++){
        mapper[*it] = cnt;
        cnt++;
    }

    for(int i=0; i<q; i++){
        int a,b;
        tie(a,b) = queries[i];

        int na = mapper[a];
        int nb = mapper[b];

        cout << nb- na +1 << endl;
    }

    return 0;
}