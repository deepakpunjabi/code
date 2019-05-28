#include <iostream>
#include <string>

using namespace std;

void removeDup(string& s, int start) {
    if (s.length() < 3) {
        return;
    }

    if (start > s.length() - 2) return;

    int count = 1;
    char c = s[start];

    int i = start + 1;

    while (i < s.length() && s[i] == c) {
        ++count, ++i;
    }

    if (count >= 3) {
        start = i - count - 2;
        if (start < 0) start = 0;
        s.erase(i - count, count);
    } else {
        start = i;
    }

    return removeDup(s, start);
}

string process_string(string in_str) {
    cout << "in: " << in_str;

    string res(in_str);
    removeDup(res, 0);

    cout << " out: " << res << endl;

    return res;
}

int main() {
    process_string("daabbcccbbaad");
    process_string("aaabbb");
    process_string("aaabbbc");
}