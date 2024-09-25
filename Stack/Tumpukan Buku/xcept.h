// file xcept.h

#ifndef Xcept_
#define Xcept_

#include <stdexcept>

using namespace std;

class BadInitializers : public logic_error {
public:
  BadInitializers() : logic_error("Bad Initializers") {}
};

class NoMem : public bad_alloc {
public:
  NoMem() : bad_alloc() {}
};

class OutOfBounds : public out_of_range {
public:
  OutOfBounds() : out_of_range("Out of Bounds") {}
};

class SizeMismatch : public logic_error {
public:
  SizeMismatch() : logic_error("Size Mismatch") {}
};

class MustBeZero : public logic_error {
public:
  MustBeZero() : logic_error("Must Be Zero") {}
};

class BadInput : public invalid_argument {
public:
  BadInput() : invalid_argument("Bad Input") {}
};

#endif