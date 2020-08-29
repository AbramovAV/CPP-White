#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    int Q,num_stops;
    int new_route = 1;
    map<set<string>,int> routes;
    string stop;
    cin>>Q;
    for(int i=0;i<Q;++i){
        cin>>num_stops;
        set<string> stops;
        for(int i=0;i<num_stops;++i){
            cin>>stop;
            stops.insert(stop);
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