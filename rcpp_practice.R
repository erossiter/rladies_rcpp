rm(list = ls())
setwd("~/dropbox/github/rladies_rcpp")


#### Introduce what Rcpp is
## - R package
## - provides matching C++ classes for a large number of basic R data types
## - pass in R objects to c++ functions which return R objects!
## - c++ is much, much faster than R
## - catSurv as an example... packages written in R verses Rcpp/C++
##   are 10,000 times slower! (10 vs .001 seconds... 10 is too slow for surveys)

#### Goals for tonight
## - get Rcpp up and running on your computer (hopefully!!)
## - go through prepared, example code
## - walk through how to set up your own code
## - practice activity



## In order to install Rcpp:
## Mac
## 1) Go to App Store and install Xcode
##
## PC
## 1) Make sure R is installed on a path ~without~ spaces
## 2a) Try to open c++ file in RStudio... should prompt you to
##     install RtoolsVERSION.exe -- do this!
## 2b) installr stuff
## 2c) If that doesn't work,
##     download a compatible version for your version of R
##     here: https://cran.r-project.org/bin/windows/Rtools/
##     (check R version using 'version' in the console)
##
## Now try lines X-X
## If 84 appears in the console, you're good!
## If not...
## 
## 3) You need to edit PATH variable
##    - Right click 


## Erin, these are the instructions!!!
## http://thecoatlessprofessor.com/programming/rcpp/install-rtools-for-rcpp/

## Erin, these are the 2011 instructions
## https://tonybreyal.wordpress.com/2011/12/07/installing-rcpp-on-windows-7-for-r-and-c-integration/


## So I have a script prepared, let's go through that first

## Then, let's create a script ourselves
## RStudio > New File > C++ File
## Save as whatever in the same folder
## (change to automatically open in Rstudio)

# install.packages("Rcpp")
library("Rcpp")
sourceCpp(file = "rcpp_example.cpp")


## sourced in C++ functions
r_ladies()

pow_and_sum(vec = 1:3, power = 2)


## compare R and C++ speed
library(microbenchmark)

test_vec <- 1:10000
microbenchmark(sum(test_vec^5), pow_and_sum(test_vec, 5))




