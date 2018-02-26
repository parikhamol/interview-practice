// Implement a method to replace all spaces with '%20'

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

string spaceReplace(string str, int truelength){
  int countspace = 0;
  for(int i = 0; i< truelength; i++){
    if (str[i] == ' '){
      countspace++;
    }
  }
  int index = truelength + (countspace*2);
  for (int i = truelength-1; i>=0; i--){
    if (str[i] == ' '){
      str[index-1]='0';
      str[index-2]='2';
      str[index-3]='%';
      index=index-3;
    }else{
      str[index-1]=str[i];
      index--;
    }
  }
  return str;
}

int main() {
  string input = "Mr John Smith    ";
  int truelength = 13;
  cout<<spaceReplace(input, truelength);
  return 0;
}


