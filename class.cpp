#include <stdio.h>
#include <iostream>
using namespace std;

class A{
public:
	A(){ cout<<"A"<<endl;}
};
class B{
public:
	B(){ cout<<"B"<<endl;}
};
class C{
public:
	C(){ cout<<"C"<<endl;}
};
class D:A,C,virtual B{
public:
	A a;
	B b;
	C c;
	D():a(),b(),c(){ cout<<"D"<<endl;}
};


int main(){
	D d;

	return 0;
}
