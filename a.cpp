#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    string L,N1,N2;
    cin>>L;
    ll a, b,c;
    int y=L.size();
    vector<vector<int>> dpgu(y, vector<int>(10, 0));
    vector<vector<int>> dpki(y, vector<int>(10, 0));
    vector<pair<int, int>> dp(y);
    for(int i=0;i<y;i++){
        dp[i]=make_pair(L[i]-'0', i);
    }
    sort(dp.begin(), dp.end());

    while(true){
        
    }
}