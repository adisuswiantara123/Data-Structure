#include "bookstack.h"
#include <iostream>

using namespace std;


Book::Book(const string &title, const string &author, int pageCount)
    : title(title), author(author), pageCount(pageCount) {}

string Book::GetTitle() const { return title; }
string Book::GetAuthor() const { return author; }
int Book::GetPageCount() const { return pageCount; }

int main() {
  BookStack<Book> bookStack(3);

  try {
    Book book1("Introduction to C++", "John Doe", 300);
    Book book2("Data Structures", "Jane Smith", 400);
    Book book3("Algorithm Design", "Bob Johnson", 350);

    bookStack.Add(book1).Add(book2).Add(book3);
  } catch (const NoMem &) {
    cout << "Could not complete additions" << endl;
  }

  cout << "Book stack should have 3 books" << endl;

  try {
    Book topBook = bookStack.Top();
    cout << "Top book: " << topBook.GetTitle() << " by " << topBook.GetAuthor()
         << endl;

    Book removedBook;
    bookStack.Remove(removedBook);
    cout << "Removed book: " << removedBook.GetTitle() << " by "
         << removedBook.GetAuthor() << endl;

    bookStack.Remove(removedBook);
    cout << "Removed book: " << removedBook.GetTitle() << " by "
         << removedBook.GetAuthor() << endl;

    bookStack.Remove(removedBook);
    cout << "Removed book: " << removedBook.GetTitle() << " by "
         << removedBook.GetAuthor() << endl;
  } catch (const OutOfBounds &) {
    cout << "Last delete failed " << endl;
  }

  return 0;
}
