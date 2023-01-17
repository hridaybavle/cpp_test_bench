#include <memory>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>

using namespace std;


struct A
{
  std::vector<int> a;
  A(std::vector<int> a) : a(a) {}

};

std::mutex a_lock;

void func_change_a(shared_ptr<A> a) {
    shared_ptr<A> b = a;
    int counter=0;
    while(counter < 1000) {    
        b->a[0] = counter+10;
        cout << "b value inside func: " << b->a[0] << endl; 
        counter++;
    }       
}

void func_increse_a_size(shared_ptr<A> a) {
    int counter=0;
    while(counter < 1000) {
        a->a[0] = counter+10;
        cout << "a size inside func insrease a size: " << a->a[0] << endl; 
        counter++;
    }
}

int main(int argc, char **argv) {
    std::cout << "Inside Main" << std::endl;
    std::vector<int> num; num.push_back(1);
    shared_ptr<A> a(new A(num));
    a->a.resize(1000);

    std::thread t1(func_change_a, a);
    std::thread t2(func_increse_a_size, a);

    t1.join();   
    t2.join();
                                                         
    return 0;
}