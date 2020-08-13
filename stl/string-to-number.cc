#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s = "13xy452";
    stringstream ss(s);

    int number;
    ss >> number;
    cout << number << endl;

    string x;
    ss >> x;
    cout << x << endl;

    // once stream is empty, it is nop
    int number2 = 90;
    ss >> number2;
    cout << number2 << endl;

    int number3;
    // convert string to const char *
    sscanf(s.c_str(), "%d", &number3);
    cout << number3 << endl;

    float number4;
    string s1 = "14.563";
    sscanf(s1.c_str(), "%f", &number4);
    cout << number4 + 0.437 << endl;

    cout << stoi("17.562") << endl;
    cout << atoi("19.3") << endl;

    cout << atof("17.562") + 0.438 << endl;
}
