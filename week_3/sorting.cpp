#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int N;
    cin>>N;
    vector<int> nums(N);
    for(auto& num:nums){
        cin>>num;
    }
    sort(begin(nums),end(nums),[](int x,int y){
        return abs(x)<abs(y);
    });
    for(const auto& num:nums){
        cout<<num<<" ";
    }
    return 0;
}