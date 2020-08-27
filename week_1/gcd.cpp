#include <iostream>

using namespace std;

int main(){
    int a,b,buffer;
    cin>>a>>b;
    if(a<b){
        buffer=b;
        b=a;
        a=buffer;
    }
    while(a%b!=0){
        buffer=a%b;
        a=b;
        b=buffer;
    }
    cout<<b;
    return 0;
}