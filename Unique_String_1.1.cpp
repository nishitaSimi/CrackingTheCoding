#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

bool isUnique(string input) {
   vector<int> frequency(52, 0);
    for(auto ch : input)
    {
        ++frequency[ch - 'A'];
        if(frequency[ch - 'A'] > 1)
        {
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cout << "Enter the string : " << endl;
    cin >> str;
    if(isUnique(str))
    {
        cout << "Unique string "<< endl;
    }
    else
    {
        cout << "Not an unique string "<< endl;
    }
    return 0;
}
