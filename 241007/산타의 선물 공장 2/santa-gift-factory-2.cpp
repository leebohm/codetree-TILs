#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 100001
#define MAX_M 100001

using namespace std;

int n,m,q;

int prv[MAX_M], nxt[MAX_M];

int head[MAX_N], tail[MAX_N], num_gift[MAX_N];

void BuildFactory(){
    cin >> n >> m;

    vector<int> boxes[MAX_N];

    for(int id=1; id<=m; id++){
        int b_num;
        cin >> b_num;
        b_num--;
        boxes[b_num].push_back(id);
    }

    for(int i=0; i<n; i++){
        if((int) boxes[i].size() == 0)
            continue;
        
        head[i] = boxes[i].front();
        tail[i] = boxes[i].back();

        num_gift[i] = (int) boxes[i].size();

        for(int j=0; j<(int) boxes[i].size() - 1; j++){
            nxt[boxes[i][j]] = boxes[i][j+1];
            prv[boxes[i][j+1]] = boxes[i][j];
        }   
    }
}

void Move(){
    int m_src, m_dst;
    cin >> m_src >> m_dst;
    m_src--; m_dst--;

    if(num_gift[m_src]== 0){
        cout << num_gift[m_dst] << endl;
        return;
    }
    if(num_gift[m_dst]== 0){
        head[m_dst] = head[m_src];
        tail[m_dst] = tail[m_src];
    }
    else{
        int orig_head = head[m_dst];
        head[m_dst] = head[m_src];
        int src_tail = tail[m_src];
        nxt[src_tail] = orig_head;
        prv[orig_head] = src_tail;
    }

    head[m_src] = tail[m_src] = 0;

    num_gift[m_dst] += num_gift[m_src];
    num_gift[m_src] = 0;

    cout << num_gift[m_dst] << endl;
}

int RemoveHead(int b_num){
    if(num_gift[b_num] == 0)
        return 0;

    
    if(num_gift[b_num] == 1){
        int id = head[b_num];
        head[b_num] = tail[b_num] = 0;
        num_gift[b_num] = 0;
        return id;
    }

    int hid = head[b_num];
    int next_head = nxt[hid];
    nxt[hid] = prv[next_head] = 0;
    num_gift[b_num]--;
    head[b_num] = next_head;
    return hid;
}

void PushHead(int b_num, int hid){
    if(hid == 0)
        return ;

    if(!num_gift[b_num]){
        head[b_num] = tail[b_num] = hid;
        num_gift[b_num] = 1;
    }
    else{
        int orig_head = head[b_num];
        nxt[hid] = orig_head;
        prv[orig_head] = hid;
        head[b_num] = hid;
        num_gift[b_num]++;
    }
}

void Change(){
    int m_src, m_dst;
    cin >> m_src >> m_dst;
    m_src--; m_dst--;

    int src_head = RemoveHead(m_src);
    int dst_head = RemoveHead(m_dst);
    PushHead(m_dst, src_head);
    PushHead(m_src, dst_head);

    cout << num_gift[m_dst] << endl;
}

void Divide(){
    int m_src, m_dst;
    cin >> m_src >> m_dst;
    m_src--; m_dst--;

    int cnt = num_gift[m_src];
    vector<int> box_ids;
    for(int i=0; i<cnt /2; i++)
        box_ids.push_back(RemoveHead(m_src));
    
    for(int i=(int) box_ids.size() - 1; i >=0; i--)
        PushHead(m_dst, box_ids[i]);

    cout << num_gift[m_dst] << endl;
}

void GiftScore(){
    int p_num;
    cin >> p_num;

    int a = prv[p_num] != 0 ? prv[p_num] : -1;
    int b = nxt[p_num] != 0 ? nxt[p_num] : -1;

    cout << a + 2*b << endl;
}

void BeltScore(){
    int b_num;
    cin >> b_num;
    b_num--;

    int a = head[b_num] != 0 ? head[b_num] : -1;
    int b = tail[b_num] != 0 ? tail[b_num] : -1;
    int c = num_gift[b_num];

    cout << a + 2*b + 3*c << endl;
}

int main(){

    cin >> q;

    while(q--){
        int q_type;
        cin >> q_type;
        if(q_type == 100)
            BuildFactory();
        else if(q_type == 200)
            Move();
        else if(q_type == 300)
            Change();
        else if(q_type == 400)
            Divide();
        else if(q_type == 500)
            GiftScore();
        else
            BeltScore();
    }
    return 0;
}