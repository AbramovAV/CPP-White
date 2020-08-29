#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char,int> BuildCharCounters(string word){
    map<char,int>letters;
    for(char w:word){
        letters[w]++;
    }
    return letters;
}

int main(){
    int N;
    string first,second;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>first>>second;
        if(BuildCharCounters(first)==BuildCharCounters(second)){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}