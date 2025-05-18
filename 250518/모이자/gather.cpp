#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 105

int n;
int arr[MAX_N];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    int min_dist = INT_MAX;

    for(int i=1; i<=n; i++){
        int tmp_dist = 0;
        for(int j=1; j<=n; j++){
            tmp_dist += abs(j-i)*arr[j];
        }
        min_dist = min(min_dist, tmp_dist);
    }
    cout << min_dist;

    return 0;
}