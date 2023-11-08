#include <iostream>
#include <fstream>
#include <cmath>

int main() {
  std::ifstream fin("datensumme.txt");
  std::ifstream fin2("datensumme.txt");
  std::ofstream fmean("mittelwerte.txt");
  std::ofstream fvar("varianzen.txt");
  double means = 0;
  double vars = 0;
  for (int i = 0; i < 234 / 9; ++i) {
    double mean = 0;
    for (int j = 0; j < 9; ++j) {
      int a;
      fin >> a;
      mean += a;
    }
    mean /= 9;
    fmean << mean << std::endl;
    double var = 0;
    for (int j = 0; j < 9; ++j) {
      int a;
      fin2 >> a;
      var += (a - mean) * (a - mean);
    }
    var /= 9;
    fvar << var << std::endl;
    means += mean;
    vars += var;
  }
  fin.close();
  fin2.close();
  fmean.close();
  fvar.close();

  means /= 26;
  vars /= 26;
  std::cout << "mean:" << means << std::endl;
  std::cout << "variance:" << vars << std::endl;
  std::cout << "std. deviation:" << sqrt(vars) << std::endl;
}

