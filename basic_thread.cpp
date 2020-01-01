/*
Basic C++ program to 

To launch a thread in C++, you have to include the <thread> header.

1. A thread std::thread represents an executable unit. 
This executable unit, which the thread immediately starts, gets its work package as a callable unit.

2. A callable unit is an entity that behaves like a function. Of course, it can be a function, 
but also a function object or a lambda function.
*/

#include<iostream>
#include<thread>

using namespace std;

void hellofn(){
	cout << "Hello from function" << endl;
}

class helloObject{
public:
	void operator()() const{
		cout << "Hello from class object" << endl;
	}
};



int main(){
	std::thread t1(hellofn);
	helloObject hello;
	std::thread t2(hello);
	std::thread t3([]{std::cout << "Hello from a lambda." << std::endl;});	
	t1.join();
	t2.join();
	t3.join();
	return 0;
}