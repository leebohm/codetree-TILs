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
            //cout << "case 1 : " << cur_dist << " v : " << v << endl;
        }
        else if((x-cur_dist)>=((v)*(v+1))/2){
            v=v;
            //cout << "case 2 : " << cur_dist << " v : " << v << endl;
        } 
        else //if((x-cur_dist)==((v-1)*(v))/2){
           {
            v-=1;            
            //cout << "case 3 : " << cur_dist << " v : " << v << endl;
        } 
        
        sec++;
        //cout << "sec : " << sec <<" "<< cur_dist << " v : " << v << endl;
    }
    cout << sec;

    return 0;
}