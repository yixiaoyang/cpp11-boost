#define BOOST_LOG_DYN_LINK 1

#include <boost/log/trivial.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>

int test1(){
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    return 0;
}

void hello_world(){
	std::cout << "Hello world, I'm a thread!" << std::endl;
}

void test2(){
	boost::thread my_thread(&hello_world);
  	my_thread.join();
}

int main (int argc, char* argv[]){
	test1();
	test2();
	return 0;
}
