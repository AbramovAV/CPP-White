#include <vector>
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

vector<string> PalindromFilter(vector<string>words,int minLength){
    vector<string> palindromes;
    for(auto word:words){
        if(word.size()>=minLength && IsPalindrom(word)){
            palindromes.push_back(word);
        }
    }
    return palindromes;
}