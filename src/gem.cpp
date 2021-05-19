#include "RcppArmadillo.h"

// [[Rcpp::export]]
arma::mat rgem(int n, int k, double b)
{
    arma::mat res = arma::mat(n, k, arma::fill::zeros);
    for (int i = 0; i < n; ++i) {
	double cumprod = 0.0;
	for (int j = 0; j < k; ++j) {
	    double r = R::rbeta(1, b);
	    res(i, j) = r * exp(cumprod);
	    cumprod += std::log1p(-r);
	}
    }
    return res;
}
