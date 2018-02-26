// Implement a method to to check if two strings are one edits (or zero edits) away 

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

string isEditAway(string s1, string s2){
  int index1 = 0, index2 =0;
  bool foundDifference = false;
  while(index1 < s1.length() && index2 < s2.length()){
    if (s1[index1] != s2[index2]){
      if (foundDifference == true){
        return "Strings are more than one edit away";
      }
      foundDifference = true;
      if (s1.length() == s2.length()){
        index1++;
      } 
    }else{
        index1++;
      }
    index2++;
  }
  return "Strings are one edit away";
}
int main() {
  string str1 = "pale";
  string str2 = "bake";
  int diff = str1.length() - str2.length();
  if (abs(diff) > 1){
    cout<<"Strings are more than one edit away";
    return 0;
  }
  string s1 = str1.length() < str2.length() ? str2 : str1;
  string s2 = str1.length() < str2.length() ? str1 : str2;
  cout<<isEditAway(s1, s2);
  return 0;
}


