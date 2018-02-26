// Implement a method to decide if one string is a permutation of the other.

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

// Using sorting
string isPermutation(string str1, string str2){
  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());
  for( int i =0 ; i <str1.length(); i++){
    if (str1[i] != str2[i]){
      return "Not permutation";
    }
  }
  return "Is a permutation";
}

// Using a hashmap of chars
string isPermutation(string str1, string str2, int flag){
  int charArr[256] = {0};
  for (int i=0; i < str1.length(); i++){
    charArr[int(str1[i])]++;
  }
  
  for (int i=0; i < str2.length(); i++){
    charArr[int(str2[i])]--;
    if (charArr[int(str2[i])] < 0){
      return "Not permutation";
    }
  }
  return "Is a permutation";

}
int main() {
  string str1 = "amol";
  string str2 = "abcd";
  if (str1.length() != str2.length()){
    cout<<"Not permutation";
    return 0;
  }
  cout<<isPermutation(str1, str2)<<endl;
  cout<<isPermutation(str1, str2, 1);
  return 0;
}


