#include "RcppArmadillo.h"

//' Sample from the Dirichlet distribution
//'
//' @param n number ofsample
//' @param a vector of weights
//'
//' @export
// [[Rcpp::export]]
arma::mat rdirichlet(int n, arma::vec a)
{
    int k = a.n_elem;
    arma::mat res = arma::mat(n, k, arma::fill::zeros);
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < k; ++j) {
	    res(i, j) = R::rgamma(a(j), 1);
	}
	res.row(i) /= sum(res.row(i));
    }
    return res;
}

