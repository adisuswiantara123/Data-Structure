// file myExceptions.h
#ifndef MY_EXCEPTIONS_H
#define MY_EXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

class IllegalParameterValue {
public:
    IllegalParameterValue(const string& theMessage = "Illegal parameter value")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class IllegalInputData {
public:
    IllegalInputData(const string& theMessage = "Illegal data input")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class IllegalIndex {
public:
    IllegalIndex(const string& theMessage = "Illegal index")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class MatrixIndexOutOfBounds {
public:
    MatrixIndexOutOfBounds(const string& theMessage = "Matrix index out of bounds")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class MatrixSizeMismatch {
public:
    MatrixSizeMismatch(const string& theMessage = "The size of the two matrices doesn't match")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class StackEmpty {
public:
    StackEmpty(const string& theMessage = "Invalid operation on empty stack")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class QueueEmpty {
public:
    QueueEmpty(const string& theMessage = "Invalid operation on empty queue")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class HashTableFull {
public:
    HashTableFull(const string& theMessage = "The hash table is full")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class UndefinedEdgeWeight {
public:
    UndefinedEdgeWeight(const string& theMessage = "No edge weights defined")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

class UndefinedMethod {
public:
    UndefinedMethod(const string& theMessage = "This method is undefined")
        : message(theMessage) {}

    void outputMessage() const {
        cout << message << endl;
    }

private:
    string message;
};

#endif
