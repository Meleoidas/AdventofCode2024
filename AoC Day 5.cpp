#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> pages){
  ifstream list1("list1");
  int n1, n2;
  char delim;

  while(list1 >> n1 >> delim >> n2){
    auto it1 = find(pages.begin(), pages.end(), n1);
    auto it2 = find(pages.begin(), pages.end(), n2);

    if(it1 != pages.end() && it2 != pages.end()){
      int dist = distance(it1, it2);
      if(dist < 0){
        return false;
      }
    }
  }
  return true;
}

int main(){
  ifstream list1("list1");
  ifstream list2("list2");

  int right = 0;
  string str;
  while(getline(list2, str)){
    vector<int> pages;
    istringstream istr(str);
    int n1;
    char delim;

    while(istr >> n1 >> delim){
      pages.push_back(n1);
    }
    istr >> n1;
    pages.push_back(n1);

    if(check(pages)){
      int mid = pages.size() / 2;
      right += pages[mid];
    }
  }

  cout<<right;
  list1.close();
  list2.close();
}