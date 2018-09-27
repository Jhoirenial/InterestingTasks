#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s);

void PushBack(string::const_iterator& beginIt,
              string::const_iterator& endIt,
              vector<string>& vector_str);

int main() {
  string s = "C Cpp Java Python scala";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}

using const_stringIt = string::const_iterator;

void PushBack(const_stringIt& beginIt,
              const_stringIt& endIt,
              vector<string>& vector_str) {
     while(beginIt != endIt) {
         auto space = find(beginIt, endIt, ' ');
        string str(beginIt, space);

        beginIt += static_cast<int>(str.size());

        if(static_cast<int>(str.size()) == 0) {
            beginIt++;
        } else {
            vector_str.push_back(str);
        }
     }

}

vector<string> SplitIntoWords(const string& s) {
    auto begin_it = begin(s);
    auto end_it = end(s);

    vector<string> vector_str;

    PushBack(begin_it, end_it, vector_str);


    return vector_str;
}
