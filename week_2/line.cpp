#include <vector>
#include <iostream>

using namespace std;

void SetWorried(vector<bool>& line,int idx){
    line[idx] = 1;
}

void SetQuiet(vector<bool>& line, int idx){
    line[idx] = 0;
}

void AddPeople(vector<bool>& line,int amount){
    line.resize(line.size()+amount,0);
}

void RemovePeople(vector<bool>& line,int amount){
    line.resize(line.size()+amount);
}

void CountWorried(const vector<bool>& line){
    int worried = 0;
    for(auto people:line){
        if (people) ++worried;
    }
    cout<<worried<<endl;
}

int main(){
    int Q,num;
    string command;
    vector<bool>line;//1 - if worried, otherwise - 0
    cin>>Q;
    for(int i=0;i<Q;++i){
        cin>>command;
        if(command=="WORRY_COUNT"){
            CountWorried(line);
        }else cin>>num;
        if(command=="COME" && num<0){
            RemovePeople(line,num);
        }
        if(command=="COME" && num>=0){
            AddPeople(line,num);
        }
        if(command=="WORRY"){
            SetWorried(line,num);
        }
        if(command=="QUIET"){
            SetQuiet(line,num);
        }
        
    }
    return 0;
}