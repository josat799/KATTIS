#include <iostream>
#include <istream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
void setDictionary(map<string, string>& dictionary);
int main()
{
    map<string, string> dictionary;
    string input;
    static string UNKNOWNLETTER = "eh";





    setDictionary(dictionary);

    while (getline(cin, input)) {
        if (dictionary.find(input) != dictionary.cend()) {
            cout << dictionary[input] << endl;
        } else {
            cout << UNKNOWNLETTER << endl;
        }
    };
    return 0;
}

void setDictionary(map<string, string>& dictionary) {
    string input;
    while(getline(cin, input)) {
        if (input == "") {
            break;
        }

        int foreginWordLength = input.find(" ");
        dictionary[input.substr(foreginWordLength + 1, input.size() - 1)] = input.substr(0, foreginWordLength);
    }
}
