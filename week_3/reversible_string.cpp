#include <string>
#include <iostream>

using namespace std;

class ReversibleString{
    public:
        ReversibleString(){
            s="";
        }
        ReversibleString(const string& str){
            s = str;
        }
        void Reverse(){
            string reversed_s;
            for(int i=s.size()-1;i>=0;--i){//could use std::reverse from algorithm
                reversed_s+=s[i];
            }
            s = reversed_s;
        }
        string ToString() const{
            return s;
        }
    private:
        string s;
};
