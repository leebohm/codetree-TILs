#include <iostream>
#include <climits>

using namespace std;

int arr[6];

int main(){

    for(int i=0; i<6; i++)
        cin >> arr[i];

    int ans = INT_MAX;
    for(int a = 0; a<2; a++){
        for(int b = 0;b <2; b++){
            for(int c = 0; c < 2; c++){
                for(int d =0; d<2; d++){
                    for(int e= 0; e<2; e++){
                        int t1 = 0;
                        int t2 = 0;
                        for(int f = 0; f<2; f++){
                            if(a+b+c+d+e+f == 3){
                                if(a==1)
                                    t1 += arr[0];
                                else
                                    t2 += arr[0];
                                if(b==1)
                                    t1 += arr[1];
                                else
                                    t2 += arr[1];
                                if(c==1)
                                    t1 += arr[2];
                                else
                                    t2 += arr[2];
                                if(d==1)
                                    t1 += arr[3];
                                else
                                    t2 += arr[3];
                                if(e==1)
                                    t1 += arr[4];
                                else
                                    t2 += arr[4];
                                if(f==1)
                                    t1 += arr[5];
                                else
                                    t2 += arr[5];
                                ans = min(ans, abs(t1-t2));
                            }
                        }
                    }
                }
            }
        }
    } 
    cout << ans;
    return 0;
}