#include<bits/stdc++.h>
#define out(x) cout<<x<<'\n'
using namespace std;
void solve(){
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<pair<string, vector<string>>> v(n);

    for(int i = 0; i < n; i++){
        // cin >> v[i].first;
        getline(cin,v[i].first);

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for(int j = 0; j < m; j++){
            string s;
            getline(cin,s);
            v[i].second.push_back(s);
        }
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> diseases(q);

    for(int i = 0; i < q; i++){
        getline(cin,diseases[i]);
    }

    vector<pair<string,double>> ans;

    for(int i = 0; i < n; i++){
        int m = v[i].second.size();
        int matched = 0;

        for(int j = 0; j < m; j++){
            if(find(diseases.begin(),diseases.end(),v[i].second[j]) != diseases.end()){
                matched++;
            }
        }

        // out(matched);
        double probability = (double) matched / (double)(m + q - matched);
        // out((m + q - matched));
        if(probability > 0) ans.push_back({v[i].first, probability});
        // cout<< v[i].first<< " -> "<< setprecision(2) << probability << '\n';
    }

    sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){

        if(a.second != b.second){
            return a.second > b.second;
        }

        if(a.second == 0){
            return false;
        }

        return a.first < b.first;
    });

    for(int i=0;i<n;i++){
        cout<< ans[i].first<< " -> "<< setprecision(2) << ans[i].second << '\n';
    }


}
int main()
{
    int t; cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}