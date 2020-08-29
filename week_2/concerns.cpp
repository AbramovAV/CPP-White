#include <iostream>
#include <vector>
#include <string>

using namespace std;

void AddConcern(vector<vector<string>>& concerns, int day,string concern){
    for(auto c:concerns[day-1]){
        if(c==concern) return;
    }
    concerns[day-1].push_back(concern);
}

void DumpConcern(const vector<vector<string>>& concerns, int day){
    cout<<concerns[day-1].size()<<" ";
    for(auto concern:concerns[day-1]){
        cout<<concern<<" ";
    }
    cout<<endl;
}

void NextConcernsList(vector<vector<string>>& concerns, int days){
    if(days<concerns.size()){
        for(int i=days;i<concerns.size();++i){
            concerns[days-1].insert(end(concerns[days-1]),begin(concerns[i]),end(concerns[i]));
        }
    }
    concerns.resize(days);
}

int main(){
    int Q,day;
    string concern;
    string command;
    const vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
    int current_days = 0;//starting from January
    vector<vector<string>> concerns(days[current_days]);
    cin>>Q;
    for(int i=0;i<Q;++i){
        cin>>command;
        if(command=="NEXT"){
            if(current_days<11) current_days++;
            else current_days=0;
            NextConcernsList(concerns,days[current_days]);
        }
        if(command=="DUMP"){
            cin>>day;
            DumpConcern(concerns,day);
        }
        if(command=="ADD"){
            cin>>day>>concern;
            AddConcern(concerns,day,concern);
        }
    }
    return 0;
}