#include <iostream>
#include <climits>

using namespace std;

#define MAX_MIN -10000000

int n,m;
int arr1[5][5];
int arr2[5][5];

int GetBoxSum(int i, int j, int p, int q){
    int boxsum = 0; 
    for(int x = i; x<=p; x++)
        for(int y = j ; y <= q; y++){
            if(arr2[x][y]!= 1001){
                boxsum += arr2[x][y];
                //cout << boxsum << " ";
                arr2[x][y] = 1001;
            }
            else return MAX_MIN;         
        }
    return boxsum;
}

void save_arr(){
    for(int i= 0; i<n; i++)
        for(int j=0; j<m; j++)
            arr2[i][j] = arr1[i][j];
}

int main() {

    cin >> n >> m;

    for(int i=0; i<n;i++)
        for(int j=0; j<m; j++)
            cin >> arr1[i][j];
    
    int ans = MAX_MIN;
    for(int num = 1; num <=2; num++){
        int box1 = 0; 
        int box2 = 0;
        int box_sum = 0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                for(int p = i; p <n; p++){
                    for(int q = j; q<m; q++){

                        for(int a=0; a<n; a++){
                            for(int b= 0; b<m; b++){
                                for(int c=a; c<n; c++){
                                    for(int d=b; d<m; d++){
                                        //cout << i <<" " << j <<" " <<p << " " <<q <<" " <<a << " " << b << " " << c <<" " <<d << endl;
                                        save_arr();
                                        box1 = GetBoxSum(i,j,p,q);
                                        box2 = GetBoxSum(a,b,c,d);
                                        if(box1 == MAX_MIN || box2 == MAX_MIN) continue;
                                        //if (box2 == 0) cout << a <<" " << b <<" " << c << " " << d << "  ";
                                        //cout << box1 << " " << box2 << "  ";
                                        box_sum = box1+box2;
                                        ans = max(ans,box_sum);
                                        //cout << ans << " ";
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
        }
    }

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}