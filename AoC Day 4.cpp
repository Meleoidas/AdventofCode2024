#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
  ifstream inputFile("input");

  int words = 0;
  string str;
  vector<vector<char>> matrix;
  while(inputFile >> str){
    vector<char> charVector;
    for(char c: str){
      charVector.push_back(c);
    }
    matrix.push_back(charVector);
  }

  for(int i = 1; i < matrix.size() - 1; i++){
    for(int j = 1; j < matrix[i].size() - 1; j++){
      if(matrix[i][j] == 'A' &&
      ((matrix[i-1][j-1] == 'M' && matrix[i+1][j+1] == 'S') || (matrix[i-1][j-1] == 'S' && matrix[i+1][j+1] == 'M')) &&
      ((matrix[i+1][j-1] == 'M' && matrix[i-1][j+1] == 'S') || (matrix[i+1][j-1] == 'S' && matrix[i-1][j+1] == 'M'))){
        words++;
      }
    }
  }

  cout<<words;
  inputFile.close();
}