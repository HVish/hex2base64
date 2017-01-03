#include "iostream"

using namespace std;

// converts decimal to base64
char dec2base64(int n) {
    if (n < 26) {
        return (n + 'A');
    } else if (n < 52) {
        return (n - 26 + 'a');
    } else if (n < 62) {
        return (n - 52 + '0');
    } else if (n == 62) {
        return '+';
    }
    return '/';
}

// converts haxadecimal digit to 4-bit binary string
string str2bin(char n) {
    switch (n) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'A': return "1010";
        case 'b': return "1011";
        case 'B': return "1011";
        case 'c': return "1100";
        case 'C': return "1100";
        case 'd': return "1101";
        case 'D': return "1101";
        case 'e': return "1110";
        case 'E': return "1110";
        case 'f': return "1111";
        case 'F': return "1111";
    }
    return "0000";
}

// converts 6-bit binary number to decimal
int bin2dec(string b) {
    int result = 0;
    for (size_t i = 0; i < 6; i++) {
        if(b[i] == '1') {
            result += (1 << (5-i));
        }
    }
    return result;
}

// start here
int main(int argc, char const *argv[]) {
    std::string hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string bin = "";
    for (size_t i = 0; i < hex.size(); i++) {
        bin += str2bin(hex[i]);
    }
    for (size_t i = 0; i < bin.size(); i+=6) {
        std::cout << dec2base64(bin2dec(bin.substr(i,6)));
    }
    return 0;
}
