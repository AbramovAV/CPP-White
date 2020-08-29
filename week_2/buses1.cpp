#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void AllBuses(const map<string,vector<string>> buses){
    int num_buses = 0;
    for(auto item:buses){
        cout<<"Bus "<<item.first<<": ";
        num_buses++;
        for(auto stop:item.second){
            cout<<stop<<" ";
        }
        cout<<endl;
    }
    if(!num_buses) cout<<"No buses"<<endl;
}

void StopForBus(map<string,vector<string>>& buses,map<string,vector<string>>& stops,string bus){
    if(!buses.count(bus)) cout<<"No bus"<<endl;
    else{
    for(auto stop:buses[bus]){
        cout<<"Stop "<<stop<<": ";
        int num_buses = 0;
        for(auto bus_per_stop:stops[stop]){
            if(bus_per_stop!=bus){
                cout<<bus_per_stop<<" ";
                ++num_buses;
            }
        }
        if(!num_buses) cout<<"no interchange";
        cout<<endl;
    }
    }
}

void BusesForStop(map<string,vector<string>>& stops,string stop){
    if(!stops.count(stop)) cout<<"No stop"<<endl;
    else{
    for(auto bus:stops[stop]){
        cout<<bus<<" ";
    }
    cout<<endl;
    }
}

void NewBus(map<string,vector<string>>& buses,map<string,vector<string>>& stops,string bus, vector<string>new_stops){
    for(auto new_stop:new_stops){
        buses[bus].push_back(new_stop);
        stops[new_stop].push_back(bus);
    }
}

int main(){
    int num_requests,second_arg;
    string command,first_arg;
    map<string,vector<string>> buses;
    map<string,vector<string>> stops;
    cin>>num_requests;
    for(int i=0;i<num_requests;++i){
        cin>>command;
        if(command=="ALL_BUSES"){
            AllBuses(buses);
        }
        if(command=="STOPS_FOR_BUS"){
            cin>>first_arg;
            StopForBus(buses,stops,first_arg);
        }
        if(command=="BUSES_FOR_STOP"){
            cin>>first_arg;
            BusesForStop(stops,first_arg);
        }
        if(command=="NEW_BUS"){
            cin>>first_arg>>second_arg;
            vector<string> stops_per_bus(second_arg);
            for(string& stop:stops_per_bus){
                cin>>stop;
            }
            NewBus(buses,stops,first_arg,stops_per_bus);
        }
    }
    return 0;
}