#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

class IPAddress {
   public:
    // You'll have a lot of room for error if you solve this via normal if else and token splitting
    string validIPAddressRegex(string IP) {
        // cpp escape character is \\
        // 0-9, 10-99, 100-199, 200-249, 250-255
        string ipv4_chunk = "[0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]";
        regex ipv4("((" + ipv4_chunk + ")\\.){3}(" + ipv4_chunk + ")");

        // {1,4} repeat this regex block () 1 to 4 times
        string ipv6_chunk = "[0-9a-fA-F]){1,4}";
        regex ipv6("(((" + ipv6_chunk + ")\\:){7}" + ipv6_chunk);

        if (regex_match(IP, ipv4)) {
            return "IPv4";
        } else if (regex_match(IP, ipv6)) {
            return "IPv6";
        } else {
            return "Neither";
        }
    }

    // divide and conquer
    string validIPAddressDC(string ip) {
        return "";
    }
};

int main() {
    IPAddress ipa;
    cout << ipa.validIPAddressRegex("172.16.254.1") << endl;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> result;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}
