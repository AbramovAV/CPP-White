#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string line;
    while(getline(fin,line)){
        fout<<line<<endl;
    }
    fin.close();
    fout.close();
}