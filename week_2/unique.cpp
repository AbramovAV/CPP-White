#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    int num_strings;
    set<string> unique_strings;
    string unique_string;
    cin>>num_strings;
    for(int i=0;i<num_strings;++i){
        cin>>unique_string;
        unique_strings.insert(unique_string);
    }
    cout<<unique_strings.size()<<endl;
    return 0;
}