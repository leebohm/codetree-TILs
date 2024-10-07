#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdlib>

#define MAX_N 100

using namespace std;

int n,k;

int arr[MAX_N];

int temp[MAX_N];

int elapsed_time;

void AddOne(){
    int min_val = INT_MAX;
    for(int i=0; i<n; i++)
        min_val = min(min_val, arr[i]);
    
    for(int i=0; i<n; i++)
        if(arr[i] == min_val)
            arr[i]++;
}

void Rotate(vector<pair<int,int> > &flours, int row_num, int col_num){
    for(int i=0; i<n; i++){
        int x,y;
        tie(x,y) = flours[i];
        flours[i] = make_pair(y, row_num - x + 1);
    }
}

vector<pair<int, int> > RollUp(){
    vector<pair<int, int> > flours(n);

    flours[0] = make_pair(1,1);
    flours[1] = make_pair(2,1);
    int row_num = 2, col_num = 1;

    int s_index = 2;

    while(s_index + row_num <= n){
        Rotate(flours, row_num, col_num);

        for(int i=1; i<= row_num; i++)
            flours[s_index++] = make_pair(col_num+1, i);
        
        if(row_num == col_num + 1)
            col_num++;
        else
            row_num++;
    }

    int delta = 1;
    while(s_index < n){
        flours[s_index++] = make_pair(row_num, col_num + delta);
        delta++;
    }
    return flours;
}

void ReArrange(vector<pair<int, int> > flours){
    for(int i=0; i<n; i++)
        temp[i] = 0;
    
    vector<tuple <int,int,int > > extended_flours;

    for(int i=0; i<n; i++){
        int x,y;
        tie(x,y) = flours[i];
        extended_flours.push_back(make_tuple(y,-x,i));
    }
    sort(extended_flours.begin(), extended_flours.end());

    for(int i=0; i<n; i++){
        int prev_index;
        tie(ignore, ignore, prev_index) = extended_flours[i];
        temp[i] = arr[prev_index];
    }

    for(int i=0; i<n; i++)
        arr[i] = temp[i];
}

bool Adjacency(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2) == 1;
}

void Press(vector<pair<int,int > > flours){
    for(int i=0; i<n; i++)
        temp[i] = arr[i];
    
    for(int i=0; i<n; i++){
        for(int j= i+1; j<n; j++){
            int x1, y1, x2, y2;
            tie(x1, y1) = flours[i];
            tie(x2, y2) = flours[j];
            if(Adjacency(x1, y1, x2, y2)){
                if(arr[i] > arr[j]){
                    temp[i] -= (arr[i] - arr[j]) / 5;
                    temp[j] += (arr[i] - arr[j]) / 5;
                }
                else{
                    temp[i] += (arr[j] - arr[i]) / 5;
                    temp[j] -= (arr[j] - arr[i]) / 5;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
        arr[i] = temp[i];
    
    ReArrange(flours);
}

vector<pair<int, int> > Fold(){
    vector<pair<int,int> > flours(n);

    for(int i=0; i<n/2; i++)
        flours[i] = make_pair(1, n/2-i);
    
    for(int i=n/2; i<n; i++)
        flours[i] = make_pair(2, i-(n/2) + 1);
    
    for(int i=0; i<n; i++){
        int x,y;
        tie(x,y) = flours[i];
        if(y <= n / 4)
            flours[i] = make_pair(3-x, n/4 - y+1);
        else
            flours[i] = make_pair(x+2, y-n/4);
    }
    return flours;
}

void Simulate(){
    AddOne();

    vector<pair<int,int> > flours = RollUp();

    Press(flours);

    flours = Fold();

    Press(flours);

    elapsed_time++;
}

bool End(){
    
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    for(int i=0; i<n; i++){
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    return max_val - min_val <= k;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    while(!End())
        Simulate();
    
    cout << elapsed_time;

    return 0;
}