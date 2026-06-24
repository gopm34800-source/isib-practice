#include <bits/stdc++.h>
using namespace std;

bool is_letter(char c){
    string letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0;i<letters.length();++i) {
        if(letters[i]==c) {
            return true;
        }
    }
    return false;
}

bool is_number(char c){
    string numbers="0123456789";
    for (int i=0;i<numbers.length();++i) {
        if(numbers[i]==c) {
            return true;
        }
    }
    return false;
}

int main() {
    string word;
    cin>>word;
    if(word.length()==6 && is_letter(word[0]) && is_number(word[1]) && is_number(word[2]) && is_number(word[3]) && is_letter(word[4]) && is_letter(word[5])) {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
