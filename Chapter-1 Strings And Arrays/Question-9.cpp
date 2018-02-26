// Implement a method check is one string is a rotation of one another. Use inbuilt isSubstring function.

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;


int main() {
  string str1= "waterbottle";
  string str2 = "erbottlewat";
  if (str1.length() != str2.length()){
    cout<<"strings are not a rotation of each other";
    return 0;
  }
  string s1 = str1+str1;
  std::size_t found = s1.find(str2);
  if (found!=std::string::npos){
    cout << "Strings are a rotation of each other";
    return 0;
  }
  cout<<"strings are not a rotation of each other";
  return 0;
}


