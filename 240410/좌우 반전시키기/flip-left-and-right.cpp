#include <iostream>

using namespace std;

#define MAX_N 102
int n;
int arr[MAX_N];

int change(int a){
    if(a == 1)
        return 0;
    else
        return 1;
}
void Output(){
    for(int i=1; i<=n; i++)
        cout << arr[i] <<" ";
    cout << endl;
}
int main() {
    
    cin >> n;
    
    for(int i = 1; i<=n; i++)
        cin >> arr[i];
    
    int ans = 0;

    for(int i = 2; i<=n; i++){
        if(arr[i-1] == 0){
            ans++;
            arr[i-1] = 1;
            int tmp = change(arr[i]);
            arr[i] = tmp;
            tmp = change(arr[i+1]);
            arr[i+1] = tmp;
        }
        //Output();
    }
    bool flag = true;
    for(int i=1; i<=n; i++){
        if(arr[i] == 0)
            flag = false;
    }

    if(flag == true)
        cout << ans;
    else
        cout << -1;
    
    // 여기에 코드를 작성해주세요.
    return 0;
}