// Implement a method do string compression.

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

string stringCompression(string input){
  int count = 1;
  string compressedString;
  int i;
  for(i = 0 ; i <input.length()-1 ; i++){
    if (compressedString.length() > input.length()){
      return input;
    }
    if (input[i] == input[i+1]){
      count++;
      continue;
    }
    compressedString += input[i];
    compressedString += std::to_string(count);
    count = 1;
  }
  compressedString += input[i];
  compressedString += std::to_string(count);
  return compressedString;
}

int main() {
  string input = "aabcccccaaa";
  cout<<stringCompression(input);
  return 0;
}


