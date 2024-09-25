#ifndef Xcept_
#define Xcept_

#include <exception>
#include <new>

class OutOfBounds : public std::exception {
   public:
      OutOfBounds() {}
};

class NoMem : public std::exception {
   public:
      NoMem() {}
};

void my_new_handler() {
   throw NoMem();
}

std::new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

#endif
