// xcept.h
// exception classes for various error types

#ifndef Xcept_
#define Xcept_

#include <stdexcept>
#include <new>

// bad initializers
class BadInitializers {
   public:
      BadInitializers() {}
};

// insufficient memory
class NoMem : public std::bad_alloc {
   public:
      NoMem() {}
};

// change new to throw NoMem instead of std::bad_alloc
void my_new_handler()
{
   throw NoMem();
}

std::new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

// improper array, find, insert, or delete index
// or deletion from an empty structure
class OutOfBounds {
   public:
      OutOfBounds() {}
};

// use when operands should have matching size
class SizeMismatch {
   public:
      SizeMismatch() {}
};

// use when zero was expected
class MustBeZero {
   public:
      MustBeZero() {}
};

// use when zero was expected
class BadInput {
   public:
      BadInput() {}
};

#endif
