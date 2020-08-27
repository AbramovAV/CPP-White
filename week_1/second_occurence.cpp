#include <iostream>
#include <string>

using namespace std;

int main(){
    string f;
    int counter=-2;
    int index=0;
    cin>>f;
    for(auto c:f){
        if(c=='f'){
            counter++;
            if(counter==0){
                cout<<index;
                return 0;
            }
        }
        index++;
    }
    cout<<counter;
    return 0;
}