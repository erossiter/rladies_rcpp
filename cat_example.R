rm(list = ls())
setwd("...")

library(Rcpp)
sourceCpp(file = "rcpp_example.cpp")


## sourced in C++ functions
r_ladies()

pow_and_sum(vec = 1:3, power = 2)


## compare R and C++ speed
library(microbenchmark)

test_vec <- 1:10000
microbenchmark(sum(test_vec^5), pow_and_sum(test_vec, 5))




