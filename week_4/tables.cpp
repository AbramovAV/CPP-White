#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    ifstream fin("input.txt");
    string line;
    int N,M;
    fin>>N>>M;
    getline(fin,line);
    for(int i=0;i<N;++i){
        for(int j=0;j<M-1;++j){
            getline(fin,line,',');
            cout<<setw(10)<<line<<" ";
        }
        getline(fin,line);
        cout<<setw(10)<<line;
        if(i<N-1) cout<<endl;
    }
    fin.close();
}