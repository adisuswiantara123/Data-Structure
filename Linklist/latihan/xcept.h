#ifndef Xcept_
#define Xcept_

#include <exception>
#include <new>
#include <iostream>
class BadInitializers {
   public:
      BadInitializers() {}
};

class NoMem {
   public:
      NoMem() {}
};

void my_new_handler()
{
   throw NoMem();
}

std::new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

class OutOfBounds {
   public:
      OutOfBounds() {}
};

class SizeMismatch {
   public:
      SizeMismatch() {}
};

class MustBeZero {
   public:
      MustBeZero() {}
};

class BadInput {
   public:
      BadInput() {}
};

#endif
