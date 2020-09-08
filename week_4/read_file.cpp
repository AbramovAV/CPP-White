#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fin("input.txt");
    string line;
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
}