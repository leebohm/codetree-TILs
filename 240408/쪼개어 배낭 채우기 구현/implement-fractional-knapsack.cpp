#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n,m;

vector<tuple<double,int,int>> jewelries;

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        int w,v;
        cin >> w >> v;

        jewelries.push_back(make_tuple(-1.0*v/w,w,v));
    }

    sort(jewelries.begin(), jewelries.end());

    double value = 0.0;
    int tmp = 0;

    for(int i=0; i<n; i++){

        if(tmp == m)
            break;

        int w = 0, v= 0;
        double tmp_val = 0.0;
        tie(tmp_val, w,v) = jewelries[i];
        int ntmp = tmp+ w;

        if(ntmp <= m){
            tmp = ntmp;
            value += v;
        }
        else{
            int tmp2 = m - tmp;
            tmp += tmp2;
            value += tmp2*(-tmp_val);
            break;
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << value;
    // 여기에 코드를 작성해주세요.
    return 0;
}