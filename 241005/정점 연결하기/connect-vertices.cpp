#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100001

int n;
int uf[MAX_N];
vector<int> vec;

int Find(int x){
    if(uf[x] == x)
        return x;
    return uf[x] = Find(uf[x]);
}
void Union(int x, int y){
    int rx = Find(x);
    int ry = Find(y);
    uf[rx] = ry;
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++)
        uf[i] = i;

    for(int i=0; i<n-2; i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    vec.push_back(1);

    int num = Find(1);
    
    for(int i=2; i<=n; i++){
        if(Find(i) != num)
            vec.push_back(i);
    }

    cout << vec[0] << " " << vec[1] <<endl;

    return 0;
}