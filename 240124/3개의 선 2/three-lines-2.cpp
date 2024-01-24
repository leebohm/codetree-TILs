#include <iostream>
#include <algorithm>

#define MAX_N 20
#define MAX_X 10

using namespace std;

int n;
int x[MAX_N], y[MAX_N];

int main() {
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i] ;
    
    int ans =0;

    for(int i=0; i<=MAX_X;i++)
        for(int j=0; j<=MAX_X;j++)
            for(int k=0; k<= MAX_X; k++){
                boo success = true;

                for(int l=0; l<n;l++){
                    if(x[l] == i || x[l] == j || x[l] ==k) continue;

                    success = false;
                }

                if(success) ans= 1;

                success= true;
                for(int l=0; l<n;l++){
                    if(x[l]==i || x[l]==j || y[l] ==k)
                        continue;

                    success = false;
                }
                if (success) ans =1;


                success= true;
                for(int l=0; l<n;l++){
                    if(x[l]==i || y[l]==j || y[l] ==k)
                        continue;

                    success = false;
                }

                if (success) ans =1;


                success= true;
                for(int l=0; l<n;l++){
                    if(y[l]==i || y[l]==j || y[l] ==k)
                        continue;

                    success = false;
                }

                if (success) ans =1;


            }
    cout << ans;
    return 0;
}