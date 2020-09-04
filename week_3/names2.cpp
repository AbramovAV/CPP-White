#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year){
      string first_name,last_name;
    for(auto& item:first_names){
        if(item.first<=year && item.second.size()>0){
            first_name = item.second;
        } else break;
    }
    for(auto& item:last_names){
        if(item.first<=year && item.second.size()>0){
            last_name = item.second;
        } else break;
    }
    if(!first_name.size() && !last_name.size()){
        return "Incognito";
    }
    if(first_name.size()>0 && !last_name.size()){
        return first_name+" with unknown last name";
    }
    if(!first_name.size() && last_name.size()>0){
        return last_name+" with unknown first name";
    }
    if(first_name.size()>0 && last_name.size()>0){
        return first_name+" "+last_name;
    }
  }
  string GetFullNameWithHistory(int year) {
    string first_name,last_name;
    vector<string> log_first_names, log_last_names;
    for(auto& item:first_names){
        if(item.first<=year && item.second.size()>0){
            first_name = item.second;
            if(log_first_names.size()>0){
                if(log_first_names[log_first_names.size()-1]!=item.second)
                    log_first_names.push_back(item.second);
            } else{
                log_first_names.push_back(item.second);
            }
            }else break;
        }
    if(log_first_names.size()>0){
        log_first_names.resize(log_first_names.size()-1);
    }
    for(auto& item:last_names){
        if(item.first<=year && item.second.size()>0){
            last_name = item.second;
            if(log_last_names.size()>0){
                if(log_last_names[log_last_names.size()-1]!=item.second)
                    log_last_names.push_back(item.second);
            } else{
                log_last_names.push_back(item.second);
            }
            }else break;
    }
    if(log_last_names.size()>0){
        log_last_names.resize(log_last_names.size()-1);
    }
    reverse(begin(log_first_names),end(log_first_names));
    reverse(begin(log_last_names),end(log_last_names));
    string previous_names = "";
    string previous_last_names = "";
    for(int i=0;i<log_first_names.size();++i){
        if(i!=log_first_names.size()-1) previous_names+=log_first_names[i]+", ";
        else previous_names+=log_first_names[i];
    }
    for(int i=0;i<log_last_names.size();++i){
        if(i!=log_last_names.size()-1) previous_last_names+=log_last_names[i]+", ";
        else previous_last_names+=log_last_names[i];
    }
    if(previous_names.size()>0) previous_names = " ("+previous_names+") "; else previous_names = " ";
    if(previous_last_names.size()>0) previous_last_names = " ("+previous_last_names+") "; else previous_last_names = " ";
    if(!first_name.size() && !last_name.size()){
        return "Incognito";
    }
    if(first_name.size()>0 && !last_name.size()){
        return first_name+previous_names+"with unknown last name";
    }
    if(!first_name.size() && last_name.size()>0){
        return last_name+previous_last_names+"with unknown first name";
    }
    if(first_name.size()>0 && last_name.size()>0){
        string s = first_name+previous_names+last_name+previous_last_names;
        s.resize(s.size()-1);
        return s;
    }
  }
private:
  map<int,string> first_names;
  map<int,string> last_names;
};