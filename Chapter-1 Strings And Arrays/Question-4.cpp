// Implement a method to to check if a string is a permutation of a 
// palindrome.

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

string isPermutation(string input){
  int charArr[256] = {0};
  int countOdd=0;
  for(int i=0;i<input.length();i++){
    if (input[i] == ' ') continue;
    charArr[int(input[i])]++;
    if (charArr[int(input[i])]%2==0){
     countOdd--; 
    } else{
      countOdd++;
    }
  }
  if (countOdd <=1)
    return "True";
  return "False";
}

int main() {
  string input = "taco cat";
  cout<<isPermutation(input);
  return 0;
}


