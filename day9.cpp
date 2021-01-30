#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;

int main(){
    string s = "";
    vector<ll>v; 
    string line;
    ifstream myfile ("C:\\Users\\RT\\Desktop\\advent.txt");
    ll i = 0;
    set<ll> se;
    while (getline (myfile,line)){
        if(i < 25){
            se.insert(stoll(line));
        }
        v.push_back(stoll(line));    
        i++;
    }
    for(ll i = 25; i < v.size(); ++i){
        ll truer = 0;
        for(auto x:se){
            if(se.find(abs(v[i] - x)) != se.end()){
                truer = 1;
                break;
            }
        }
        if(!truer){
            cout << v[i] << endl;
            ll idk = v[i];
            ll sum = 0, last = 0;
            for(ll i = 0; i < v.size(); ++i){
                if(idk == v[i])continue;
                else{
                    sum += v[i];
                    if(sum > idk){
                        while(sum > idk){
                            sum -= v[last];
                            last++;
                        }
                    }
                    if(sum == idk){
                        cout << *min_element(v.begin() + last, v.begin() + i) + *max_element(v.begin() + last, v.begin() + i) << endl;
                        return 0;
                    }
                }
            }
            return 0;
        }
        se.erase(v[i - 25]);
        se.insert(v[i]);
    }
    return 0;
}
