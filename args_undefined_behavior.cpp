#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<chrono>

/*
Undefined behavior due to interleaving of operations: Data race
*/


using namespace std;

class sleeper{
private:
	int& i;
public:
	sleeper(int& i_):i{i_}{};
	void operator()(int k){
		for (unsigned int j = 0; j <= 5; j++){
			this_thread::sleep_for(chrono::milliseconds(100));
			i+=k;
		}
		cout << this_thread::get_id() << endl;
	}
};


int main(){
	std::cout << std::endl;
  	int valSleeper = 1000;
  	std::thread t(sleeper(valSleeper), 5);
  	// t.detach();	// The thread will leave and never return	ans:1000
  	t.join();		// This will stop data race condition		ans:1060
  	std::cout << "valSleeper = " << valSleeper << std::endl;

  	std::cout << std::endl;
	return 0;
}