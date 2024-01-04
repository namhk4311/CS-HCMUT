#include <iostream>
#include <cstring>
using namespace std;

class Book {
    char* name;
public:
    Book(const char*);
    ~Book();
    
    void display();
    char* getName();
};

Book::Book(const char* name){
    this->name = new char[strlen(name) + 1];
    for(int i = 0; i < strlen(name); i++){
        this->name[i] = name[i];
    }
    this->name[strlen(name)] = '\0';
}

Book::~Book(){
    // for(int i = 0; i < strlen(this->name); i++){
    //     delete [] this->name[i];
    // }
    delete [] name;
}

void Book::display() {
    cout << "Book: " << this->name << endl;
}

char* Book::getName() {
    return this->name;
}