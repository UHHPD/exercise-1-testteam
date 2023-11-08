#include <iostream>
#include <fstream>
#include <cmath>

int main() {
  double mean = 0;
  std::ifstream fin("datensumme.txt");
  for(int i = 0 ; i < 234 ; ++i) {
    int a;
    fin >> a;
    mean += a;
  }
  fin.close();
  mean /= 234;
  std::cout << "mean:" << mean << std::endl;


  double var = 0;
  std::ifstream fin2("datensumme.txt");
  for(int i = 0 ; i < 234 ; ++i) {
    int a;
    fin2 >> a;
    var += (a-mean)*(a-mean);
  }
  fin2.close();
  var /= 234;
  std::cout << "variance:" << var << std::endl;
  std::cout << "std. deviation:" << sqrt(var) << std::endl;
}

