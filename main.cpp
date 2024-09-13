#include <iostream>
#include <string>
#include "telegram.h"

using namespace std;

void getStringLength()
{
    int length = 0;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            length++;
        }
    }
    cout << "Length of the string is: " << length << endl;
}

int main() {
    sendTelegram();
    return 0;
}
