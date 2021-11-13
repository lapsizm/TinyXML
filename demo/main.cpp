/*#include <iostream>
#include <sstream>
#include <vector>

#include "tinyxml2.h"


struct MobilePhone {
  double weight;
  bool is_broken;
  double price;
};

using namespace tinyxml2;

int main(int argc, char** argv) {
  if (argc == 2) {
    size_t size;
    std::stringstream ss(argv[1]);
    ss >> size;

    std::vector<MobilePhone> mb(size);

    for (size_t i = 0; i < mb.size(); ++i) {
      std::cin >> mb[i].weight >> mb[i].is_broken >> mb[i].price;
    }


    XMLDocument doc;

    doc.LoadFile("../file2.xml");

    XMLDeclaration* dec = doc.NewDeclaration();
    doc.InsertFirstChild(dec);

    XMLElement* node = doc.NewElement("MobilePhones");
    doc.InsertEndChild(node);



    if (size == 0) {
      (*node).SetText("\n");
    }

    for (size_t i = 0; i < mb.size(); ++i) {
      XMLElement* element = doc.NewElement("MobilePhone");
      element->SetAttribute("id", i);
      element->SetAttribute("weight", mb[i].weight);
      element->SetAttribute("is_broken", mb[i].is_broken);
      element->SetAttribute("price", mb[i].price);
      node->InsertEndChild(element);
    }
    doc.SaveFile("../file2.xml");
    doc.Print();
  }
}*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool check_polindrom(const std::string& word) {
  size_t len = word.length();

  for (size_t i = 0; i < len / 2; ++i) {
    if(word[i] == ' ') continue;
    if (tolower(word[i]) > 96 && tolower(word[i]) < 123 &&
            tolower(word[len - i - 1]) > 96 &&
            tolower(word[len - i - 1]) < 123) {
      if (tolower(word[i]) != tolower(word[len - i - 1])) {
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  std::ifstream fin;
  fin.open("../text.txt");
  if (fin.is_open()) {
    size_t count = 0;
    std::vector<std::string> vec;
    while (!fin.eof()) {
      std::string str;
      std::getline(fin, str);
      if (!str.empty()) {
        bool a = check_polindrom(str);
        if (a) {
          vec.push_back(str);
          ++count;
        }
      }
    }

    std::cout << "{\n"
              << "\t \"count_palindromes\": " << count
              << "\n\t \"palindromes\": [";
    for (size_t i = 0; i < vec.size(); ++i) {
      std::cout << " \"" << vec[i] << "\" ";
      if (i != vec.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "]\n}";
  }
}