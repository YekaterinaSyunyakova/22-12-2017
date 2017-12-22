

#include "stdafx.h"

class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	A(int x) : value(x) {
		std::cout << "A(int)" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
	int value;
	friend std::ostream & operator<<(std::ostream &, const A &);
	friend void operator >> (std::istream & stream, const A & a);
};
std::ostream & operator<<(std::ostream & stream, const A & a)
{
	return stream << a.value;
}
void operator >> (std::istream & stream, const A & a) {
	stream >> a;
}
class Finder {
public:
	Finder(int y) : x(y) {}
	int x;
	bool operator()(const A & a) {
		return x == a.value;
	}
};
void algorithm() {
	std::vector<A> x = { A(1), A(2), A(3) };
	std::for_each(x.begin(), x.end(), [](A a) { std::cout << a.value << '\t'; });
	std::cout << std::endl;
	int y;
	std::cin >> y;
	Finder f(y);
	auto a = std::find_if(x.begin(), x.end(), f);
	auto b = std::find_if(x.begin(), x.end(), [y](A & a) {return a.value == y; });
	if (a != x.end()) {
		std::cout << *a << '\t' << *b << std::endl;
	}
	else {
		std::cout << "not found" << std::endl;
	}
}
void sorter() {
	std::string s = "123456789";
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j < s.length(); ++j) {
			if (i != j && s[i] == s[j]) {
				std::cout << "not unique";
				return;
			}
		}
	}
	s = "1223456789";
	bool arr[256] = { false };
	for (int i = 0; i < s.length(); ++i) {
		int temp = (int)(s[i] - 48);
		if (arr[temp]) {
			std::cout << "not unique";
			return;
		}
		arr[temp] = true;
	}
	s = "1234657891";
	std::sort(s.begin(), s.end());
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == s[i - 1]) {
			std::cout << "not unique";
			return;
		}
	}
	std::cout << "unique";
}
int main()
{
	srand(time(NULL));
	std::vector<int> x(20);
	std::for_each(x.begin(), x.end(), [](int & a) {
		a = rand() % 10;
		std::cout << a << '\t';
	});
	std::cout << std::endl;
	/*std::cout << *std::min_element(x.begin(), x.end()) << '\t';
	std::cout << *std::max_element(x.begin(), x.end()) << '\t';
	std::sort(x.begin(), x.end(), std::greater<int>());
	std::sort(x.begin(), x.end(), std::less<int>());*/
	/*int n = 4;
	std::for_each(x.begin(), x.end(), [n](int & a) { a += n; });
	std::for_each(x.begin(), x.end(), [n](int & a) { a -= n; });*/
	/*auto it = x.begin();
	while (it != x.end()) {
	auto y = std::find(it, x.end(), 1);
	if (y != x.end()) {
	x.erase(y);
	it++;
	}
	}*/
	x.erase(std::remove(x.begin(), x.end(), 4), x.end());
	std::cout << "after 4 is removed: " << std::endl;
	std::for_each(x.begin(), x.end(), [](int & a) {
		std::cout << a << '\t';
	});
	std::cout << std::endl;
	return 0;
}
