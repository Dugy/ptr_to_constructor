# Pointer to constructor
C++ allows taking pointers to funcitons, pointers to methods, but not pointers to constructors. It can be useful when creating various objects to store in a common parent class.

## Basic usage
This line grabs pointer to a function that returns a unique pointer to a string.
```C++
std::unique_ptr<std::string>(*test)(std::string) = &construct<std::string>;
```

It can be later called to make unique_pointers to strings:
```C++
std::unique_ptr<std::string> made = test("Hello World!");
```

## With inheritance

If there are two template arguments, the first is the returned parent class, the second is the constructed child class.

```C++
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

std::unique_ptr<A>(*test)(std::string) = &construct<A, B>;
std::unique_ptr<A> made = test("Hello World!");
```

## Other pointer types

You can use `constructShared` to have a function that returns shared pointers and `constructRaw` to have a function that returns raw pointers.

```C++
A*(*test)(std::string) = &constructRaw<std::string>;
```

## With more constructors

If there are more constructors, it will be derived according to the function pointer type saved it's saved into.

```C++
std::unique_ptr<std::string>(*test)() = &construct<std::string>;
```
