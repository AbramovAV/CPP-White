#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a,b,c;
    double x1,x2,D;
    cin>>a>>b>>c;
    D = b*b - 4*a*c;
    if(D<0){return 0;}
    if(a==0){
        if(b==0){
            return 0;
        }
        cout<< (-c/b);
        return 0;
    }

    x1 = (-b + sqrt(D))/(2*a);
    x2 = (-b - sqrt(D))/(2*a);
    if(x1!=x2){
        cout<<x1<<" "<<x2;
    } else{
        cout<<x1;
    }
    return 0;
}