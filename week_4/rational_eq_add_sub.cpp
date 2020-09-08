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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
