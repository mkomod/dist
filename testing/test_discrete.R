Rcpp::sourceCpp("../src/discrete.cpp")

rdiscrete(1e1, 1:9/55)                 # raises an error

abs(table(rdiscrete(1e6, 1:10/55)) / 1e6 - 1e-3)  < 1:10/55

