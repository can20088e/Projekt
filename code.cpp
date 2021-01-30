#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
    ll n, suma = 100, ct = 0; 
    cin >> n;
    while(1){
        suma += suma / 100;
        ct++;
        if(suma >= n){
            break;
        }
    }   
    cout << ct;
    return 0; 
 
}