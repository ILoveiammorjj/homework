#include <bits/stdc++.h>
 
//modulo multiplication
inline std::size_t mulmod(std::size_t a, std::size_t b, std::size_t m) 
{
	if (b < a)
		std::swap(a, b);
	std::size_t res = 0;
	for (std::size_t i = 0; i < a; ++i) 
	{
		res += b;
		res %= m;
	}
	return res;
}
 
//degree
inline std::size_t pow(std::size_t x, std::size_t n)
 {
	if (!n) return 1;
	else if (n==1) return x;
	else if (n % 2 == 0)
		return pow(x * x, n/2);
	else
		return pow(x * x, n /2)*x;
 }
 
//pow(a, b) mod n
inline std::size_t powmod(std::size_t a, std::size_t b, std::size_t n)
{
	a%=n;
	std::size_t result = 1;
	while (b > 0) 
	{
		if (b&1) result = (result*a)%n;
		a = (a*a)%n;
		b >>= 1;
	}
	return result;
}
 
//search for quadro nonresidique
std::size_t quadroNonres(std::size_t p)
{
	std::size_t a = 2;
	while (powmod(a, (p-1)/2, p) != p-1) ++a;
	return a;
}
 
//Tonnelli_Shanks algorithm
std::size_t TS_algo(std::size_t p, std::size_t n)
{
	n = n%p;
	std::size_t r = 0, s = p - 1;
	while(s%2 == 0)
	{
		s/=2;
		++r;
	}
	std::size_t v = powmod(n, s, p), w = powmod(n, (s+1)/2, p);
	std::size_t mod = v, m = 0;
	while(mod != 1)
	{
		mod = mulmod(mod, mod, p);
		++m;
	}
	std::size_t z = quadroNonres(p), v_coeff = powmod(powmod(z, s, p), pow(2, r-m), p),
	w_coeff = powmod(powmod(z, s, p), pow(2, r-m-1), p);
	while (v != 1)
	{
		v = mulmod(v, v_coeff, p);
		w = mulmod(w, w_coeff, p);
	}
	return w;
}
 
int main() {
	std::size_t p, n;
	if (!(std::cin >> p >> n))
	{
		std::cerr << "Input error\n";
		return 0;
	}
	std::cout << "The result is " << TS_algo(p, n) << "\n";
	return 0;
}
