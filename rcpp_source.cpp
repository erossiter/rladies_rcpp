#include <Rcpp.h>
#include <vector> 
using namespace Rcpp;

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
double pow_and_sum(std::vector<double> vec, double power) {
  double out = 0.0;
  for(auto &i : vec){
    out += pow(i, power);
  }
  return out;
}

