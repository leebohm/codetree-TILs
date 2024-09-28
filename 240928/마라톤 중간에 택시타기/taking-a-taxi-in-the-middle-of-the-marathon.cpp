#include <iostream>
#include <tuple>
#include <climits>

using namespace std;

#define MAX_N 100001

int left_num[MAX_N];
int right_num[MAX_N];
int n;
pair<int,int> points[MAX_N];

int count_distance(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1 - y2);
}

int cal_dist_points(int idx1, int idx2){
    int x1,y1,x2,y2;
    tie(x1,y1) = points[idx1];
    tie(x2,y2) = points[idx2];
    return count_distance(x1,y1,x2,y2);
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        points[i] = make_pair(x,y);
    }

    for(int i=1; i<=n; i++){
        int x1, y1, x2, y2;
        tie(x1,y1) = points[i];
        tie(x2,y2) = points[i-1];
        int d = count_distance(x1,y1,x2,y2);
        left_num[i] = d;
    }

    for(int i=1; i<n;i++){
        left_num[i] += left_num[i-1];
    }

    for(int i=n-2; i>=0; i--){
        int x1, y1, x2, y2;
        tie(x1,y1) = points[i];
        tie(x2,y2) = points[i+1];
        int d = count_distance(x1,y1,x2,y2);
        right_num[i] = d;
    }

    for(int i=n-1; i >= 0; i--){
        right_num[i] += right_num[i+1];
    }

    int ans = INT_MAX;

    for(int i=0; i<n-2; i++){
        int tmp = left_num[i] + right_num[i+2] + cal_dist_points(i,i+2); 
        //cout << left_num[i] << " " << right_num[i+2] << " " << cal_dist_points(i,i+2) << endl;
        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}