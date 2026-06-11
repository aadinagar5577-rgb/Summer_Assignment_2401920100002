#include <iostream>
using namespace std;

// Interface
class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
};

// KidUser class
class KidUser : public LibraryUser {
public:
    int age;
    string bookType;

    void registerAccount() {
        if (age < 12) {
            cout << "You have successfully registered under a Kids Account" << endl;
        }
        else {
            cout << "Sorry, Age must be less than 12 to register as a kid" << endl;
        }
    }

    void requestBook() {
        if (bookType == "Kids") {
            cout << "Book Issued successfully, please return the book within 10 days" << endl;
        }
        else {
            cout << "Oops, you are allowed to take only kids books" << endl;
        }
    }
};

// AdultUser class
class AdultUser : public LibraryUser {
public:
    int age;
    string bookType;

    void registerAccount() {
        if (age > 12) {
            cout << "You have successfully registered under an Adult Account" << endl;
        }
        else {
            cout << "Sorry, Age must be greater than 12 to register as an adult" << endl;
        }
    }

    void requestBook() {
        if (bookType == "Fiction") {
            cout << "Book Issued successfully, please return the book within 7 days" << endl;
        }
        else {
            cout << "Oops, you are allowed to take only adult Fiction books" << endl;
        }
    }
};

int main() {

    // Test Case #1 : KidUser
    KidUser kid;

    cout << "KidUser Test Case 1:" << endl;
    kid.age = 10;
    kid.registerAccount();

    kid.bookType = "Kids";
    kid.requestBook();

    cout << endl;

    cout << "KidUser Test Case 2:" << endl;
    kid.age = 18;
    kid.registerAccount();

    kid.bookType = "Fiction";
    kid.requestBook();

    cout << endl;

    // Test Case #2 : AdultUser
    AdultUser adult;

    cout << "AdultUser Test Case 1:" << endl;
    adult.age = 5;
    adult.registerAccount();

    adult.bookType = "Kids";
    adult.requestBook();

    cout << endl;

    cout << "AdultUser Test Case 2:" << endl;
    adult.age = 23;
    adult.registerAccount();

    adult.bookType = "Fiction";
    adult.requestBook();

    return 0;
}
