#include <cstdio>
#include <iostream>

class A{
	~A(){
		cout << "IN DESC\n";
	}
};

int main(){
	A a;
	a.~A();
}
