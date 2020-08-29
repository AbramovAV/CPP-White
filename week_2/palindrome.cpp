#include <string>

using namespace std;

bool IsPalindrom(string word){
    string reversed_word = "";
    for(auto w:word){
        reversed_word = w+reversed_word;
    }
    if(word==reversed_word){
        return true;
    }
    return false;
}