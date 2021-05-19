Rcpp::sourceCpp("../src/gem.cpp")
set.seed(1)

sum(rgem(1, 150, 20))
