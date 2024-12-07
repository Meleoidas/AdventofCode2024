#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main(){
  ifstream inputFile("input");

  int sum = 0;
  string line, str = "";
  while(inputFile >> line){
    str = str + " " + line;
  }

  regex rgx("mul\\((\\d+),(\\d+)\\)");
  smatch match;
  while(regex_search(str, match, rgx)){
    sum += stoi(match[1].str()) * stoi(match[2].str());
    str = match.suffix().str();
  }

  cout<<sum;
  inputFile.close();
}
