#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <sstream>
#include <exception>

using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
  Date(int y, int m, int d){
     year = y;
     month = m;
     day = d;
  }
  int GetYear() const{
    return year;
  }
  int GetMonth() const{
    return month;
  }
  int GetDay() const{
    return day;
  }
private:
  int day,month,year;
};

bool operator<(const Date& lhs, const Date& rhs){
  return (lhs.GetYear()<rhs.GetYear()) || 
         (lhs.GetYear()==rhs.GetYear() && lhs.GetMonth()<rhs.GetMonth()) ||
         (lhs.GetYear()==rhs.GetYear() && lhs.GetMonth()==rhs.GetMonth() && lhs.GetDay()<rhs.GetDay());
}

class Database {
public:
  void AddEvent(const Date& date, const string& event){
    events[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event){
    if(events.count(date)>0 && events[date].count(event)>0){
      events[date].erase(event);
      return true;
    }else return false;
  }
  int DeleteDate(const Date& date){
    int N;
    if(events.count(date)>0){
      N = events[date].size();
      events.erase(date);
    }else N=0;
    return N;
  }

  void Find(const Date& date) const{
    if(events.count(date)>0){
      for(auto& event:events.at(date)){
        cout<<event<<endl;
      }
    }
  }
  
  void Print() const{
    for(auto& item:events){
      for(auto& event:item.second){
        cout<<setw(4)<<setfill('0')<<item.first.GetYear()<<"-"<<
        setw(2)<<setfill('0')<<item.first.GetMonth()<<"-"<<
        setw(2)<<setfill('0')<<item.first.GetDay()<<" "<<event<<endl;
      }
    }
  }
private:
  map<Date,set<string>> events;
};

int main() {
  Database db;
    
  string command;
  const set<string> commands = {"Add","Del","Find","Print",""};
  while (getline(cin, command)) {
    try{
    istringstream input(command);
    string com,date,event;
    int year,month,day;
    input>>com;
    if(commands.count(com)==0){
      throw invalid_argument("Unknown command: "+com);
    }else if(command=="") continue;
    else if(com=="Print"){
      db.Print();
      continue;
    }
    input>>date;
    istringstream input_date(date);
    input_date>>year;
    input_date.ignore(1);
    input_date>>month;
    input_date.ignore(1);
    input_date>>day;
    if(input_date.fail() || !input_date.eof()){
      throw invalid_argument("Wrong date format: "+date);
    }else if(month<1 || month>12){
      throw invalid_argument("Month value is invalid: "+to_string(month));
    }else if(day<1 || day>31){
      throw invalid_argument("Day value is invalid: "+to_string(day));
    }
    input>>event;
    if(com=="Add"){
      db.AddEvent({year,month,day},event);
    }
    if(com=="Del"){
      if(event==""){
        int N = db.DeleteDate({year,month,day});
        cout<<"Deleted "<<N<<" events"<<endl;
      }else{
        if(db.DeleteEvent({year,month,day},event)) cout<<"Deleted successfully"<<endl;
        else cout<<"Event not found"<<endl;
      }
    }
    if(com=="Find"){
      db.Find({year,month,day});
    }
    } catch(invalid_argument& e){
      cout<<e.what()<<endl;
      break;
    }
  }

  return 0;
}