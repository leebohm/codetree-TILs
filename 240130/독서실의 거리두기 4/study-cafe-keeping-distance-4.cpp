// #include <iostream>
// #include <string>

// using namespace std;

// string str;
// int n;

// int main() {

//     cin >> n;
//     cin >> str;
    
//     int ans =0;
//     for(int i=0; i<n-1;i++)
//         for(int j=i+1; j<n;j++){
//             string temp = str;
//             if(temp[i]!='1' && temp[j]!='1'){
//                 temp[i]='1', temp[j]='1';

//                 int num = 1; 
//                 int ch = 1e9;
//                 bool flag = true;
//                 for(int k=0; k<n;k++){
//                     if(temp[k]=='0') num++;
//                     else if(temp[k]=='1'){
//                         if(k==0) continue;
//                         else if(num!=1) {
//                             ch=min(ch,num);
//                             num =1;
//                         }
//                         else if(num == 1){
//                             ch=min(ch,num);
//                         }
//                         else if(temp[k-1]=='1') {
//                             flag = false;
//                             break;
//                             ch=0;
//                             }
                         
                        
//                     }
//                 }
//                 if(flag) {
//                     ans = max(ch,ans);
//                     }
//             }
//             else continue;
            
//         }
    
//     cout << ans;
//     // 여기에 코드를 작성해주세요.
//     return 0;
// }


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string seat;

int MinDist() {
    int min_dist = n;
    for(int i=0; i<n;i++)
        for(int j=i+1; j<n;j++)
            if(seat[i] =='1' && seat[j] =='1')
                min_dist = min(min_dist,j-i);
    
    return min_dist;
}

int main(){
    cin >> n;
    cin >> seat;
    int ans =0;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(seat[i] == '0' && seat[j] =='0'){
                seat[i] = seat[j] = '1';
                ans = max(ans, MinDist());
                seat[i] = seat[j] = '0';
            }
    cout << ans;
    return 0;
}