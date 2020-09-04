#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string ToLowerString(string s){
    string lower_case_str;
    for(auto c:s) lower_case_str+=tolower(c);
    return lower_case_str;
}

int main(){
    int N;
    cin>>N;
    vector<string> strings(N);
    for(auto& s:strings){
        cin>>s;
    }
    sort(begin(strings),end(strings),[](string s1,string s2){
        return ToLowerString(s1)<ToLowerString(s2);//can be solved with std::lexicographical_compare
    });
    for(auto& s:strings){
        cout<<s<<" ";
    }
    return 0;
}