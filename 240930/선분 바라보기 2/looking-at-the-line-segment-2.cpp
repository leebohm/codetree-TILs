#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<tuple<int,int,int,int> > points;
// x, +1/1, y, idx 를 의미

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++){
        int x1, x2, y;
        cin >> y >> x1 >> x2;
        points.push_back(make_tuple(x1,1,y,i));
        points.push_back(make_tuple(x2,-1,y,i));
    }
    sort(points.begin(), points.end());

    int h = INT_MAX;
    int ans = 0;
    for(int i=0; i<2*n; i++){
        int x,v,y,idx;
        tie(x,v,y,idx) = points[i];
        if(v == 1 && h > y){
            h = y;
            ans += 1;
        }
        else if(v == -1){
            int prev_x, prev_v, prev_y;
            tie(prev_x, prev_v, prev_y, ignore) = points[i-1];
            if(prev_x < x && prev_v == 1 && prev_y > y){
                h = prev_y;
                ans++;
            }
            else
                h = INT_MAX;
        }
        //cout << h << " " << x << " " << ans << endl;
    }

    cout << ans;

    return 0;
}

/*
선분 바라보기2
좌표평면 위에 x축에 평행한 서로 다른 선분이 n개 주어집니다.
각 선분을 이루는 양쪽 끝 점의 x 좌표들은 모두 다르며 
선분마다 서로 다른 색이 칠해져있습니다.
이때 y 값이 아주 작은 지점 (원점으로부터 아래 방향으로 아주 멀리 떨어져 있는 지점)에서 
바라봤을 때 보이는 서로 다른 색깔의 수를 구하는 프로그램을 작성해보세요

시발 이걸 어떻게 구하나
아니..
이거 ..
규칙이 뭔지도 모르겠음
선분 시작하면 +1
또 선분 시작하면 근데 원래 y값 보다 작으면 +1 
선분 끝나면 뭐 없음.. 아 근데 이전 y 값을 알고 잇어야 할 것 같은데
이전 y값이 더 크면 아니 당연히 더 크겟지
이전 Y 값으로 높이 update 하고, 또 +1 해야하나? 만약 그게 시작점이면 +1
또 시작점 나옴 높이 값이 작으면 +1
끝값 나옴 끝값의 높이가 현재 높이보다 크면 그냥 패스 
*/