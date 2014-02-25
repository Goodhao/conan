/*
  By Goodhao
  http://goodhaoblog.com
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main() {
  fstream infile;
  stringstream buffer;
  string content,url;
  unsigned int first,x1,x2,number;
  cin >> number;
  system("wget http://conan.17dm.com/manhua/ 1>/dev/null 2>/dev/null");
  infile.open("index.html",ios::in); 
  buffer << infile.rdbuf();
  infile.close();
  content = buffer.str();
  buffer.str("");
  first = content.find("articletxt3 mb1");
  for (unsigned int i = 0;i < number;i++) {
    first = content.find("<li>",first + 1);
  }
  first = content.find("\"",first);
  x1 = first + 1;
  first = content.find("\"",first + 1);
  x2 = first - x1;
  url = content.substr(x1,x2);
  //found
  url = "wget -O 1.html " + url + " 1>/dev/null 2>/dev/null";
  system(url.c_str());
  infile.open("1.html",ios::in); 
  buffer << infile.rdbuf();
  infile.close();
  content = buffer.str();
  buffer.str("");
  first = 0;
  for (;;) {
    first = content.find("narImg[",first);
    first = content.find("\'",first);
    if (first == string::npos) {
      break;
    }
    x1 = first + 1;
    first = content.find("\'",first + 1);
    x2 = first -x1;
    url = content.substr(x1,x2);
    url = "wget " + url + " 1>/dev/null 2>/dev/null";
    system(url.c_str());
  }
  system("rm index.html; rm 1.html");
  return 0;
}
