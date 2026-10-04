#include<bits/stdc++.h>
#define out(x) cout << x << '\n'

using namespace std;

void solve(){

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<pair<string, vector<string>>> v(n);

    for(int i = 0; i < n; i++){

        getline(cin, v[i].first);

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for(int j = 0; j < m; j++){

            string s;
            getline(cin, s);

            v[i].second.push_back(s);
        }
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> diseases(q);

    for(int i = 0; i < q; i++){
        getline(cin, diseases[i]);
    }

    vector<pair<string, double>> ans;

    for(int i = 0; i < n; i++){

        int m = v[i].second.size();
        int matched = 0;

        for(int j = 0; j < m; j++){

            if(find(diseases.begin(),
                    diseases.end(),
                    v[i].second[j]) != diseases.end()){

                matched++;
            }
        }

        double denominator = m + q - matched;

        // Avoid division by zero
        if(denominator == 0)
            continue;

        double probability =
            (double)matched / denominator;

        // Ignore probability 0
        if(probability > 0){
            ans.push_back({
                v[i].first,
                probability
            });
        }
    }

    sort(ans.begin(), ans.end(),
        [](const auto &a, const auto &b){

            if(a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        }
    );

    for(auto &x : ans){

        cout << x.first << " -> "
             << fixed << setprecision(2)
             << x.second << '\n';
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++){

        cout << "Case " << tc << ":\n";

        solve();
    }

    return 0;
}