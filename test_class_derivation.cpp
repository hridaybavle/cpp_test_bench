#include <unistd.h>

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class A {
 protected:
  int variable = 0;

 public:
  A() {}
};

class B : public A {
 public:
  B() { variable = 1; }

  int get_variable() { return variable; }
};

int main(int argc, char **argv) {
  std::cout << "Inside Main" << std::endl;

  shared_ptr<B> b(new B());
  std::cout << "variable at start: " << b->get_variable() << std::endl;

  return 0;
}