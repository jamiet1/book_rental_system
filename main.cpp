#include "Classes.h"
void importFile(std::string*);
void intValidation(int&);
std::vector<Book*> createBookStructure(std::string, std::vector<int>*);
std::vector<Person*> createPersonStructure(std::string);
void searchBook(std::vector<Book*>);
void rentBook(std::vector<Book*>&, std::vector<Person*>&);
void returnBook(std::vector<Book*>&, std::vector<Person*>&);
void showInfo(std::vector<Book*>, std::vector<Person*>);
void showAllBooks(std::vector<Book*>, std::vector<int>);
void chooseMenu(std::vector<Book*>&, std::vector<Person*>&, std::vector<int>);
int main() {
    std::string filename;
    std::cout << "Enter filename for books: ";
    importFile(&filename);
    std::vector<int> bookIndex;
    std::vector<Book*> book = createBookStructure(filename, &bookIndex);
    std::cout << "Enter filename for persons: ";
    importFile(&filename);
    std::vector<Person*> person = createPersonStructure(filename);
    chooseMenu(book, person, bookIndex);
    return 0;
}
/**
 * input validation for integers
 * passes an integer
 * @param
 */
void intValidation(int& x){
    std::cin >> x;
    while(!std::cin){
        std::cout << "Enter a valid integer: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> x;
    }
}
/**
 * import a valid file
 * passes a pointer of a string
 * @param
 */
void importFile(std::string* file){
    std::cin >> *file;
    std::ifstream infile;
    infile.open(*file);
    while(infile.fail()){ // file input validation
        std::cout << "File does not exist. Enter again: ";
        std::cin >> *file;
        infile.open(*file);
    }
    infile.close();
}
/**
 * adds read values from file to a vector of type Book*, creates an int vector with book indexes corresponding to codes in sorted order
 * passes a string, a pointer to an integer vector
 * returns a vector of type Book*, a sorted vector of type int
 * @param
 * @return
 */
std::vector<Book*> createBookStructure(std::string file, std::vector<int>* bIndex){
    std::ifstream infile1;
    infile1.open(file);
    int code, available, rented, age, publish_date;
    std::string title, publisher, next;
    std::vector<Book*> books;
    std::vector<int> codes;
    while(!infile1.eof()){ // adds Book* objects to the vector books
        infile1 >> code >> title >> next >> available >> rented;
        if(code >= 1001 && code <= 2000){ // find the matched child class of Book
            age = stoi(next);
            books.push_back(new ChildrenBook(age, code, title, available, rented));
        }else if (code >= 2001 && code <= 3000){
            publisher = next;
            books.push_back(new ComputerBook(publisher, code, title, available, rented));
        }else if (code >= 3001 && code <= 4000){
            publish_date = stoi(next);
            books.push_back(new Novel(publish_date, code, title, available, rented));
        }
        codes.push_back(code);
    }
    sort(codes.begin(), codes.end()); // sort codes from smallest to largest
    for (int i = 0; i < codes.size(); i++) // adds indexes of each sorted code to the vector bIndex
        for (int j = 0; j < books.size(); j++)
            if(codes[i] == books[j]->getCode())
                bIndex->push_back(j);
    infile1.close();
    return books;
}
/**
 * adds read values from file to a vector of type Person*
 * passes a string
 * returns a vector of type Person*
 * @param
 * @return
 */
std::vector<Person*> createPersonStructure(std::string file){
    std::ifstream infile;
    infile.open(file);
    int id, count, code1, code2, code3;
    int teacherCode[3] = {};
    int studentCode[2] = {};
    std::string name;
    std::vector<Person*> persons;
    while(!infile.eof()){ // adds Person* objects to the vector persons
        infile >> id >> name >> count;
        if (id >= 1 && id <= 100){ // find the matched child class of Person
            if(count == 3){
                infile >> code1 >> code2 >> code3;
                teacherCode[0] = code1;
                teacherCode[1] = code2;
                teacherCode[2] = code3;
            }else if(count == 2){
                infile >> code1 >> code2;
                teacherCode[0] = code1;
                teacherCode[1] = code2;
            }else if(count == 1){
                infile >> code1;
                teacherCode[0] = code1;
            }
            persons.push_back(new Teacher(teacherCode, id, name, count));
        }else if (id >= 101 && id <= 300){
            if(count == 2){
                infile >> code1 >> code2;
                studentCode[0] = code1;
                studentCode[1] = code2;
            }else if(count == 1){
                infile >> code1;
                studentCode[0] = code1;
            }
            persons.push_back(new Student(studentCode, id, name, count));
        }
    }
    infile.close();
    return persons;
}
/**
 * checks if user input code and title are found in one of the Book* class in the vector passed
 * passes a vector of type Book*
 * @param
 */
void searchBook(std::vector<Book*> b){
    int code;
    std::string title;
    int codeFoundAtIndex = -1, titleFoundAtIndex = -1;
    bool match = false;
    try{
        std::cout << "Enter code: ";
        intValidation(code);
        std::vector<Book*>::iterator iter;
        for (std::vector<Book*>::size_type i = 0; i < b.size(); ++i) // find the input code in vector b
            if(b[i]->getCode() == code) codeFoundAtIndex = i;
        if(codeFoundAtIndex == -1) throw code;
        try{
            std::cout << "Enter title: ";
            std::cin >> title;
            for (std::vector<Book*>::size_type i = 0; i < b.size(); ++i) // find the input title in vector b
                if(b[i]->getTitle() == title) titleFoundAtIndex = i;
            if(titleFoundAtIndex == -1) throw title;
            if(titleFoundAtIndex != codeFoundAtIndex) throw match;
            std::cout << title << "(" << code << ") exists" << std::endl;
            std::cout << "publisher: " << b[codeFoundAtIndex]->getPublisher() << std::endl;
            std::cout << b[codeFoundAtIndex]->getAvailable() << " available, " <<b[codeFoundAtIndex]->getRented() << " rented" << std::endl;
        }
        catch(std::string t){ // title input validation
            std::cout << "No match (title does not match)! " << std::endl;
        }
        catch(bool m){ // code and title matched input validation
            std::cout << "No match (code and title do not match)! " << std::endl;
        }
    }
    catch(int c){ // code input validation
        std::cout << "No match (code does not match)! " << std::endl;
    }
}
/**
 * asks the user to rent a book, updates object in vector b and p corresponding to the user input Person id and Book title
 * passes a vector of type Book*, a vector of type Person*
 * @param
 */
void rentBook(std::vector<Book*>& b, std::vector<Person*>& p){
    int id, idFoundAtIndex = -1, titleFoundAtIndex = -1, count, newIndex = 0;
    double throwId;
    char confirm;
    bool unavailable = true;
    std::string title;
    try{
        std::cout << "Enter your id: ";
        intValidation(id);
        throwId = id;
        for (std::vector<Book*>::size_type i = 0; i < p.size(); ++i) // find the input id in vector b
            if(p[i]->getId() == id) idFoundAtIndex = i;
        if(idFoundAtIndex == -1) throw throwId;
        try{
            count = p[idFoundAtIndex]->getCount();
            std::cout << "You are " << p[idFoundAtIndex]->getName() << ". " << "You rented " << count << " book. " << std::endl;
            if(id <= 100 && count == 3) throw(count);
            else if(id > 100 && count == 2) throw(count);
            try{
                std::cout << "Enter book title: ";
                std::cin >> title;
                for (std::vector<Book*>::size_type i = 0; i < b.size(); ++i) // find the input title in vector b
                    if(b[i]->getTitle() == title) titleFoundAtIndex = i;
                if(titleFoundAtIndex == -1) throw title;
                try{
                    if(b[titleFoundAtIndex]->getAvailable() == 0) throw(unavailable);
                    try {
                        std::cout << "Do you want to rent '" << title << "' (y/n)? ";
                        std::cin >> confirm;
                        if (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') throw (confirm);
                        int *newCode = new int[p[idFoundAtIndex]->getCount() + 1];
                        for (int i = 0; i < p[idFoundAtIndex]->getCount(); i++) { // adds the update book codes that the person rented to the array newCode
                            newCode[i] = *(p[idFoundAtIndex]->getCode() + i);
                        }
                        newCode[p[idFoundAtIndex]->getCount()] = b[titleFoundAtIndex]->getCode(); // updates the corresponding vector b and p elements
                        b[titleFoundAtIndex]->setAvailable(b[titleFoundAtIndex]->getAvailable() - 1);
                        b[titleFoundAtIndex]->setRented(b[titleFoundAtIndex]->getRented() + 1);
                        p[idFoundAtIndex]->setCount(p[idFoundAtIndex]->getCount() + 1);
                        p[idFoundAtIndex]->setCode(newCode);
                        std::cout << "***** Rent succeed. Check your info! " << std::endl;
                    }
                    catch(char y){ // character input validation
                        std::cout << "Neither y or n. The choice is not available. " << std::endl;
                    }
                }
                catch(bool n){ // check if the selected book is all rented out
                    std::cout << "The book is not available (all rented out). " << std::endl;
                }
            }
            catch(std::string t){ // title input validation
                std::cout << "No match (title does not match)! " << std::endl;
            }
        }
        catch(int c){ // check if the user is eligible for renting more books
            if(c == 2) std::cout << "You already rented 2 books." << std::endl;
            else std::cout << "You already rented 3 books." << std::endl;
        }
    }
    catch(double i){ // id input validation
        std::cout << "No match (id does not match)! " << std::endl;
    }
}
/**
 * asks the user to return a book, updates object in vector b and p corresponding to the user input Person id and Book title
 * passes a vector of type Book*, a vector of type Person*
 * @param
 */
void returnBook(std::vector<Book*>& b, std::vector<Person*>& p){
    int id, code, idFoundAtIndex = -1, codeFoundAtIndex = -1, newIndex = 0, removeIndex;
    int rentedCode[10] = {};
    double throwCode;
    char confirm;
    try {
        std::cout << "Enter your id: ";
        intValidation(id);
        for (std::vector<Book*>::size_type i = 0; i < p.size(); ++i){
            if(p[i]->getId() == id) idFoundAtIndex = i;
        }
        if(idFoundAtIndex == -1) throw id;
        try {
            std::cout << "Enter book code to return: ";
            std::cin >> code;
            throwCode = code;
            for (int i = 0; i < p[idFoundAtIndex]->getCount(); i++){
                if(code == *(p[idFoundAtIndex]->getCode() + i)){
                    for (std::vector<Book*>::size_type j = 0; j < b.size(); ++j) {
                        if(code == b[j]->getCode()){
                            codeFoundAtIndex = j;
                            continue;
                        }
                    }
                }
            }
            if (codeFoundAtIndex == -1) throw throwCode;
            try{
                std::cout << "Do you want to return '" << b[codeFoundAtIndex]->getTitle() << "' (y/n)? ";
                std::cin >> confirm;
                if(confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') throw(confirm);
                int* newCode = new int[p[idFoundAtIndex]->getCount() - 1];
                for(int i = 0; i < p[idFoundAtIndex]->getCount(); i++){
                    if(*(p[idFoundAtIndex]->getCode() + i) != code) {
                        newCode[newIndex] = *(p[idFoundAtIndex]->getCode() + i);
                        newIndex++;
                    }
                }
                b[codeFoundAtIndex]->setAvailable(b[codeFoundAtIndex]->getAvailable() + 1);
                b[codeFoundAtIndex]->setRented(b[codeFoundAtIndex]->getRented() - 1);
                p[idFoundAtIndex]->setCount(p[idFoundAtIndex]->getCount() - 1);
                p[idFoundAtIndex]->setCode(newCode);
                std::cout << "***** Return succeed. Check your info! "  << std::endl;
            }
            catch(char y){ // character input validation
                std::cout << "Neither y or n. The choice is not available. " << std::endl;
            }
        }
        catch(double t){ // check if the user did not rent the book they want to return
            std::cout << "No match! " << p[idFoundAtIndex]->getName() << " (id#" << id << ") did not rent the book" << std::endl;
        }
    }
    catch(int i){ // id input validation
        std::cout << "No match (id does not match)! " << std::endl;
    }
}
/**
 * outputs number of books rented and all rented book information of a Person* object in p
 * passes a vector of type Book*, a vector of type Person*
 * @param
 */
void showInfo(std::vector<Book*> b, std::vector<Person*> p){
    int id, idFoundAtIndex = -1, code;
    std::string name;
    try {
        std::cout << "Enter your id: ";
        intValidation(id);
        for (std::vector<Book*>::size_type i = 0; i < p.size(); ++i) // find the input id in vector p
            if(p[i]->getId() == id) idFoundAtIndex = i;
        if(idFoundAtIndex == -1) throw id;
        try {
            std::cout << "Enter your name: ";
            std::cin >> name;
            if(p[idFoundAtIndex]->getName() != name) throw name;
            std::cout << "You rented " << p[idFoundAtIndex]->getCount() << " books. " << std::endl;
            for (int i = 0; i < p[idFoundAtIndex]->getCount(); i++) { // outputs each book rented by the person with id inputted
                for (std::vector<Book*>::size_type j = 0; j < b.size(); ++j){
                    code = b[j]->getCode();
                    if (code == *(p[idFoundAtIndex]->getCode() + i)) {
                        if (code >= 1001 && code <= 2000) {
                            std::cout << "* " << b[j]->getTitle() << "(" << b[j]->getCode() << ")" << " - age: " << b[j]->getAge() << std::endl;
                        } else if (code >= 2001 && code <= 3000) {
                            std::cout << "* " << b[j]->getTitle() << "(" << b[j]->getCode() << ")" << " - publisher: " << b[j]->getPublisher() << std::endl;
                        } else if (code >= 3001 && code <= 4000) {
                            std::cout << "* " << b[j]->getTitle() << "(" << b[j]->getCode() << ")" << " - published date: " << b[j]->getPublish_date() << std::endl;
                        }
                    }
                }
            }
        }
        catch(std::string n){ // name input validation
            std::cout << "No match (name does not match)! " << std::endl;
        }
    }
    catch(int i){ // id input validation
        std::cout << "No match (id does not match)! " << std::endl;
    }
}
/**
 * outputs every object in b from the smallest code to the largest
 * passes a vector of type Book*, a sorted vector of type int
 * @param
 */
void showAllBooks(std::vector<Book*> b, std::vector<int> bIndex){
    int code, j = 0;
    int codeType[3] = {1001, 2001, 3001};
    std::string type[3] = {"Children Books", "Computer Books", "Novels"};
    std::string info[3] = {"age", "publisher", "published date"};
    for (int i = 0; i < bIndex.size(); ++i){ // outputs each book* object in vector b
        if(i == 0 || (b[bIndex[i - 1]]->getCode() < (2001 + 1000 * (j - 1)) && b[bIndex[i]]->getCode() >= (2001 + 1000 * (j - 1)))){
            std::cout << "==========================================================================" << std::endl << std::setw(40)<< type[j] << std::endl << "=========================================================================="<< std::endl << "code" << std::setw(30) << type[j] << std::setw(20) << info[j] << std::setw(10)<< "available" << std::setw(10) << "rented" << std::endl<< "---------------------------------------------------------------------------" << std::endl;
            j++;
        }
        b[bIndex[i]]->printBook();
    }
}
/**
 * asks user to choose a choice from the menu
 * passes a vector of type Book*, a vector of type Person*, a sorted vector of type int
 * @param
 */
void chooseMenu(std::vector<Book*>& b, std::vector<Person*>& p, std::vector<int> bIndex){
    int choice = 1;
    while(choice != 6){ // continues till 6 is entered
        std::cout << "---------------------" << std::endl << "         Menu         " << std::endl << "---------------------" << std::endl;
        try{
            std::cout << "1. Search a book" << std::endl << "2. Rent a book" << std::endl << "3. Return a book" << std::endl << "4. Show my information" << std::endl << "5. Show all books" << std::endl << "6. Exit" << std::endl << std::endl << "Select (1~6): ";
            intValidation(choice);
            if(choice < 1 || choice > 6) throw(choice);
            switch(choice){
                case 1:
                    searchBook(b);
                    break;
                case 2:
                    rentBook(b, p);
                    break;
                case 3:
                    returnBook(b, p);
                    break;
                case 4:
                    showInfo(b, p);
                    break;
                case 5:
                    showAllBooks(b, bIndex);
                    break;
                case 6:
                    exit(0);
            }
        }
        catch(int c){ // menu choice input validation
            std::cout << "Choice not available! " << std::endl;
        }
    }
}
