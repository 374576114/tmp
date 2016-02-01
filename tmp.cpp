#include <iostream>
#include <stdio.h>
using namespace std;

class base{
	int a;
public :
	base(){a = 0;}
	virtual void show(){
		cout<<"base " << a<< endl;
	}
	virtual ~base(){ cout<<"base ~base"<<endl;
	}
};

class b: public base{
	int ba;
public :
	b():base(){
		ba = 1;
	}
	void show(){
		cout<<"b "<<ba<<endl;
	}
	~b(){}
};

int main(){
	base *p = NULL;
	p = new base();
	p = new b();

	p->show();
	p->base::show();

	return 0;
}

