#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

template <class T>
T fromString(const std::string& s)
{
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}

int FindDot(const std::string& version) {
    const auto begin_version = begin(version);

     auto dot = find(begin_version, end(version), '.');
    std::string major_str(begin_version, dot);
    int major = fromString<int>(major_str);

    return major;
}

int CompareVersions(const std::string& version1,
                    const std::string& version2)
{
    int major1 = FindDot(version1);

    int major2 = FindDot(version2);

    if(major1 < major2) {
        return -1;
    } else {
        if(major1 > major2) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main()
{
    int major = CompareVersions("51.0.1.1011", "1.12.0.456");
    std::cout << major << std::endl;

    return 0;
}
