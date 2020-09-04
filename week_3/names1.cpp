#include <map>
#include <string>
#include <iostream>

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
private:
  map<int,string> first_names;
  map<int,string> last_names;
};
