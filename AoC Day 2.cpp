// worst code humanity has ever seen, but it works 👍

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;


bool check(vector<int>& checkVector){
    int increasing = 0, decreasing = 0;

    for(int i = 0; i < checkVector.size() - 1; i++){
       bool isIncreasing = (checkVector[i+1] > checkVector[i]);
       if(checkVector[i+1] > checkVector[i]){
        increasing++;
       }else if(checkVector[i+1] < checkVector[i]){
        decreasing++;
       }else{
        return false;
       }
    }
    if(increasing == decreasing){return false;}
    if(increasing>0 && decreasing>0){return false;}
    
    for(int i = 0; i < checkVector.size() - 1; i++){
        int diff = checkVector[i+1] - checkVector[i];

        if(1 > abs(diff) || abs(diff) > 3) {
          return false;
        }
    }
    
    return (true);
}

bool isRowSafe(vector<int>& rowStringVector) {
    int increasing = 0, decreasing = 0;

    for(int i = 0; i < rowStringVector.size() - 1; i++){
       bool isIncreasing = (rowStringVector[i+1] > rowStringVector[i]);
       if(rowStringVector[i+1] > rowStringVector[i]){
        increasing++;
       } else if(rowStringVector[i+1] < rowStringVector[i]) {
        decreasing++;
       } else {
        vector<int> check_incdec = rowStringVector;
        check_incdec.erase(check_incdec.begin() + i);
        if(!check(check_incdec)) {return false;}
       }
    }

    if(increasing == decreasing){return false;}
    if(increasing > 0 && decreasing > 0){
      bool isIncreasing = (increasing > decreasing);
       if(isIncreasing){
        for(int i = 0; i < rowStringVector.size() - 1; i++) {
        if(rowStringVector[i+1] < rowStringVector[i]){
          vector<int> check_first = rowStringVector;
          check_first.erase(check_first.begin() + i);
          vector<int> check_second = rowStringVector;
          check_second.erase(check_second.begin() + i+1);

          if(!check(check_first) && !check(check_second)) {return false;}
        }
       }
       }else{
        for(int i = 0; i < rowStringVector.size() - 1; i++) {
        if(rowStringVector[i+1] > rowStringVector[i]){
          vector<int> check_first = rowStringVector;
          check_first.erase(check_first.begin() + i);
          vector<int> check_second = rowStringVector;
          check_second.erase(check_second.begin() + i+1);

          if(!check(check_first) && !check(check_second)) {return false;}
        }
       }
       }
      }

    for(int i = 0; i < rowStringVector.size() - 1; i++) {
        int diff = rowStringVector[i+1] - rowStringVector[i];

        if(1 > abs(diff) || abs(diff) > 3) {
            vector<int> check_first = rowStringVector;
            check_first.erase(check_first.begin() + i);
            vector<int> check_second = rowStringVector;
            check_second.erase(check_second.begin() + i + 1);

            if(!check(check_first) && !check(check_second)) {return false;}
        }
    }
    
    return true;
}

int main(){
  ifstream inputFile("input");
  ofstream outputFile("output");

  string row;
  int number;

  while(getline(inputFile, row)){
    istringstream rowStream(row);
    vector<int> rowStreamVector;
    bool increasing, increasing2;

    while(rowStream >> number){
      rowStreamVector.push_back(number);
    }

    if(isRowSafe(rowStreamVector)){
      for(const int& num : rowStreamVector){
        outputFile << num << " ";
      }
      outputFile << endl;
    }
  }

  inputFile.close();
  outputFile.close();
  return 0;
}