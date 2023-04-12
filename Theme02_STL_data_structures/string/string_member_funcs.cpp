#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string s(5, 'a');	// s = "aaaaa"
	string t = "Hello World!";	// == t("Hello World!")

	s.pop_back();	// s = "aaaa"
	s.push_back('b');	// s = "aaaab"
	s.insert(s.begin() + 1 , 'c');	// insert 'c' at s[1], s = "acaaab"
	s.insert(s.begin() + 3, 2, 'd');	// insert 'dd' at s[3], s = "acaddaab"
	s.erase(s.begin() + 1);	// erase s[1], s = "aaddaab"
	s.erase(s.begin() + 2, s.end());	// erase[s[2], s.end()), s = "aa"
	s.insert(s.begin(), t.begin(), t.begin() + 5);	// insert [t[0], t[5]) at s[0], s = "Helloaa"

	cout << "s.size() : " << s.size() << '\n';	// 7
	cout << "s.empty() : " << s.empty() << '\n' << '\n';	// 0
	s.resize(4);	// s = "Hell"
	s.clear();	// s = ""
	s.resize(3, 'a');	// s = "aaa"

	cout << "t.substr(0, 5) : " << t.substr(0, 5) << '\n';	// "Hello"
	cout << "t.substr(6) : " << t.substr(6) << '\n';	// "World!"
	cout << "t.find(\'!\') : " << t.find('!') << '\n';	// 11 (t[11] == '!')
	cout << "t.find(\'?\') : " << t.find('?') << ' ' << string::npos << ' ' << typeid(string::npos).name() << '\n';	// 4294967295 == (unsinged int)(-1)
	cout << "s + t : " << s + t << '\n' << '\n';	// s + t == "aaaHello World!"

	for (string::iterator it = t.begin(); it != t.end(); it++)
		cout << *it;
	cout << '\n';
	for (string::reverse_iterator it = t.rbegin(); it != t.rend(); it++)
		cout << *it;
	cout << '\n';
	cout << "t.front() : " << t.front() << '\n';	// 'H'
	cout << "t.back() : " << t.back() << '\n';	// '!'
}
