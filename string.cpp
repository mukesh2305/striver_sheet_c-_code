#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define prime 119
const int CHAR = 256;
/////////////////////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/////////////////////////////////////////////////////
// print frequencies of character in order in a string of lowercase alphabets

void solve_lower_case_order() {
    string str = "geeksforgeeks";
    int count[26] = {0};
    for (int i = 0; i < str.size(); i++) {
        count[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            cout << (char)(i + 'a') << " ";
        }
    }
}

////////////////////////////////////////////////////////////
// string is palindrome or not
bool isPali(string & str) {
    int l = 0, h = str.size() - 1;
    while (l <= h) {
        if (str[l++] != str[h--]) return false;
    }
    return true;
}

void solve_isPali() {
    string str = "mkum";
    if (isPali(str)) cout << " Yes " << endl;
    else cout << " No " << endl;
}

/////////////////////////////////////////////////////////////////////
// Check if a String is Subsequence of Other
// substring => means continuous character in the same order
// subsequences => means character in the same order but not continuous

// TC O(N + M)
bool subsequences(string & s1, string & s2) {
    int n = s1.size();
    int m = s2.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            i++, j++;
        } else i++;
    }
    return j == m;
}

// TC O(N + M)
bool subsequences_recursive(string & s1, string & s2, int n, int m) {
    if (m == 0) return true;
    if (n == 0) return false;
    if (s1[n - 1] == s2[m - 1]) return subsequences_recursive(s1, s2, n - 1, m - 1);
    else return subsequences_recursive(s1, s2, n - 1, m);
}
void solve_subsequences() {
    string s1 = "geeksforgeeks";
    string s2 = "gerges";

    int n = s1.size();
    int m = s2.size();
    // if(subsequences(s1, s2)) cout << " this is subsequences";
    if (subsequences_recursive(s1, s2, n, m)) cout << " this is subsequences";
    else cout << " not ";
}

///////////////////////////////////////////////////////////////////////////////
// Check for Anagram
// TC O(nlogn)
bool Anagram(string & s1, string & s2) {
    if (s1.length() != s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// TC O(n)
bool Anagram1(string & s1, string & s2) {
    if (s1.size() != s2.size()) return false;
    int count[CHAR] = {0};
    for (int i = 0; i < s1.size(); i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}


void solve_Anagram() {
    string s1 = "listen", s2 = "silent";
    if (Anagram(s1, s2)) cout << " yes " << endl;
    // if(Anagram1(s1, s2)) cout << " yes " << endl;
    else cout << " no " << endl;
}

/////////////////////////////////////////////////////////////////
// Leftmost Repeating Character
// TC O(N^2)
int leftMost(string & str) {
    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j]) return i;
        }
    }
    return -1;
}

// TC O(N)
int leftMost1(string & str) {
    int count[256] = {0};
    for (int i = 0; i < str.size(); i++) {
        count[str[i]]++;
    }
    for (int i = 0; i < str.size(); i++) {
        if (count[str[i]] > 1) return i;
    }
    return -1;
}

int leftMost2(string & str) {
    bool vis[256];
    fill(vis, vis + 256, false);
    int res = -1;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (vis[str[i]]) res = i;
        else vis[str[i]] = true;
    }
    return res;
}

void solve_leftMost() {
    string str = "abccbd";
    // cout << leftMost(str);
    // cout << leftMost(str);
    cout << leftMost2(str);
}

/////////////////////////////////////////////////////////////////////
// Leftmost Non-repeating Element
// TC O(N^2)
int notRep(string & str) {
    for (int i = 0; i < str.size(); i++) {
        bool flag  = false;
        for (int j = 0; j < str.size(); j++) {
            if (i != j && str[i] == str[j]) {
                flag = true;
                break;
            }
        }
        if (flag == false) return i;
    }
    return -1;
}

// TC O(N)
int notRep1(string & str) {
    int FI[256];
    fill(FI, FI + 256, -1);
    for (int i = 0; i < str.size(); i++) {
        if (FI[str[i]] == -1)
            FI[str[i]] = i;
        else
            FI[str[i]] = -2;
    }

    int res = INT_MAX;

    for (int i = 0; i < 256; i++) {
        if (FI[i] >= 0) {
            res = min(res, FI[i]);
        }
    }
    return (res == INT_MAX) ? -1 : res;
}

void solve_notRep() {
    string str = "geeksforgeeks";
    cout << notRep(str) << endl;
    // cout << notRep1(str) << endl;
}
//////////////////////////////////////////////////////////
// reverse word in string

// 1st approach
vector<string> rev_words_in_string(string & str) {
    stack<string> words;
    vector<string> ans;

    // split the string into the words
    string word = "";
    for (char c : str) {
        if (c == ' ') {
            words.push(word + " ");
            word = "";
        } else {
            word += c;
        }
    }
    words.push(word + " ");

    while (!words.empty()) {
        ans.push_back(words.top());
        words.pop();
    }

    return ans;
}

//2nd approach
void rev_words_in_string1(string & str) {
    stringstream ss(str); // create a string stream from the string
    string word;
    string reversed = "";
    while (ss >> word) { // read in each word
        reversed = word + " " + reversed; // add the word to the front of the reversed string
    }
    str = reversed;
}

//3nd approach
void rev_words_in_string2(string & str) {
    int n = str.size();
    int start = 0;
    for (int end = 0; end < n; end++) {
        if (str[end] == ' ') {
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
    }
    // reverse last word
    reverse(str.begin() + start, str.end());

    // reverse whole string
    function<void(int, int)> rev_str = [&](int l, int r) {
        while (l < r) {
            swap(str[l++], str[r--]);
        }
    };
    rev_str(0, n - 1);
}

void rev_words_in_string() {
    string str = "my name is mukesh";
    // for(auto word : rev_words_in_string(str)) cout << word;
    rev_words_in_string1(str);
    // rev_words_in_string2(str);
    cout << str << endl;
}

///////////////////////////////////////////////////////////////////
// Overview of Pattern Searching
// m -> pattren length
// n -> Text length
// 1 <= m <= n
// ---------- no preprocessing -------------
// naive Algo :-> O((n - m + 1) * m)
// naive when all characters of pattren are distinct :- O(n)

// ----------- preprocess pattren -------------------------
// Robin karp Algo: O((n - m + 1) * m) -> but bettre than naive on avarage
// KMP Algo: O(n)

// ----------- preprocess Text --------------------------
// suffix Tree Alog : O(m)

// TC O((n - m + 1) * m)
vector<int> naive_Algo(string & txt, string & pat) {
    int n = txt.size(); // actual Text
    int m = pat.size(); // pattren

    vector<int> vec;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == m)
            vec.push_back(i);
    }
    return vec;
}

// Improved Naive Pattern Searching for Distinct
vector<int> improved_naive_Algo(string & txt, string & pat) {
    // ABCABCD
    // ABCD
    int n = txt.size(); // actual Text
    int m = pat.size(); // pattren

    vector<int> vec;
    for (int i = 0; i <= n - m; ) {
        int j;
        for (j = 0; j < m; j++) {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == m)
            vec.push_back(i);
        if (j == 0)
            i++;
        else
            i = i + j;
    }
    return vec;
}

void solve_naive_Algo() {
    string txt = "ABCABCD";
    string pat = "ABCD";
    // for(auto i : naive_Algo(txt, pat)) cout << " index : " << i << endl;
    for (auto i : improved_naive_Algo(txt, pat)) cout << " index : " << i << endl;
}

//////////////////////////////////////////////////////////////
// pattren searching Algo
// Rabin Karp Algorithm ( this algo is optimize algo)
// TC O(n - m + 1)
// in worst case : it is called spurioustlits O(m * n)

// also take refrnce of abdul bari lectures
ll createHashValue(string str, int n) {
    ll result = 0;
    for(int i = 0; i < n; i++) {
        result += (ll)(str[i] * (ll)pow(prime, i));
    }
    return result;
}

ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patLength) {
    ll newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += (ll)(str[newIndex] * (ll)pow(prime, patLength - 1));
    return newHash;
}

bool checkEqual(string & str1, string & str2,int start1,int end1, int start2, int end2) {
    // if both string are equal or not
    if(end1 - start1 != end2 - start2) return false;
    while(start1 <= end1 && start2 <= end2) {
        if(str1[start1] != str2[start2])
            return false;
        start1++;
        start2++;
    }
    return true;
}
void rabin_karp_algo(string & pat, string & str) {
    int m = pat.size();
    int n = str.size();
    // this will give intial hash value of both sring and pattren
    ll patHash = createHashValue(pat, m);
    ll strHash = createHashValue(str, m);

    for(int i = 0; i <= n - m; i++) {
        if(patHash == strHash && checkEqual(str, pat, i, i + m - 1, 0, m - 1)){
            cout << " index " << i << endl;
            // break; // if we want to match 1 time than use break (we wanted to print first starting index of first word)
        }
        if(i < n - m) {
            strHash = recalculateHash(str, i, i + m, strHash, m);
        }
    }
}

void solve_rabin_karp_algo() {
    string str = "ababcabdabd";
    string pat = "abd";
    rabin_karp_algo(pat, str);
}

//////////////////////////////////////////////////////////////////////////
// Check if Strings are Rotations
bool areRotations(string & s1, string & s2) {
    if(s1.size() != s2.size()) return false;
    return ((s1 + s2).find(s2) != string::npos);
}
void solve_areRotations() {
    string s1 = "ABCD";
    string s2 = "CDAB";
    if(areRotations(s1, s2)) cout << " string are in rotations";
    else cout << " string not are in rotations";
}

/////////////////////////////////////////////////////////
// Anagram Search
// TC O(n + m)
bool f_Anagram(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    unordered_map<char, int> mp;
    for(char c : s1) mp[c]++;
    for(char c : s2) mp[c]--;
    for(auto i: mp){
        if(i.second != 0) 
            return false;
    } 
    return true;
}
bool isPresent_Anagram(string & str, string & pat) {
    int n = str.size();
    int m = pat.size();

    for(int i = 0; i <= n - m; i++) {
        if(f_Anagram(pat, str.substr(i, m))) return true;
    }
    return false;
}

// optimal approach
// TC O(n * CHAR)
bool areSame(int CT[], int CP[]) {  
    for(int i = 0; i < CHAR; i++) {
        if(CT[i] != CP[i]) return false;
    }
    return true;
}

bool isPresent_Anagram1(string & str, string & pat) {
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for(int i = 0; i < pat.size(); i++) { // => o(m)
        CT[str[i]]++;
        CP[pat[i]]++;
    }
    if(areSame(CT, CP)) return true;
    for(int i = pat.size(); i < str.size(); i++) { // => O(n - m)
        CT[str[i]]++;
        CT[str[i - pat.size()]]--;
        if(areSame(CT, CP)) return true; // => // => O(CHR)
    }
    return false;
}
void solve_isPresent_Anagram() {
    string str = "geeksforgeeks";
    string pat = "frog";
    // if(isPresent_Anagram(str, pat)) cout << "Yes";
    if(isPresent_Anagram1(str, pat)) cout << "Yes";
    else cout << "No";
}

////////////////////////////////////////////////////////////////////////////////////
// Lexicographic Rank of a String
// ref => https://www.youtube.com/watch?v=Yat41hRCKlE
long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// TC O(n * log(n)) => n for loop on string and logn for iteration on map
long long findRank(string s) {
    int n = s.size();
    long long rank = 1;
    unordered_map<char, int> char_freq;
    for(char c : s) {
        char_freq[c]++;
    }

    for(int i = 0; i < n; i++) {
        // count the number of charcater lesser than current character
        int count = 0;
        for(auto pair : char_freq) {
            if(pair.first < s[i])
                count += pair.second;
        }

        // Update the rank by adding the number of permutations that come before S[i]
        rank += count * factorial(n - 1 - i);
        // Decrement the frequency of S[i] in the map
        char_freq[s[i]]--;
    }
    return rank;
}

void solve_findRank() {
    string s = "cab";
    cout << findRank(s);
}

///////////////////////////////////////////////////////////
// leetcode => 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubString(string s) {
    int n = s.size();
    set<char> st;
    int start = 0, end = 0, mx = 0;
    while(start < n) {
        if(st.find(s[start]) == st.end()) {
            mx = max(mx, start - end + 1);
            st.insert(s[start]);
            start++;
        } else {
            st.erase(s[end]);
            end++;
        }
    }
    return mx;
}

void solve_lengthOfLongestSubString() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubString(s);
}
int main() {
    init_code();

    //////////////////////////////
    // solve_lower_case_order();
    // solve_isPali();
    // solve_subsequences();
    // solve_Anagram();
    // solve_leftMost();
    // solve_notRep();
    // rev_words_in_string();
    // solve_naive_Algo();
    // solve_rabin_karp_algo();
    // solve_areRotations();
    // solve_isPresent_Anagram();
    // solve_findRank();
    solve_lengthOfLongestSubString();
}