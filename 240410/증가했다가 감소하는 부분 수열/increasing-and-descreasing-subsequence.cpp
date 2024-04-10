#include <iostream>
#include <string>

#define MAX_N 1001
using namespace std;

int n;
int arr[MAX_N];
string str[MAX_N];
int dp[MAX_N];

void Output(){
    for(int i=0; i<n; i++)
        cout << str[i] << " ";
    cout << endl;
}

void Initialize(){
    for(int i=0; i<n; i++)
        str[i] = "notyet";
}

int main() {

    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    dp[0] = 1;

    Initialize();

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if((arr[i] > arr[j] && str[j] == "up") || (str[j] == "notyet" && arr[i] > arr[j])){
                dp[i] = max(dp[i], dp[j]+1);
                str[i] = "up";
            }
            else if(arr[i] < arr[j] && str[j] == "up"){
                dp[i] = max(dp[i], dp[j]+1);
                str[i] = "updown";
            }
            else if((arr[i] < arr[j] && str[j] == "down")||(str[j] == "notyet" && arr[i] < arr[j]) ||(arr[i] < arr[j] && str[j] == "updown")){
                if(str[j] == "updown")
                    str[i] = "updown";
                else 
                    str[i] = "down";
                dp[i] = max(dp[i], dp[j]+1);
            }
            else if(arr[i] > arr[j]){
                str[i] = "up";
                dp[i] = 2;
            }
            else if(arr[i] < arr[j]){
                str[i] = "down";
                dp[i] = 2;
            }

        }     
        //Output();   
    } 

    int ans = 0;
    for(int i=0; i<n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}