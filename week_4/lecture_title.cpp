#include <string>

using namespace std;

struct Specialization
{
    string value;
    explicit Specialization(string s){
        value = s;
    }
};

struct Course
{
    string value;
    explicit Course(string c){
        value = c;
    }
};

struct Week
{
    string value;
    explicit Week(string w){
        value = w;
    }
};

struct LectureTitle
{
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization s, Course c, Week w){
        specialization = s.value;
        course = c.value;
        week = w.value;
    }
};

