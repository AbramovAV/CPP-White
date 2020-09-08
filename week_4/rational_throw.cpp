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
        if(denominator==0) throw invalid_argument("Zero denominator provided");
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

Rational operator/(const Rational& first, const Rational& second){
    if(second.Numerator()==0) throw domain_error("Zero divisor provided");
    int num = first.Numerator()*second.Denominator();
    int denom = first.Denominator()*second.Numerator();
    return Rational(num,denom);
}

