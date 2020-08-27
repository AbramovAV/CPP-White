#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> digits;
    cin>>n;
    while(n>1){
        digits.push_back(n%2);
        n/=2;
    }
    digits.push_back(n);
    for (int i=digits.size()-1;i>=0;--i){
        cout<<digits[i];
    }
    return 0;
}