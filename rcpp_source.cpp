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
LogicalVector check_greater(NumericVector x, double y){
  LogicalVector out(x.size()); //initialize length inside ()
  for(int i = 0; i < x.size(); ++i){
    if(x[i] > y){
      out[i] = true;
    } else{
      out[i] = false;
    }
  }
  return out;
}


// [[Rcpp::export]]
NumericMatrix fill_matrix(int nrow, int ncol){
  NumericMatrix x(nrow, ncol);
  
  for(int i = 0; i < nrow; i++) {
    for(int j = 0; j < ncol; j++) {
      x(i, j) = i+j;
    }
  }
  
  return x;
}

// [[Rcpp::export]]
double grab_alpha(List mod){
  if(!mod.inherits("lm")){
    stop("Input must be a linear model");
  }
  //Extracting 'coefficients' member of S3 'lm' class
  //converting to C++ with as() because we know this will always be numeric
  NumericVector coefs = as<NumericVector>(mod["coefficients"]);
  double alpha = coefs[0];
  
  return alpha;
}


// [[Rcpp::export]]
List list_of_vectors(){
  List out;
  
  // initialize to nothhing
  NumericVector n(4, 2.2);
  IntegerVector i(10, 1);
  LogicalVector l(2, true);
  StringVector s(3, "hi");
  
  out["numeric"] = n;
  out["integer"] = i;
  out["logical"] = l;
  out["string"] = s;
  
  return out;
}


// [[Rcpp::export]]
double pow_and_sum(std::vector<double> x, double power) {
  double out = 0.0;
  for(auto &i : x){
    out += pow(i, power);
  }
  return out;
}


// [[Rcpp::export]]
RObject using_rfunc(Function f, NumericVector x){
  return f(x);
}


