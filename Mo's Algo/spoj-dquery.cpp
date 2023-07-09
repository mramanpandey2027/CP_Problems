 // problem -> https://www.spoj.com/problems/DQUERY/ 

#include<bits/stdc++.h>
using namespace std;
 
#define fast      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define int long long

struct query {
    int l,r,ind; 
}; 

const int N = 1e6+10; 

int freq[N]; 

int32_t main(){
    fast; 

    int n;
    cin >> n; 
    
    vector<int> a(n);
    
    for(auto &it: a) cin >> it;  
        
        cout << n << '\n';
    
    int qn;
    cin >> qn;
    vector<query> q(qn);   
    
    for(int i=0;i<qn;i++){
        cin >> q[i].l >> q[i].r,q[i].ind=i; 
        q[i].l--,q[i].r--; 
    }
    
    int bucket = max((int)(sqrt(n)),1ll); 
    
    sort(q.begin(),q.end(),[&](query a,query b){
        if(a.l/bucket != b.l/bucket) return a.l < b.l; 
        return a.r < b.r; 
    });
    
    int l=0,r=0; 
    vector<int> ans(qn); 
    int cnt=0; 
    
    auto add = [&](int i){
        freq[a[i]]++; 
        if(freq[a[i]]==1) cnt++; 
    };
    
    auto del = [&](int i){
        freq[a[i]]--; 
        if(freq[a[i]]==0) cnt--; 
    };
    
    auto get_ans = [&](){
        return cnt; 
    };
    
    
    for(int i=0;i<qn;i++){
        while(l>q[i].l) add(--l);
        while(r<=q[i].r) add(r++); 
        while(l<q[i].l) del(l++); 
        while(r-1>q[i].r) del(--r); 
        ans[q[i].ind]= get_ans(); 
    }
    
    for(int i=0;i<qn;i++){
        cout << ans[i] << '\n';
    }

}