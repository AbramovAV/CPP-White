#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

void Count(map<string,set<string>>& synonyms,string word){
    if(!synonyms.count(word)){
        cout<<0<<endl;
    }else{
        int counter = 0;
        for(auto synonym:synonyms[word]){
            ++counter;
        }
        cout<<counter<<endl;
    }
}

void Add(map<string,set<string>>& synonyms,string word1, string word2){
    synonyms[word1].insert(word2);
    synonyms[word2].insert(word1);
}

void Check(map<string,set<string>>& synonyms,string word1, string word2){
    for(auto synonym:synonyms[word1]){
        if(synonym==word2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int Q;
    string command,first_arg,second_arg;
    map<string,set<string>> synonyms;
    cin>>Q;
    for(int i=0;i<Q;++i){
        cin>>command;
        if(command=="COUNT"){
            cin>>first_arg;
            Count(synonyms,first_arg);
        }
        if(command=="ADD"){
            cin>>first_arg>>second_arg;
            Add(synonyms,first_arg,second_arg);
        }
        if(command=="CHECK"){
            cin>>first_arg>>second_arg;
            Check(synonyms,first_arg,second_arg);
        }
    }
}