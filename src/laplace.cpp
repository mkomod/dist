#include "RcppArmadillo.h"

//' Density function of the Laplace distribution
//'
//' @param x vector
//' @param m location
//' @param b scale
//'
//' @export
// [[Rcpp::export]]
arma::vec dlaplace(arma::vec x, double m, double b)
{
    return 0.5 / b * exp(-abs(x - m)/b);
}


//' Distribution function of the Laplace distribution
//'
//' @param x quantile
//' @param m location
//' @param b scale
//'
//' @export
// [[Rcpp::export]]
arma::vec plaplace(arma::vec x, double m, double b)
{
    return 0.5 + 0.5 * sign(x - m) % (1.0 - exp(-abs(x - m)/b));
}


//' Sample from the Laplace distribution
//'
//' @param n number of samples
//' @param m location
//' @param b scale
//'
//' @export
// [[Rcpp::export]]
arma::vec rlaplace(int n, double m, double b)
{
    arma::vec res = arma::vec(n, arma::fill::randu);
    res = m - b * arma::sign(res - 0.5) % log1p(-2.0*abs(res - 0.5));
    return res;
}
