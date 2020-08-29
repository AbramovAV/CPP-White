#include <set>
#include <map>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int,string>& m){
    set<string> s;
    for(auto item:m){
        s.insert(item.second);
    }
    return s;
}