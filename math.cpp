#include <bits/stdc++.h>
using namespace std;
//////////////////////////////
//1 Digits In Factorial
int digitsInFactorial(int N) // O(n) solution
{
	double fact = 0;
	for (int i = 1; i <= N; i++)
		fact += log10(i);
	return floor(fact + 1);
}

// 2 approach
int fact(int N) {
	int fact = 1;
	for (int i = 1; i <= N; i++)
		fact *= i;
	return fact;
}
int digitsInFactorial1(int N) // O(n) solution
{
	N = fact(N);
	int cnt = 0;
	while (N != 0) {
		cnt++;
		N /= 10;
	}
	return cnt;
}
void solve_digitsInFactorial() {
	int n = 5;
	cout << digitsInFactorial1(n);
}

////////////////////////////////////////////////
// isPrime
bool isPrime(int N)
{
	if (N == 1) return false;
	if (N == 2 || N == 3) return true;
	if (N % 2 == 0 || N % 3 == 0) return false;
	for (int i = 5; i * i <= N; i++)
		if (N % i == 0)
			return false;
	return true;

}
bool isPrime1(int n) {
	if(n == 0 || n == 1) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
void solve_isPrime() {
	int N = 6;
	if (isPrime(N)) cout << " number is Prime Number " << endl;
	else cout << " number is not prime number " << endl;
}


/////////////////////////////////////////////
// divisor
void divisor(int n ) {
	for (int i = 1; i * i <= n ; i++) {
		if (n % i == 0) {
			cout  << i <<  " " ;
			// this condition because number does not repeat
			if (i != n / i) cout << n / i << " ";  // devisor exist in pair
		}
		// 12 => (1, 12) (2, 6) (3, 4)
	}
}
// disor in sorted order
void divisor_sortedOrder (int n ) {
	int i;
	for ( i = 1; i * i <= n ; i++) {
		if (n % i == 0)
			cout << i <<  " " ;
	}
	i--;
	for ( ; i >= 1; i--) {
		if (n % i == 0) {
			if (i != n / i) cout << n / i << " ";
		}
	}
}
void solve_divisor() {
	int n = 12;
	divisor(n);
	// divisor_sortedOrder(n);
}


///////////////////////////////////////////
// Exactly 3 Divisors
// 1st approach
int exactly3Divisors(int N) // O(nlogn) solution
{
	int tc = 0; // total count
	for (int n = 1; n <= N; n++) {
		int cnt = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				cnt++;
				if (i != n / i ) cnt++;
			}
		}
		if (cnt == 3) tc++;
	}
	return tc;
}

//2nd approach
bool isPrimeNum(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int exactly3Divisors1(int N) {
	int cnt = 0;
	for (int i = 2; i * i <= N; i++)
		if (isPrimeNum(i)) cnt++;
	return cnt;
}
void solve_exactly3Divisors() {
	int n = 6;
	// cout << exactly3Divisors(n);
	cout << exactly3Divisors1(n);
}



///////////////////////////////
// Addition Under Modulo
//1st problem with long long
long long sumUnderModulo(long long a, long long b)
{
	int mod = 1000000007;
	return (long long)((a % mod + b % mod)) % mod;
}
void solve_sumUnderModulo() {
	long long  a = 9223372036854775807;
	long long b = 9223372036854775807;
	cout << sumUnderModulo(a, b);
}


////////////////////////////////////
// addition of number in string form

void add_two_large_string_numbers(string &a,  string &b) {
	int aL = a.size();
	int carry = 0;
	string ans = "";
	for (int i = aL - 1; i >= 0; i--) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry ;
		ans.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	if (carry)
		ans.push_back(carry + '0');
	reverse(ans.begin(), ans.end());
	cout << ans;

}

void solve_add_two_large_string_numbers() {
	// sum two large numbers
	// string a = "2223372036854775807";
	// string b = "2223372036854775807";

	// string a = "9223372036854775807";
	// string b = "9223372036854775807";

	// string a = "9223372036854775807";
	// string b = "9223372";

	string a = "12";
	string b = "198111";

	// string a = "9234";
	// string b = "2245";
	// cout << a << endl << b << endl;
	int aL = a.length();
	int bL = b.length();

	if (aL < bL) {
		int diff = bL - aL;
		a.resize(bL);
		reverse(a.begin(), a.begin() + aL);
		reverse(a.begin(), a.end());
		for (int i = 0; i < diff;  i++)
			a[i] = '0';
	}  else { // bL < aL
		int diff =   aL - bL;
		b.resize(aL);
		reverse(b.begin(), b.begin() + bL);
		reverse(b.begin(), b.end());
		for (int i = 0; i < diff;  i++)
			b[i] = '0';
	}
	// cout << a << " " << b ;
	add_two_large_string_numbers(a ,b);
}
////
string add_two_large_string_numbers1(string a, string b) {
	//  a = "198111" b = "12"
	//  a = "12"  b = "198111"
	if (a.length() > b.length()) swap(a, b);

	string str = "";

	int n1 = a.length(), n2 = b.length();

	// reverse both the string
	// a = "12"  b = "198111"
	// a = "21" b = "111891"
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;
	for (int i = 0; i < n1; i++) {
		int sum = ((a[i] - '0') + (b[i] - '0')  + carry);
		str.push_back(sum % 10 + '0');

		// calculate the carray of larger number
		carry = sum / 10;
	}

	for (int i = n1; i < n2; i++) {
		int sum = ((b[i] - '0') + carry);
		str.push_back(sum % 10 + '0');

		// calculate the carray of larger number
		carry = sum / 10;
	}

	//  add reamaning carray
	if (carry) {
		str.push_back(carry + '0');
	}

	// revverse string
	reverse(str.begin(), str.end());
	return str;
}

void solve_add_two_large_string_numbers1() {
	// string a = "9234";
	// string b = "2245";
	string a = "12";
	string b = "198111";
	cout << add_two_large_string_numbers1(a, b);
}

///////////////////////////////////////////////////////////////
// Multiplication Under Modulo
int multiplicationUnderModulo(long long a, long long b)
{
	long M = 1000000007;
	a = a % M;
	b = b % M;
	return (a * b) % M;
}

void solve_multiplicationUnderModulo() {
	long long a = 92233720368547758;
	long long b = 92233720368547758;
	cout << multiplicationUnderModulo(a, b);
}

/////////////////////////////////////////////
//  Modular Multiplicative Inverse
int modInverse(int a, int m)
{
	int i = 1;
	while(i < m) {
		if((i * a) % m == 1) return i;
		i++;
	}
	return -1;
}
void solve_modInverse() {
	int a = 3, m = 11;
	cout << modInverse(a, m);
}


int main() {
	// solve_digitsInFactorial();
	// solve_isPrime();
	// solve_divisor();
	// solve_exactly3Divisors();
	// solve_sumUnderModulo();
	// solve_add_two_large_string_numbers();
	// solve_add_two_large_string_numbers1();
	// solve_multiplicationUnderModulo();
	solve_modInverse();
}