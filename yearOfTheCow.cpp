#include <iostream>
#include <map>
#include <vector>
#include<math.h>
using namespace std;

int main() {
  int n;

  //map of animal names and years
  map<string,int> years;
  years.insert({"Ox", 1});
  years.insert({"Tiger", 2});
  years.insert({"Rabbit", 3});
  years.insert({"Dragon", 4});
  years.insert({"Snake", 5});
  years.insert({"Horse", 6});
  years.insert({"Goat", 7});
  years.insert({"Monkey", 8});
  years.insert({"Rooster", 9});
  years.insert({"Dog", 10});
  years.insert({"Pig", 11});
  years.insert({"Rat", 12});

  map<string,int> differences;
  map<string,string> animals;
  differences.insert({"Bessie", 0});
  animals.insert({"Bessie", "Ox"});

  string line;
  while(getline(cin, line)) {
    vector<string> vec;
    string temp = "";

    for(int j = 0; j < line.length(); j++) {
      if(line[j] == ' ') {
        vec.push_back(temp);
        temp = "";
      }
      else {
        temp += line[j];
      }
    }
    vec.push_back(temp);
  

    string name = vec[0];
    string prevOrNext = vec[3];
    string animal = vec[4];
    string comparison = vec[7];
    int diff;

    animals.insert({name,animal});

    
    if(prevOrNext == "previous") {
      if(years[animals[comparison]] > years[animal]) {
        diff = differences[comparison] - (years[animals[comparison]]-years[animal]);
      }
      else if(years[animals[comparison]] <= years[animal]) {
        diff = differences[comparison] - (years[animals[comparison]]) - (12-years[animal]);
      }
    }
    else if(prevOrNext == "next") {
      if(years[animals[comparison]] >= years[animal]) {
        diff = differences[comparison] + (12-years[animals[comparison]]) + years[animal];
      }
      else if(years[animals[comparison]] < years[animal]) {
        diff = differences[comparison] + (years[animal]-years[animals[comparison]]);
      }
    }
    differences.insert({name,diff});
  }

  //code for finding difference between bessie and elsie
  cout << differences["Elsie"];
} 


//test cases
//mildred prev dragon Bessie -9
//gretta prev monkey mildred 
//paulina next dog bessie 9
