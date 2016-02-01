#include <iostream>
using namespace std;
class BASE{
	public:
		BASE(){
			cout<<"BASE"<<endl;
		}
};
class A{
	int a;
protected :
	int b;
public :
	int c;
	
	A(){
		a = 0;
		b = 0;
		c = 0;
		cout<<"A"<<endl;
	}
	void print(){
		cout<<"A"<<a<<" "<<b<<" "<<c<<endl;
	}
	~A(){
		cout<<"～A"<<endl;
	}
};

class B:virtual protected A{
	int a;
protected :
	int b;
public: 
	int c;
	B(): A(){
		a = 0;
		b = 0;
		c = 0;
		cout<<"B"<<endl;
	}
	void test(int x){
		A::c = x;
		A::b = x;
	}
	void print(){
		cout<<"B"<<a<<b<<c<<endl;
		cout<<"B>A"<<A::b<<A::b<<endl;
	}
	~B(){
		cout<<"~B"<<endl;
	}

};
class C: virtual A{
	int a;
protected:
	int b;
public :
	int c;
	C(){
		a = 0;
		b = 0;
		c = 0;
		cout<<"C"<<endl;
	}
	void test(int x){
		A::b = x;
		A::c = x;
		cout<<"C"<<a<<b<<c<<endl;
		cout<<"C>A"<<A::b<<A::b<<endl;
	}
	void print(){
		cout<<"C"<<a<<b<<c<<endl;
		cout<<"C>A"<<A::b<<A::b<<endl;
	}


};
struct D: B,C{
	int a;
protected:
	int b;
public :
	int c;
	D(){
		a = 0;
		b = 0;
		c = 0;
		cout<<"D"<<endl;
	}
	void test(int x){
		//B::A::b = x;
		B::A::c = x;
		B::b = x;
		B::c = x;
		C::b = x;
		C::c = x;
		cout<<"C::test(2) ";
		B::test(3);
		cout<<"B::print ";
		B::print();
		cout<<"C::print ";
		C::print();
	}
};
int main(){
	D b;
}
