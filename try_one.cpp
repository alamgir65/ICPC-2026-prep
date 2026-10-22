#include<bits/stdc++.h>
#define out(x) cout<<x<<'\n'
using namespace std;
void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto &it:a) cin>>it;
    vector<int> track(n,0);
    for(int i=n-1;i>=1;i--){
        if(a[i]-a[i-1] >= 2){
            if(i == n-1) track[i]=1;
            else track[i] = track[i+1]+1;
        }
    }

    for(int i=0;i<n;i++){
        if(i<n-1 && a[i+1]-a[i] >= 2) cout<<track[i+1]+1<<"\n";
        else cout<<0<<"\n";
    }
}
int main()
{
    int t=1;
    for(int i=1; i<=t; i++){
        //cout<<"Case "<<i<<":\n";
        solve();
        // hudai update kore labh nai
    }
    return 0;
}
