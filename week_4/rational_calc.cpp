#include <iostream>
#include <numeric>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator){
        if(denominator==0) throw logic_error("Invalid argument");
        if(numerator==0) denominator=1;
        int divisor = gcd(numerator,denominator);
        num = numerator/divisor;
        denom = denominator/divisor;
        if((denom<0 && num>0)||(denom<0 && num<0)){
            denom*=-1;
            num*=-1;
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

private:
    int num,denom;
};

Rational operator+(const Rational& first, const Rational& second){
    int multiplie = lcm(first.Denominator(),second.Denominator());
    int num = (multiplie/first.Denominator())*first.Numerator() + (multiplie/second.Denominator())*second.Numerator();
    return Rational(num,multiplie);
}

Rational operator-(const Rational& first, const Rational& second){
    int multiplie = lcm(first.Denominator(),second.Denominator());
    int num = (multiplie/first.Denominator())*first.Numerator() - (multiplie/second.Denominator())*second.Numerator();
    return Rational(num,multiplie);
}

bool operator==(const Rational& first, const Rational& second){
    int multiplie = lcm(first.Denominator(),second.Denominator());
    return (multiplie/first.Denominator())*first.Numerator() == (multiplie/second.Denominator())*second.Numerator();
}

Rational operator*(const Rational& first, const Rational& second){
    int num = first.Numerator()*second.Numerator();
    int denom = first.Denominator()*second.Denominator();
    return Rational(num,denom);
}

Rational operator/(const Rational& first, const Rational& second){
    if(second.Numerator()==0) throw logic_error("Division by zero");
    int num = first.Numerator()*second.Denominator();
    int denom = first.Denominator()*second.Numerator();
    return Rational(num,denom);
}

ostream& operator<<(ostream& out_stream,const Rational& first){
    out_stream<<first.Numerator()<<"/"<<first.Denominator();
    return out_stream;
}

istream& operator>>(istream& in_stream, Rational& first){
    int num,denom;
    char sep;
    in_stream>>num>>sep>>denom;
    if(!in_stream.fail() && sep=='/'){
        first = Rational(num,denom);
    }
    return in_stream;
}


int main() {
    try {
        Rational r1,r2;
        char op;
        cin>>r1>>op>>r2;
        if(op=='+') cout<<r1+r2;
        if(op=='-') cout<<r1-r2;
        if(op=='*') cout<<r1*r2;
        if(op=='/') cout<<r1/r2;
    } catch (logic_error& e) {
        cout<<e.what();
    }
    return 0;
}