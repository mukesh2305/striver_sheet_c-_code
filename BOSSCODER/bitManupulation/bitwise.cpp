#include <bits/stdc++.h>
using namespace std;

int print_int(int arr[], int n) {
	// evry integer occurs twise one integer occures one's so print that int
	int XOR	 = 0;
	// map<int, int> mp;
	for (int i = 0; i < n; i++) {
		// mp[arr[i]]++;
		XOR ^= arr[i];
	}
	// for (auto it : mp) {
	// 	if (it.second  == 1) cout << it.first << "\n";
	// }
	return XOR;
}

void  swap_number(int a, int b) {
	// swap two number using bitwise xor
	cout << a << " " << b << "\n" ;
	a =  a ^ b;
	b = a ^ b ;
	a = a ^ b;
	cout << a  << " " << b;
}
void nth_bit_set_or_not(int a) {
	// int aa = (a >> 1);
	//  5     			= 101
	// 1 >> 1 			= 010
	//  5 & (1 >> 1)   = 000
	// first solution
	// if ( (a >> 1) & 1) cout << a << " set";
	// else cout << a << " not set";

	// second solution
	if ((a & (1 << 1))) cout << " set" << " " << a;
	else cout << " not set " << a << endl;
}
void count_the_set_bit(int a) {
	int count = 0;
	//  total complxity = O(total bits in n)
	while (a != 0) {
		// cout << a << " a " << endl;
		// if(a & 1) { // 1 than go
		// 	count++;
		// }

		count += (a & 1); // (a & 1) => return 1 and 0 => number is even than 1 number is odd than 0;
		a = a >> 1; // n = n/2;
	}
	cout << count;
}

// brian keringame algo
void countBits(int n) {
	int count = 0;
	while ( n != 0) {
		n = n & (n - 1);
		count++;
	}
	cout << count << endl;
}

bool number_is_power_of_2(int n) {
	// cout << (1 << 3) << endl;
	int result = 0;
	int i  = 1;
	if ( n == 0) return false;
	if(n == 1) return true;
	if (!(n & 1)) {
		while (true) {
			result = (1 << i);
			if (result == n) return true;
			if ( result > n) return false;
			i++;
		}
	}
	return false;

}

// brian keringame algo using calculate number if power of 2
// brian keringame algorithem use for calculating the set bit of number
// if set bit is more than 1 than numbe is not a power of 2

// bool brian_2_power(int n) {
// 	int count = 0;
// 	if ( n == 0) return false;
// 	while ( n != 0) { // power of 2 number has 1 bit set
// 		n = n & (n - 1); // if count is more than 1 than it it not power of 2
// 		count++;
// 		if (count > 1) return false;
// 	}

// 	return true;

// }


bool brian_2_power(int n) {
	// first way
	// if ( n == 0) return false;
	// return ((n & (n -1)) == 0);


	// second way
	return (n != 0) && ((n & (n - 1)) == 0);
}


// find missing number from the range in the array
int find_missing_number(int arr[], int n) {
	int mx = *max_element(arr, arr + n);
	int mn = *min_element(arr, arr + n);
	int result = 0;
	for (int i = 0; i < n; i++) result ^= arr[i]; // xor all the numbers
	for (int i = mn; i <= mx; i++) result ^= i; // number that match cancel but number that not match becomes result
	return result;
}
// Time Complexity of this algo is O(n), and space complexity is O(1);
void find_2_odd_times_upper_number(int arr[], int n) {
	int x = 0;
	int first = 0, second = 0;
	for (int i = 0; i < n; i++) {
		x ^= arr[i];
	}

	int rg_bit_set = x & ~( x - 1); // set second bit using this formula

	for (int i = 0; i < n; i++) {
		// this process make 2 buckets first with number as 1 bit after &
		// second with number as 0 bit set after & operation
		if (arr[i] & rg_bit_set ) { // this return positive number
			first ^= arr[i];
		} else {   // return 0 number
			second ^= arr[i];
		}
	}

	cout << first << " " << second;

}

// powerset using bitwise operator
void powerset(string str, int n) {
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i & 1 << j)) cout << str[j] << "";
		}
		cout << "\n";
	}
}

//   position of first set bit
int set_pos(int a) {
	int count  = 1;
	while (a != 0) {
		if (a & 1) return count;
		a = a >> 1;
		count++;
	}

	return -1;
}

// ===========================================================
// function to find first position with diffrent bits
int posOfRightMostDiffBit(int m , int n) {
	if (m < n) swap(m , n);
	int count = 0;
	while (m != 0) {
		if ( (m & 1)  && (n & 1) ) count++;
		else if ( !(m & 1) && !(n & 1)) count++;
		else return count++;
	}
	return -1;
}

int posOfRightMostDiffBit1(int m, int n) {
	int count = 1;
	if (m == n ) return -1; // no bit differ
	while (n > 0 || m > 0) {
		if (n % 2 != m % 2) return count;
		count++;
		m = m >> 1;
		n = n >> 1;
	}
	return -1;
}

int posOfRightMostDiffBit2(int m , int n) {
	if (m == n) return -1;
	int x = m ^ n; // only bit remains they are diffrent
	int count = 1 ;
	while (x != 0) {
		if ( x & 1) return count;
		count++;
		x = x >> 1;
	}
	return -1;
}


int posOfRightMostDiffBit3(int m , int n) {
	if (m == n) return -1;
	int x = m ^ n;
	return log2(x & ~(x - 1)) + 1 ;
}

// =========================================================


// =========================================================
// calculate total number of bit set in the number 1 to n
int bitSet_total(int n) {
	int count = 0;
	for (int j = 1; j <= n; j++) {
		int i = j;
		while (i != 0) {
			if (i & 1) count++;
			i = i >> 1;
		}

	}
	return count;
}

int largetPowerOf2(int n) {
	int x = 0;
	while ((1 << x) <= n) x++;
	return x - 1; // when condition is wrong than x value is 1 extra count added that's why we -minus one
}

int bitSet_total1(int n) {
	if (n == 0) return 0;
	int x = largetPowerOf2(n);
	int bitsetUpto2raiseTox = (1 << (x - 1)) * x;
	// reaning bit from 2 raiseto power x to n
	int reamaningBit = n - (1 << x) + 1;
	int rest = n - (1 << x);
	int ans =  bitsetUpto2raiseTox + reamaningBit + bitSet_total1(rest);
	return ans;
}
// =======================================================
// count the differ bit from the 2 numbes
int differ_bit(int a, int b) {
	int res = a ^ b, count = 0;
	while (res != 0) { //logn complexity
		count += (res & 1);
		count++;
	}
	return count;
}

int differ_bit1(int a , int b) {
	int res = a ^ b, count = 0;
	while (res != 0) { //logn complexity
		res = res & (res - 1);
		count++;
	}
	return count;
}
int differ_bit2(int a , int b) {
	int res = a ^ b;
	return __builtin_popcount(res); // inbuit function log(N) time complexity
}
// ================================================================
// if numebr is spare or not // means consicutive bit are set than number is not spare if not than number is spare
int isSpare(int n) {
	int count = 0;
	while (n != 0) {
		if (n & 1 ) count++;
		else count = 0;
		if (count == 2) return 0;
		n = n >> 1;
	}

	return 1;
}

int isSpare1(int n ) {
	return ((n & (n >> 1)) == 0);
}
// ===================================================================
// count maximum consicutive set bit;
int mx_consicutive_set_bit(int n ) {
	int cnt = 0;
	vector<int> mx_cnt;
	while (n != 0) {
		if (n & 1) cnt++;
		else {
			mx_cnt.push_back(cnt);
			cnt = 0;
		}
		n = n >> 1;
	}

	mx_cnt.push_back(cnt);
	return *max_element(mx_cnt.begin(), mx_cnt.end());
}

int mx_consicutive_set_bit1(int n) {
	int cnt = 0, mx_cnt = 0;
	while ( n != 0) {
		if (n & 1) cnt++;
		else cnt = 0;
		if (cnt > mx_cnt) mx_cnt = cnt;
		n = n >> 1;
	}

	return mx_cnt;
}

int mx_consicutive_set_bit2(int n ) {
	int cnt = 0;
	while ( n != 0) {
		n = (n & (n >> 1)); // 111  // if no consicutive bit than it give so loop while stop
		cout << n << endl;  // 011  // if yes bit are consiquite than it while continue to run and count++;
		cnt++;
	}
	return cnt;
}
// =====================================
// convert binary to greycode

int  binary_to_gray_code(int n) {
	return n ^(n >> 1); // this way to find gray code
}
vector<int> binary_to_gray_code1(int n) {
	int temp = n;
	vector<int> bin;
	while(temp != 0) {
		bin.push_back(temp % 2);
		temp /= 2;		
	}
	// 110
	reverse(bin.begin(), bin.end());
	return bin;
}

string binary_to_gray_code3(int n) {
	string bin;
	while(n != 0) {
		bin += ((n % 2) + '0');
		n /= 2;		
	}
	// 110
	reverse(bin.begin(), bin.end());
	return bin;
}

string binary_to_gray_code2(int n ) {
	string bin;
	for(int i = 31 ; i>= 0	; i--) {
		int k = n >> i;
		if(k & 1) bin += '1'    ;
		else   bin += '0' ;
	}

	return bin;
}
// ============================================================
//  swap bits even place of odd wise versa
int swap_bits(int n) {
	int od = 0x55555555; // maks for odd -> because all the odd bit are 1 
	int ev = 0xAAAAAAAA; // mask for even -> because all the even bits are 1

	int odds = (n & od);  // reserve odd bits 
	int evens = (n & ev); // reverse even bits

	odds <<= 1; // odd bits are became evens
	evens >>= 1; // evens bits ae becoms odd

	n = odds | evens; // now bits are completely shifted
	return n;
}
// =========================================================
// max & value

int max_AND_vlaue(int arr[],int  n) {
	int count = 0;
	for(int i = 0; i<n; i++) {

		for(int j = i + 1; j<n; j++) {
			int m = (arr[i] & arr[j]);
			if(m > count) count = m;
		}
	}

	return count ;
}
int checkBit(int pattern, int arr[], int n) {
	int count = 0;
	for(int i = 0; i<n;i++) {
		if((pattern & arr[i]) == pattern)
			count++;
	}

	return count;
}
int max_AND_vlaue1(int arr[], int n ) {
	int res = 0, count ;
	// take 31 bit to 0 bit , because total bit in the the number is 32
	for(int bit = 31 ; bit >= 0; bit--) {
		count = checkBit(res | 1 << bit, arr, n);

		if(count >= 2) {
			res |= (1 << bit);
		}
	}
	return res;
}

int main() {
	// int arr[] = {2, 1, 2, 5, 6, 5, 7, 7, 6};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << print_int(arr, n);

	// int a = 5, b = 7;
	// swap_number(a, b);

	// int a = 5;
	// nth_bit_set_or_not(a);

	// int a = 3356;
	// count_the_set_bit(a);



	// int a = 7;
	// countBits(a);


	// int n = 16;
	// if (number_is_power_of_2(n)) cout << " yes ";
	// else cout << " no " << "\n";

	// int n = 7;
	// if (brian_2_power(n)) cout << " yes ";
	// else cout << " no " << "\n";


	// question : all the numbers are appear in the even number of times
	// except 1 number is apper odd number of times
	// int arr[] = {4, 3,3, 4,3 , 4, 4, 5, 5};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << print_int(arr, n);


	// find the missing number from array
	// int arr[] = { 1, 4, 3};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << find_missing_number(arr, n);


	// question 2 : all the numbers are appear in the even number of times
	// except 2 number is apper odd number of times
	// int arr[] = { 3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
	// // last_1 = {3, 3, 5, 7, 7} //when we do xor = then 5 reamins
	// // last_0 = {4, 4, 4, 4, 6} //when we do xor = then 6 reamins
	// int n = sizeof(arr) / sizeof(arr[0]);
	// find_2_odd_times_upper_number(arr, n);

	// question 3: using powerset algo find subset of strig
	// string str = "abc";
	// int n = str.length();
	// powerset(str, n);


	// // first postion of set bit
	// int a = 3365;
	// cout << set_pos(a);


	// function to find first position with diffrent bits
	// int m = 11, n = 9;
	// // cout << posOfRightMostDiffBit(m , n);
	// cout << posOfRightMostDiffBit3(m , n);


	// calcualte total number of bitset from 1 to n
	// int n = 4;
	// // cout << bitSet_total(n);
	// cout << bitSet_total1(n);


	// number is spare or not
	// int n = 5;
	// // if(isSpare(n)) cout << "yes";
	// // else cout << " no ";
	// if(isSpare1(n)) cout << " yes";
	// else cout << "no";


	// calculate mx consicutive set bit
	// int n = 14;
	// cout << mx_consicutive_set_bit(n);
	// cout << mx_consicutive_set_bit1(n);
	// cout << mx_consicutive_set_bit2(n);


	// binary to gray code
	// int n = 6;
	// cout << binary_to_gray_code(n);
	// for(auto it : binary_to_gray_code1(n)) {
	// 	cout << it << " ";
	// }
	 // cout << binary_to_gray_code2(n);
	// cout << binary_to_gray_code3(n);


	// swap bits form odd to even and even to odd
	// int n = 23;
	// cout << swap_bits(n);

	// maximum & value
	int arr[] = {4, 8,12, 16 };
	int n = sizeof(arr)/ sizeof(arr[0]);
	cout << max_AND_vlaue(arr, n);
}