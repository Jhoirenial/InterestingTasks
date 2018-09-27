#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <class T>
std::ostream& operator<< (std::ostream& os, std::vector<T> myVector) {
    bool first = true;
    for(const auto& i : myVector)
    {
        if(!first)
        {
            os << ' ';
        }

        first = false;
        os << i;
    }

    return os;
}

void Split(const std::string& text,
           char delimeter,
           std::vector<std::string>& pParts) {
    auto begin_str = begin(text);
    auto end_str = end(text);

    while(begin_str != end_str)
    {
        auto space = find(begin_str, end_str, delimeter);
        std::string str(begin_str, space);

        //std::cout << str.size();
        begin_str += static_cast<int>(str.size());

        if(static_cast<int>(str.size()) == 0) {
            begin_str++;
        } else {
            pParts.push_back(str);
        }
    }
}

int main() {
    std::vector<std::string> myVector;

    Split("June/1/2017", '/', myVector);
    std::cout << myVector;

    return 0;
}
