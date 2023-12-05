#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
class Book {
public:
    Book();
    Book(int code, std::string title, int available, int rented);
    virtual void setCode(int code) = 0;
    virtual void setTitle(std::string title) = 0;
    virtual void setAvailable(int available) = 0;
    virtual void setRented(int rented) = 0;
    virtual void setAge(int age) = 0;
    virtual void setPublisher(std::string publisher) = 0;
    virtual void setPublish_date(int publish_date) = 0;
    virtual int getCode() = 0;
    virtual std::string getTitle() = 0;
    virtual int getAvailable() = 0;
    virtual int getRented() = 0;
    virtual int getAge() = 0;
    virtual std::string getPublisher() = 0;
    virtual int getPublish_date() = 0;
    virtual void printBook() = 0;
private:
    int code; // unique book code
    std::string title; // book title
    int available; // number of books available to rent
    int rented; // number of books rented
};
class ChildrenBook : public Book {
public:
    ChildrenBook();
    ChildrenBook(int age, int code, std::string title, int available, int rented);
    void setCode(int code);
    void setTitle(std::string title);
    void setAvailable(int available);
    void setRented(int rented);
    void setAge(int age);
    void setPublisher(std::string publisher);
    void setPublish_date(int publish_date);
    int getCode();
    std::string getTitle();
    int getAvailable();
    int getRented();
    int getAge();
    std::string getPublisher();
    int getPublish_date();
    void printBook();
private:
    int age; // age to read the children book
};
class ComputerBook : public Book {
public:
    ComputerBook();
    ComputerBook(std::string publisher, int code, std::string title, int available, int rented);
    void setCode(int code);
    void setTitle(std::string title);
    void setAvailable(int available);
    void setRented(int rented);
    void setAge(int age);
    void setPublisher(std::string publisher);
    void setPublish_date(int publish_date);
    int getCode();
    std::string getTitle();
    int getAvailable();
    int getRented();
    int getAge();
    std::string getPublisher();
    int getPublish_date();
    void printBook();
private:
    std::string publisher; // publisher of the computer book
};
class Novel : public Book {
public:
    Novel();
    Novel(int publish_date, int code, std::string title, int available, int rented);
    void setCode(int code);
    void setTitle(std::string title);
    void setAvailable(int available);
    void setRented(int rented);
    void setAge(int age);
    void setPublisher(std::string publisher);
    void setPublish_date(int publish_date);
    int getCode();
    std::string getTitle();
    int getAvailable();
    int getRented();
    int getAge();
    int getPublish_date();
    std::string getPublisher();
    void printBook();
private:
    int publish_date; // publish date of the novel
};
class Person {
public:
    Person();
    Person(int id, std::string name, int count);
    virtual void setId(int id) = 0;
    virtual void setName(std::string name) = 0;
    virtual void setCount(int count) = 0;
    virtual void setCode(int code[]) = 0;
    virtual int getId() = 0;
    virtual std::string getName() = 0;
    virtual int getCount() = 0;
    virtual int* getCode() = 0;
private:
    int id; // unique person id
    std::string name; // person name
    int count; // number of books the person rented
};
class Student : public Person {
public:
    Student();
    Student(int code[2], int id, std::string name, int count);
    void setId(int id);
    void setName(std::string name);
    void setCount(int count);
    void setCode(int code[2]);
    int getId();
    std::string getName();
    int getCount();
    int* getCode();
private:
    int code[2]; // codes of books the student rented, maximum of 2
};
class Teacher: public Person {
public:
    Teacher();
    Teacher(int code[3], int id, std::string name, int count);
    void setId(int id);
    void setName(std::string name);
    void setCount(int count);
    void setCode(int code[3]);
    int getId();
    std::string getName();
    int getCount();
    int* getCode();
private:
    int code[3]; // codes of books the teacher rented, maximum of 3
};
