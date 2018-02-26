// Implement an algorithm to determine if a string has all unique characters. Dont use additional datastructures.

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

// Function uses an additional datastructure.
string findDuplicate(string input){
  bool arr[256] = {false};
  for (int i=0; i< input.length() ; i++){
    if (arr[int(input[i])] == true) {
      return "Duplicate found";
    }
    arr[int(input[i])] = true;
  }
  return "No Duplicate";
}

// Function uses no additional datastructure.
string findDuplicate(string input, int flag){
  std::sort(input.begin(), input.end());
  for (int i = 0 ; i < input.length() -1 ; i++){
    if (input[i] == input[i+1]) {
      return "Duplicate found";
    }
  }
  return "No Duplicate";
}
int main() {
  string input = "racecar";
  cout<<findDuplicate(input)<<endl;
  cout<<findDuplicate(input, 1);
  return 0;
}


