#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string name;
    string last_name;
    int day;
    int month;
    int year;
};


int main(){
    int N,M;
    vector<Student> student_list;
    cin>>N;
    for(int i=0;i<N;++i){
        string name,last_name;
        int day,month,year;
        cin>>name>>last_name>>day>>month>>year;
        student_list.push_back({name,last_name,day,month,year});
    }
    cin>>M;
    for(int i=0;i<M;++i){
        string request;
        int idx;
        cin>>request>>idx;
        if(idx>0 && idx<=N){
            if(request=="name"){
            cout<<student_list[idx-1].name<<" "<<student_list[idx-1].last_name<<endl;
        }else if(request=="date"){
            cout<<student_list[idx-1].day<<"."<<student_list[idx-1].month<<"."<<student_list[idx-1].year<<endl;
        }
        else cout<<"bad request"<<endl;
        }else{
            cout<<"bad request"<<endl;
        }
    }
}