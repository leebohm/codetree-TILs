#include <iostream>

#define MAX_N 26

using namespace std;

int n;
int left_num[MAX_N], right_num[MAX_N];

void PreOrder(int x){
    if(x == -1)
        return;

    cout << (char) (x + 'A');
    PreOrder(left_num[x]);
    PreOrder(right_num[x]);
}

void InOrder(int x){
    if( x== -1)
        return;
    
    InOrder(left_num[x]);
    cout << (char) (x+'A');
    InOrder(right_num[x]);
}

void PostOrder(int x){
    if(x == -1)
        return;
    
    PostOrder(left_num[x]);
    PostOrder(right_num[x]);
    cout << (char) (x+'A');
}

int main(){
    cin >> n;

    for(int i = 0; i<n; i++)
        left_num[i] = right_num[i] = -1;

    for(int i=0; i<n; i++){
        char x, l, r;

        cin >> x >> l >> r;
        if(l != '.')
            left_num[x-'A'] = l-'A';
        if(r != '.')
            right_num[x-'A'] = r-'A';
    }

    PreOrder(0);
    cout << endl;

    InOrder(0);
    cout << endl;

    PostOrder(0);
    cout << endl;

    return 0;
}