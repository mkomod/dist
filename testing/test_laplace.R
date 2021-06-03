Rcpp::sourceCpp("../src/laplace.cpp")

xs <- seq(-10, 10, 0.05)

ds <- dlaplace(xs, 0, 1)
plot(xs, ds, type="l")

ps <- plaplace(xs, 0, 1)
plot(xs, ps, type="l")

rl <- rlaplace(1e7, 0, 1)
plot(density(rl))
lines(xs, ds, col="red", lwd=1) 

