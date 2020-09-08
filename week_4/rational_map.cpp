#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator<(const Rational& first, const Rational& second){
    int multiplie = lcm(first.Denominator(),second.Denominator());
    return (multiplie/first.Denominator())*first.Numerator() < (multiplie/second.Denominator())*second.Numerator();
}

bool operator>(const Rational& first, const Rational& second){
    int multiplie = lcm(first.Denominator(),second.Denominator());
    return (multiplie/first.Denominator())*first.Numerator() > (multiplie/second.Denominator())*second.Numerator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
