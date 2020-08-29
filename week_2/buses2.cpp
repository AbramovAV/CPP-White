#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int Q,num_stops;
    int new_route = 1;
    map<vector<string>,int> routes;
    cin>>Q;
    for(int i=0;i<Q;++i){
        cin>>num_stops;
        vector<string> stops(num_stops);
        for(string& stop:stops){
            cin>>stop;
        }
        if(routes[stops]>0){
            cout<<"Already exists for "<<routes[stops]<<endl;
        }else{
            routes[stops] = new_route;
            cout<<"New bus "<<new_route<<endl;
            ++new_route;
        }
    }
    return 0;
}