#include <iostream>

using namespace std;

int n, x;
int arr[1000];

// 들어가는 최소 비용. 비용을 기록해야함.. 
// 최대 최소 높이차가 17이하가 되도록.
// 언덕 높이를 1부터 100까지로 가정하고 해야겠다. 
// 그러면 그 언덕 높이인게 적어도 한개는 잇어야하는거 아닌가. 
// 흠........ 

int main() {

    cin >> n;
    for(int i=0; i<n;i++)
        cin >> arr[i];

    int ans = 1e9;
    for(int i=0; i<n;i++){ // 설정한 언덕의 최대 높이 
        int cost = 0;
        for(int j=0;j<n;j++){
            if(i!= j){
                if((arr[i]-arr[j] <= 17) && (arr[i]-arr[j]>=0)){
                    continue;
                }
                else{
                    if(arr[i]<arr[j]){
                        int tmp = abs(arr[j] - arr[i]);
                        cost += tmp*tmp;  
                    }
                    else if ((arr[i]>arr[j])&&(abs(arr[i]-arr[j])>17)){
                        int tmp = abs(arr[j] - abs(arr[i]-17));
                        cost += tmp*tmp;  
                    }
                }
            
            }

        }
        ans = min(cost, ans);
        
}    

    cout << ans ;
    // 여기에 코드를 작성해주세요.
    return 0;
}