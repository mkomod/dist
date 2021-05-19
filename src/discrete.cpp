#include "RcppArmadillo.h"

// [[Rcpp::export]]
arma::mat rdiscrete(int n, arma::vec p, bool as_indicator=false)
{

    if (sum(p) != 1.0)
	Rcpp::stop("probabilities must sum to 1");

    int k = p.n_elem;
    arma::vec p_cs = arma::cumsum(p);
    arma::mat res;

    if (as_indicator) {
	res = arma::mat(n, k, arma::fill::zeros);
	for (int i = 0; i < n; ++i) {
	    int j = arma::find(p_cs > R::runif(0, 1), 1).eval()(0);
	    res(i, j) = 1;
	}
    } else {
	res = arma::mat(n, 1, arma::fill::zeros);
	for (int i = 0; i < n; ++i) {
	    int j = arma::find(p_cs > R::runif(0, 1), 1).eval()(0);
	    res(i) = j;
	}
    }
    return res;
}

