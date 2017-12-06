#include <Rcpp.h>
#include <vector> 
using namespace Rcpp; 

// [[Rcpp::plugins(cpp11)]]


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