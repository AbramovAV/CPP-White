#include <iostream>
#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
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
    int num = first.Numerator()*second.Denominator();
    int denom = first.Denominator()*second.Numerator();
    return Rational(num,denom);
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
