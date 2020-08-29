#include <vector>

using namespace std;

void Reverse(vector<int>& v){
    int buffer;
    for(int i=0;i<v.size()/2;++i){
        buffer = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = buffer;
    }
}