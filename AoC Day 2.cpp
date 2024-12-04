#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

bool isRowSafe(vector<int>& rowStringVector) {
    int increasing = 0, decreasing = 0;

    for (int i = 0; i < rowStringVector.size() - 1; i++){
       bool isIncreasing = (rowStringVector[i+1] > rowStringVector[i]);
       if(isIncreasing){
        increasing++;
       }else{
        decreasing++;
       }
    }
    if(increasing == decreasing){return false;}
    bool isIncreasing = (increasing > decreasing);

    for(int i=0; i < rowStringVector.size() - 1; i++){
        int diff = rowStringVector[i+1] - rowStringVector[i];

        if(diff < 0 && isIncreasing){
            return false;
        }else if(diff > 0 && !isIncreasing){
            return false;
        }

        if(1 > abs(diff) || abs(diff) > 3){
            return false;
        }
    }
    
    return (true);
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
