#include <Rcpp.h>
#include <vector> 
using namespace Rcpp; 

// [[Rcpp::plugins(cpp11)]]


// [[Rcpp::export]]
List listC(){

  NumericVector vec(3);
  vec[0] = 1.0;
  vec[1] = 2.0;
  vec[2] = 3.0;
  
  NumericMatrix mat(2, 2);
  
  int scalar = 10;
  
  List out(3);
  out[0] = vec;
  out[1] = mat;
  out[2] = scalar;
  
  return out;
}

// [[Rcpp::export]]
NumericVector rowMeansC(NumericMatrix x){
  int ncol = x.ncol();
  int nrow = x.nrow();
  
  NumericVector out(nrow, 0.0); //initialize all to 0
  for(int i = 0; i < nrow; i++){
    for(int j = 0; j < ncol; j++){
      out[i] += x(i,j);
    }
    out[i] /= ncol;
  }
  
  return out;
  
}