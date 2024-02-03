#include <iostream>
#include <cmath>

int x;

using namespace std;

int main() {

    cin >> x;
    
    int cur_dist = 0;
    int v = 1;
    int sec = 0;

    while(cur_dist < x){
        cur_dist += v;

        if((x-cur_dist)>=((v+1)*(v+2))/2){
            v+=1;
        }
        else if((x-cur_dist)>=((v)*(v+1))/2){
            v=v;
        } 
        else {
            v-=1;            
        } 
        
        sec++;
    }
    cout << sec;

    return 0;
}