#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ifstream fin("input.txt");
    string line;
    cout<<fixed<<setprecision(3);
    while(getline(fin,line)){
        cout<<stod(line)<<endl;
    }
    fin.close();
}