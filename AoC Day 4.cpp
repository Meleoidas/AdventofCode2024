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

  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix[i].size(); j++){
      if(j + 3 < matrix[i].size() && matrix[i][j] == 'X' && matrix[i][j+1] == 'M' && matrix[i][j+2] == 'A' && matrix[i][j+3] == 'S'){ // xmas
        words++;
      }
      if(i + 3 < matrix.size() && matrix[i][j] == 'X' && matrix[i+1][j] == 'M' && matrix[i+2][j] == 'A' && matrix[i+3][j] == 'S'){ // down
        words++;
      }
      if(i - 3 >= 0 && matrix[i][j] == 'X' && matrix[i-1][j] == 'M' && matrix[i-2][j] == 'A' && matrix[i-3][j] == 'S'){ // up
        words++;
      }
      if(i + 3 < matrix.size() && j - 3 >= 0 && matrix[i][j] == 'X' && matrix[i+1][j-1] == 'M' && matrix[i+2][j-2] == 'A' && matrix[i+3][j-3] == 'S'){ // down left
        words++;
      }
      if(i + 3 < matrix.size() && j + 3 < matrix[i].size() && matrix[i][j] == 'X' && matrix[i+1][j+1] == 'M' && matrix[i+2][j+2] == 'A' && matrix[i+3][j+3] == 'S'){ // down right
        words++;
      }
      if(i - 3 >= 0 && j - 3 >= 0 && matrix[i][j] == 'X' && matrix[i-1][j-1] == 'M' && matrix[i-2][j-2] == 'A' && matrix[i-3][j-3] == 'S'){ // up left
        words++;
      }
      if(i - 3 >= 0 && j + 3 < matrix[i].size() && matrix[i][j] == 'X' && matrix[i-1][j+1] == 'M' && matrix[i-2][j+2] == 'A' && matrix[i-3][j+3] == 'S'){ // up right
        words++;
      }
      if(j + 3 < matrix[i].size() && matrix[i][j] == 'S' && matrix[i][j+1] == 'A' && matrix[i][j+2] == 'M' && matrix[i][j+3] == 'X'){ // samx
        words++;
      }
    }
  }

  cout<<words;
  inputFile.close();
}