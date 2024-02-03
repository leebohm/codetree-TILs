#include <iostream>
#include <cmath>

int x;

using namespace std;

int main() {

    cin >> x;
    
    int cur_dist = 0;
    int v = 0;
    int sec = 0;

    while(cur_dist < x){
        cur_dist += v;

        if((x-cur_dist)>=((v)*(v+1))/2) v+=1;
        else if(x-cur_dist == cur_dist + v*v/2) v= v;
        else if((x-cur_dist)>=((v)*(v-1))/2) v-=1;
        sec++;
    }
    cout << sec;

    return 0;
}