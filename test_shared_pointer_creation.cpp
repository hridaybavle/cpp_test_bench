#include <unistd.h>

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

struct A {
  int a;
  A(int a) : a(a) {}
};

int main(int argc, char **argv) {
  std::cout << "Inside Main" << std::endl;

  int num = 1;
  shared_ptr<A> obj1;
  shared_ptr<A> obj2;

  obj1 = make_shared<A>(num);
  std::cout << "obj1 a value: " << obj1->a << std::endl;
  std::cout << "obj1 use count: " << obj1.use_count() << std::endl;

  num = 2;
  obj2 = obj1;
  std::cout << "obj1 a value: " << obj1->a << std::endl;
  std::cout << "obj1 use count: " << obj1.use_count() << std::endl;

  // std::cout << "obj2 a value: " << obj2->a << std::endl;

  return 0;
}