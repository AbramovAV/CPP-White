#include <iostream>
#include <string>
#include <map>

using namespace std;

void Dump(const map<string,string>& countries){
    int num_countries;
    for(auto item:countries){
        cout<<item.first<<"/"<<item.second<<endl;
        ++num_countries;
    }
    if(!num_countries) cout<<"There are no countries in the world"<<endl;
}

void About(map<string,string>& countries,string country){
    if(!countries.count(country)){
        cout<<"Country "<<country<<" doesn't exist"<<endl;
    }else{
        cout<<"Country "<<country<<" has capital "<<countries[country]<<endl;
    }
}

void ChangeCapital(map<string,string>& countries,string country, string new_capital){
    if(countries[country]==""){
        countries[country]=new_capital;
        cout<<"Introduce new country "<<country<<" with capital "<<new_capital<<endl;
    }else if(countries[country]==new_capital){
        cout<<"Country "<<country<<" hasn't changed its capital"<<endl;
    }else{
        cout<<"Country "<<country<<" has changed its capital from "<<countries[country]<<" to "<<new_capital<<endl;
        countries[country]=new_capital;
    }
}

void Rename(map<string,string>& countries, string old_country, string new_country){
    if(!countries.count(old_country) || old_country==new_country || countries.count(new_country)>0){
        cout<<"Incorrect rename, skip"<<endl;
    }else{
        cout<<"Country "<<old_country<<" with capital "<<countries[old_country]<<" has been renamed to "<<new_country<<endl;
        countries[new_country]=countries[old_country];
        countries.erase(old_country);
    }
}

int main(){
    int num_requests;
    map<string,string>countries;
    string command,first_arg,second_arg;
    cin>>num_requests;
    for(int i=0;i<num_requests;++i){
        cin>>command;
        if(command=="DUMP"){
            Dump(countries);
        }
        if(command=="ABOUT"){
            cin>>first_arg;
            About(countries,first_arg);
        }
        if(command=="CHANGE_CAPITAL"){
            cin>>first_arg>>second_arg;
            ChangeCapital(countries,first_arg,second_arg);
        }
        if(command=="RENAME"){
            cin>>first_arg>>second_arg;
            Rename(countries,first_arg,second_arg);
        }
    }
    return 0;
}