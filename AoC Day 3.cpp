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
  regex rgxDo("do\\(\\)");
  regex rgxDont("don't\\(\\)");

  smatch match, matchDo, matchDont;

  bool Do = true;

  while(true){
    string str1 = "", str2 = "";
    if(Do && regex_search(str, matchDont, rgxDont)){
      str1 = matchDont.suffix().str();
    }
    if(Do && regex_search(str, match, rgx)){
      str2 = match.suffix().str();
    }else if(!Do && regex_search(str, matchDo, rgxDo)){
      str = matchDo.suffix().str();
      Do = true;
    }
    if(Do && str1.size() > str2.size()){
      str = str1;
      Do = false;
    }else if(Do && str1.size() < str2.size()){
      sum += stoi(match[1].str()) * stoi(match[2].str());
      str = str2;
    }
    if(!regex_search(str, matchDont, rgxDont) && !regex_search(str, match, rgx) && !regex_search(str, matchDo, rgxDo)){
      break;
    }
  }

  cout<<sum;
  inputFile.close();
}
