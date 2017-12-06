#include <Rcpp.h>
#include <vector> //so we can use C++ vectors 
using namespace Rcpp; //so we don't have to write Rcpp::NumericVector


// So we can use C++ 11 functionality
// [[Rcpp::plugins(cpp11)]]


// [[Rcpp::export]]
std::string r_ladies() {
  return "Hello world!";
}

// [[Rcpp::export]]
int add2(int x, int y, int z) {
  int sum = x + y + z;
  return sum;
}


// [[Rcpp::export]]
double sumC(NumericVector x) {
  int n = x.size();
  double total = 0;
  for(int i = 0; i < n; ++i) {
    total += x[i];
  }
  return total;
}



// [[Rcpp::export]]
double pow_and_sum(std::vector<double> x, double power) {
  double out = 0.0;
  for(auto &i : x){
    out += pow(i, power);
  }
  return out;
}

