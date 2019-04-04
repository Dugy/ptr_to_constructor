#include <iostream>
#include <string>
#include "ptr_to_constructor.hpp"

struct A {
	std::string a;
	virtual std::string print() = 0;
	A(std::string source)
		: a(source) {}
	virtual ~A() = default;
};

struct B : public A {
	virtual std::string print() {
		return a;
	}
	B(std::string source)
		: A(source) {}
	virtual ~B() = default;
};

int main() {
	std::unique_ptr<A>(*test)(std::string) = &construct<A, B>;
	std::unique_ptr<A> made = test("Hello World!");
	std::cout << made->print() << std::endl;

	std::shared_ptr<A>(*test2)(std::string) = &constructShared<A, B>;
	std::shared_ptr<A> made2 = test2("Hello World Again!");
	std::cout << made2->print() << std::endl;
 
	A*(*test3)(std::string) = &constructRaw<A, B>;
	A* made3 = test3("And Hello World Again!");
	std::cout << made3->print() << std::endl;

	std::unique_ptr<std::string>(*test4)() = &construct<std::string>;
	std::unique_ptr<std::string> made4 = test4();
	std::cout << (made4->empty() ? "One Final Hello World!" : "Fail") << std::endl;
}
