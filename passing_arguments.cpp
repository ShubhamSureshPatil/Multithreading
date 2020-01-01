#include<iostream>
#include<vector>
#include<string>
#include<thread>

using namespace std;

int main(){
	string s{"shubham"};

	// Pass by value to thread
	thread t1([=]{cout << s << endl;});

	// Pass by refernce to thread
	thread t2([&]{cout << s << endl;});

	t1.join();
	t2.join();
}