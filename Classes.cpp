#include "Classes.h"
Book::Book() : code(0), title(""), available(0), rented(0) {}
Book::Book(int code, std::string title, int available, int rented) {
    this->code = code;
    this->title = title;
    this->available = available;
    this->rented = rented;
}
void Book::setCode(int code) { this->code = code; }
void Book::setTitle(std::string title) { this->title = title; }
void Book::setAvailable(int available) { this->available = available; }
void Book::setRented(int rented) { this->rented = rented; }
void Book::setAge(int age) {}
void Book::setPublisher(std::string publisher) {}
void Book::setPublish_date(int publish_date) {}
int Book::getCode() { return code; }
std::string Book::getTitle() { return title; }
int Book::getAvailable() { return available; }
int Book::getRented() { return rented; }
int Book::getAge() {  return 0; }
std::string Book::getPublisher() { return ""; }
int Book::getPublish_date() { return 0; }
void Book::printBook(){}
ChildrenBook::ChildrenBook() : age(0), Book(0, "", 0, 0) {}
ChildrenBook::ChildrenBook(int age, int code, std::string title, int available, int rented) : Book(code, title, available, rented) {
    this->age = age;
}
void ChildrenBook::setTitle(std::string title) { Book::setTitle(title); }
void ChildrenBook::setAvailable(int available) { Book::setAvailable(available); }
void ChildrenBook::setRented(int rented) { Book::setRented(rented); }
void ChildrenBook::setAge(int age) { this->age = age; }
void ChildrenBook::setCode(int code) { Book::setCode(code); }
void ChildrenBook::setPublisher(std::string publisher) { Book::setPublisher(publisher); }
void ChildrenBook::setPublish_date(int publish_date) { Book::setPublish_date(publish_date); }
int ChildrenBook::getCode() { return Book::getCode(); }
std::string ChildrenBook::getTitle() { return Book::getTitle(); }
int ChildrenBook::getAvailable() { return Book::getAvailable(); }
int ChildrenBook::getRented() { return Book::getRented(); }
int ChildrenBook::getAge() { return age; }
std::string ChildrenBook::getPublisher() { return Book::getPublisher(); }
int ChildrenBook::getPublish_date() { return Book::getPublish_date(); }
void ChildrenBook::printBook(){ std::cout << Book::getCode() << std::setw(30) << Book::getTitle() << std::setw(20) << age << std::setw(10) << Book::getAvailable() << std::setw(10) << Book::getRented() << std::endl; }
ComputerBook::ComputerBook() : publisher(""), Book(0, "", 0, 0) {}
ComputerBook::ComputerBook(std::string publisher, int code, std::string title, int available, int rented) : Book(code, title, available, rented) {
    this->publisher = publisher;
}
void ComputerBook::setCode(int code) { Book::setCode(code); }
void ComputerBook::setTitle(std::string title) { Book::setTitle(title); }
void ComputerBook::setAvailable(int available) { Book::setAvailable(available); }
void ComputerBook::setRented(int rented) { Book::setRented(rented); }
void ComputerBook::setAge(int age) { Book::setAge(age); }
void ComputerBook::setPublisher(std::string publisher) { this->publisher = publisher; }
void ComputerBook::setPublish_date(int publish_date) { Book::setPublish_date(publish_date); }
int ComputerBook::getCode() { return Book::getCode(); }
std::string ComputerBook::getTitle() { return Book::getTitle(); }
int ComputerBook::getAvailable() { return Book::getAvailable(); }
int ComputerBook::getRented() { return Book::getRented(); }
int ComputerBook::getAge() { return Book::getAge(); }
std::string ComputerBook::getPublisher() { return publisher; }
int ComputerBook::getPublish_date() { return Book::getPublish_date(); }
void ComputerBook::printBook(){ std::cout << Book::getCode() << std::setw(30) << Book::getTitle() << std::setw(20) << publisher << std::setw(10) << Book::getAvailable() << std::setw(10) << Book::getRented() << std::endl; }
Novel::Novel() : publish_date(0), Book(0, "", 0, 0) {}
Novel::Novel(int publish_date, int code, std::string title, int available, int rented) : Book(code, title, available, rented) {
    this->publish_date = publish_date;
}
void Novel::setCode(int code) { Book::setCode(code); }
void Novel::setTitle(std::string title) { Book::setTitle(title); }
void Novel::setAvailable(int available) { Book::setAvailable(available); }
void Novel::setRented(int rented) { Book::setRented(rented); }
void Novel::setAge(int age){ Book::setAge(age); }
void Novel::setPublish_date(int publish_date) { this->publish_date = publish_date; }
void Novel::setPublisher(std::string publisher) { Book::setPublisher(publisher); }
int Novel::getCode() { return Book::getCode(); }
std::string Novel::getTitle() { return Book::getTitle(); }
int Novel::getAvailable() { return Book::getAvailable(); }
int Novel::getRented() { return Book::getRented(); }
int Novel::getAge() { return Book::getAge(); }
std::string Novel::getPublisher() { return Book::getPublisher(); }
int Novel::getPublish_date() { return publish_date; }
void Novel::printBook(){ std::cout << Book::getCode() << std::setw(30) << Book::getTitle() << std::setw(20) << publish_date << std::setw(10) << Book::getAvailable() << std::setw(10) << Book::getRented() << std::endl; }
Person::Person() : id(0), name(""), count(0) {}
Person::Person(int id, std::string name, int count) {
    this->id = id;
    this->name = name;
    this->count = count;
}
void Person::setId(int id) { this->id = id;}
void Person::setName(std::string name) { this->name = name; }
void Person::setCount(int count) { this->count = count; }
void Person::setCode(int code[]) {}
int Person::getId() { return id;}
std::string Person::getName() { return name; }
int Person::getCount() { return count; }
int* Person::getCode() { return 0; }
Student::Student() : code(), Person(0, "", 0) {}
Student::Student(int code[2], int id, std::string name, int count) : Person(id, name, count) {
    for(int i = 0; i < 2; i++) this->code[i] = code[i];
}
void Student::setId(int id) { Person::setId(id); }
void Student::setName(std::string name) { Person::setName(name); }
void Student::setCount(int count) { Person::setCount(count); }
void Student::setCode(int code[2]) { for(int i = 0; i < 2; i++) this->code[i] = code[i]; }
int Student::getId() { return Person::getId();}
std::string Student::getName() { return Person::getName(); }
int Student::getCount() { return Person::getCount(); }
int* Student::getCode() { return code; }
Teacher::Teacher() : code(), Person(0, "", 0) {}
Teacher::Teacher(int code[3], int id, std::string name, int count) : Person(id, name, count) {
    for(int i = 0; i < 3; i++) this->code[i] = code[i];
}
void Teacher::setId(int id) { Person::setId(id); }
void Teacher::setName(std::string name) { Person::setName(name); }
void Teacher::setCount(int count) { Person::setCount(count); }
void Teacher::setCode(int code[3]) { for(int i = 0; i < 3; i++) this->code[i] = code[i]; }
int Teacher::getId() { return Person::getId();}
std::string Teacher::getName() { return Person::getName(); }
int Teacher::getCount() { return Person::getCount(); }
int* Teacher::getCode() { return code; }
