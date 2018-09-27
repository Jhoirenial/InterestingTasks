#include <iostream>
#include <string>
#include <sstream>

template <typename T>
std::string toString(T val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

bool Palindrome(const int& number) {
     std::string s = toString(number);
     int sizeS = static_cast<int>(s.size());
     const int sizeSHalf = sizeS / 2;

    for(int i = 0; i < sizeSHalf; ++i) {
        if(s[i] != s[sizeS - 1]) {
            return false;
        }
        --sizeS;
    }
    return true;
}

int main() {
     int number = 34543;
    if(Palindrome(number)) {
        std::cout << number << " is palindrome" << std::endl;
    } else {
        std::cout << number << " is not palindrome" << std::endl;
    }

    return 0;
}
