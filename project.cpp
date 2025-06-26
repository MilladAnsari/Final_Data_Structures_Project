#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " : " << x << '\n';


typedef long long ll;

const ll maxn = 5e5 + 5;


ll max_heap[maxn], min_heap[maxn];
string smx[maxn], smn[maxn]; 
ll cmn, cmx;

struct Node {
    ll sum, cnt_talab, cnt_bedeh;
    struct Node* child[60];
};

// Node* root;
struct Node* root = (struct Node*)malloc(sizeof(struct Node));

Node* make(string s){
    Node* cur = root;
    // cout << "S : " << s << endl;
    for(int i = 0; i < s.size(); i ++){
        int ind = s[i] - 'a';
        if((cur->child[ind]) == NULL){
            struct Node *Nd = (struct Node*)malloc(sizeof(struct Node));
            (cur->child[ind]) = Nd;
            (Nd->sum) = 0;
            (Nd->cnt_bedeh) = 0;
            (Nd->cnt_talab) = 0;
            for(int i = 0; i < 55; i ++)
                Nd->child[i] = NULL;
        }
        cur = (cur->child[ind]);
    }
    // cout << "sum : " << cur->sum << endl;
    return cur;
}


void add(Node* nd, string s, ll x){
    Node* cur = nd;
    for(int i = 0; i < s.size(); i ++){
        int ind = (s[i] - 'a') + 26;
        if(cur->child[ind] == NULL){
            struct Node *Nd = (struct Node*)malloc(sizeof(struct Node));
            cur->child[ind] = Nd;
            Nd->sum = 0;
            Nd->cnt_bedeh = 0;
            Nd->cnt_talab = 0;
            for(int i = 0; i < 55; i ++)
                Nd->child[i] = NULL;
        }
        cur = cur->child[ind];
    }
    if((cur->sum) > 0)
        (nd->cnt_bedeh) --;
    if((cur->sum) < 0)
        (nd->cnt_talab) --;
    (cur->sum) += x;
    if((cur->sum) > 0)
        (nd->cnt_bedeh) ++;
    if((cur->sum) < 0)
        (nd->cnt_talab) ++;
    (nd->sum) += x;
}

ll tabdil(string sx){
    ll res = 0;
    bool flag = 0;
    for(int i = 0; i < sx.size(); i ++){
        if(sx[i] == '.'){
            flag = 1;
            continue;
        }
        res = res * 10 + sx[i] - '0';
    }
    if(!flag)
        return res * 100;
    if(sx[sx.size() - 2] == '.')
        return res * 10;
    return res;
}

bool compare(string s0, string s1){
    for(int i = 0; i < min(s0.size(), s1.size()); i ++){
        if(s0[i] < s1[i])
            return 1;
        if(s0[i] > s1[i])
            return 0;
    }
    if(s0.size() < s1.size())
        return 1;
    return 0;
}

bool compare_min(ll i0, ll i1){
    if(min_heap[i0] < min_heap[i1])
        return 1;
    if(min_heap[i0] > min_heap[i1])
        return 0;
    return compare(smn[i0], smn[i1]);
}

bool compare_max(ll i0, ll i1){
    if(max_heap[i0] > max_heap[i1])
        return 1;
    if(max_heap[i0] < max_heap[i1])
        return 0;
    return compare(smx[i0], smx[i1]);
}

void swap_min(ll i0, ll i1){
    ll temp = min_heap[i0];
    min_heap[i0] = min_heap[i1];
    min_heap[i1] = temp;
    string temp_str = smn[i0];
    smn[i0] = smn[i1];
    smn[i1] = temp_str;
}

void swap_max(ll i0, ll i1){
    ll temp = max_heap[i0];
    max_heap[i0] = max_heap[i1];
    max_heap[i1] = temp;
    string temp_str = smx[i0];
    smx[i0] = smx[i1];
    smx[i1] = temp_str;
}

void add_min(ll x, string s){
    min_heap[cmn] = x;
    smn[cmn] = s;
    ll ind = cmn;
    while((ind > 1) && compare_min(ind, ind / 2)){
        swap_min(ind, ind / 2);
        ind /= 2;
    }
}

void add_max(ll x, string s){
    max_heap[cmx] = x;
    smx[cmx] = s;
    ll ind = cmx;
    while((ind > 1) && compare_max(ind, ind / 2)){
        swap_max(ind, ind / 2);
        ind /= 2;
    }
}

void add_heap(ll x, string s){
    cmn ++;
    add_min(x, s);
    cmx ++;
    add_max(x, s);
}

ll get_min(){
    while(cmn > 0 && ((make(smn[1])-> sum) != min_heap[1])){
        swap_min(1, cmn);
        min_heap[cmn] = 0;
        smn[cmn] = "";
        cmn --;
        ll ind = 1;
        while(true){
            if(smn[ind * 2] == "")
                break;
            if(smn[ind * 2 + 1] == ""){
                if(compare_min(ind * 2, ind)){
                    swap_min(ind, ind * 2);
                    ind *= 2;
                    continue; 
                }
                break;
            }
            if(compare_min(ind * 2, ind * 2 + 1)){
                if(compare_min(ind * 2, ind)){
                    swap_min(ind, ind * 2);
                    ind *= 2;   
                    continue; 
                }
                else
                    break;
            }
            if(compare_min(ind * 2 + 1, ind * 2)){
                if(compare_min(ind * 2 + 1, ind)){
                    swap_min(ind, ind * 2 + 1);
                    ind *= 2;  ind ++;
                    continue; 
                }
                else
                    break;
            }
            if(compare_min(ind * 2, ind)){
                swap_min(ind, ind * 2);
                ind *= 2;   
                continue; 
            }
            else
                break;        
        }
    }
    return min_heap[1];
}

ll get_max(){
    while(cmx> 0 && (make(smx[1])-> sum) != max_heap[1]){
        swap_max(1, cmx);
        max_heap[cmx] = 0;
        smx[cmx] = "";
        cmx --;
        ll ind = 1;
        while(true){
            if(smx[ind * 2] == "")
                break;
            if(smx[ind * 2 + 1] == ""){
                if(compare_max(ind * 2, ind)){
                    swap_max(ind, ind * 2);
                    ind *= 2;
                    continue; 
                }
                break;
            }
            if(compare_max(ind * 2, ind * 2 + 1)){
                if(compare_max(ind * 2, ind)){
                    swap_max(ind, ind * 2);
                    ind *= 2;   
                    continue; 
                }
                else
                    break;
            }
            if(compare_max(ind * 2 + 1, ind * 2)){
                if(compare_max(ind * 2 + 1, ind)){
                    swap_max(ind, ind * 2 + 1);
                    ind *= 2;  ind ++;
                    continue; 
                }
                else
                    break;
            }
            if(compare_max(ind * 2, ind)){
                swap_max(ind, ind * 2);
                ind *= 2;   
                continue; 
            }
            else
                break;        
        }
    }
    return max_heap[1];
}

set<pair<ll, string>> st, st2;

int main(){
    for(int i = 0; i < 55; i ++)
                root->child[i] = NULL;
    int q; cin >> q;
    while(q --){
        int query; cin >> query;
        if(query == 1){
            string s0, s1; cin >> s0 >> s1;
            string sx; cin >> sx;
            ll x = tabdil(sx);
            Node* n0 = make(s0);
            Node* n1 = make(s1);
            add(n0, s1, -x);
            add_heap(n0->sum, s0);
            add(n1, s0, x);
            add_heap(n1->sum, s1);
            // for(int i = 1; i <= cmn; i ++)
            //     cout << min_heap[i] << smn[i] << pakmn[i] << ' ';
            // cout << endl;
            continue;
        }
        if(query == 2){
            // continue;
            ll x = get_max();
            if(x == 0)
                cout << "-1\n";
            else
                cout << smx[1] << '\n';
            continue;
        }
        if(query == 3){
            // continue;
            ll x = get_min();
            if(x == 0)
                cout << "-1\n";
            else
                cout << smn[1] << '\n';
            continue;
        }
        // continue;
        if(query == 4){
            string s0; cin >> s0;
            cout << ((make(s0))->cnt_bedeh) << '\n';           
        }
        if(query == 5){
            string s0; cin >> s0;
            cout << ((make(s0))->cnt_talab) << '\n';           
        }
        if(query == 6){
            string s0, s; cin >> s0 >> s;
            // continue ;
            Node* n0 = make(s0);
            Node* cur = n0;
            for(int i = 0; i < s.size(); i ++){
                int ind = s[i] - 'a' + 26;
                if(cur->child[ind] == NULL){
                    struct Node *Nd = (struct Node*)malloc(sizeof(struct Node));
                    cur->child[ind] = Nd;
                    Nd->sum = 0;
                    Nd->cnt_bedeh = 0; Nd->cnt_talab = 0;
                    for(int i = 0; i < 55; i ++)
                        Nd->child[i] = NULL;
                }
                cur = cur->child[ind];
            }
            cout << fixed << setprecision(2) << (long double)(cur->sum) / 100.0 << '\n';
        }
    }
}