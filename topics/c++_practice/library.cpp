#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Book {
public:
    string title;
    string author;
    string category;
    int stock;
    int publication_year;
    bool available;

    Book(string t = "", string a = "", string c = "", int s = 1, int y = 0)
        : title(t), author(a), category(c), stock(s), publication_year(y) {
        available = (stock > 0);
    }

    void showAllDetails() {
        updateAvailability();
        cout << "Title: " << title
             << "\nAuthor: " << author
             << "\nCategory: " << category
             << "\nPublication Year: " << publication_year
             << "\nStock: " << stock
             << "\nAvailable: " << (available ? "Yes" : "No") << "\n" << endl;
    }

    void updateAvailability() {
        available = (stock > 0);
    }
};

class Library {
public:
    vector<Book>* books;
    unordered_map<string, int> lent_books_map;

    Library(vector<Book>* _books) : books(_books) {}

    void addBook(const Book& newBook) {
        for (auto& book : *books) {
            if (book.title == newBook.title) {
                cout << "Book already exists in library.\n";
                return;
            }
        }
        books->push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void showInventory() {
        for (auto& book : *books) {
            book.showAllDetails();
        }
    }

    Book* findBook(const string& searchTitle) {
        for (auto& book : *books) {
            if (book.title == searchTitle)
                return &book;
        }
        return nullptr;
    }

    void lendBook(const string& title) {
        Book* book = findBook(title);
        if (!book) {
            cout << "Book not found.\n";
            return;
        }
        book->updateAvailability();
        if (!book->available) {
            cout << "Book is already lent out.\n";
            return;
        }

        string userName;
        cout << "Enter your name to lend the book: ";
        cin.ignore();
        getline(cin, userName);

        if (lent_books_map.find(userName) != lent_books_map.end()) {
            cout << "You already have a book lent. Return it first.\n";
            return;
        }

        book->stock--;
        book->updateAvailability();
        lent_books_map[userName] = book - &(*books)[0];
        cout << "Book lent successfully!\n";
    }

    void returnBook(const string& title) {
        Book* book = findBook(title);
        if (!book) {
            cout << "Book not found.\n";
            return;
        }

        book->stock++;
        book->updateAvailability();
        for (auto it = lent_books_map.begin(); it != lent_books_map.end(); ++it) {
            if ((*books)[it->second].title == title) {
                lent_books_map.erase(it);
                break;
            }
        }

        cout << "Book returned successfully!\n";
    }
};

int main() {
    vector<Book> books;
    Library library(&books);

    library.addBook(Book("Crime & Punishment", "Fyodor Dostoyevsky", "Russian Literature", 5, 1866));
    library.addBook(Book("The Hobbit", "J.R.R. Tolkien", "Fantasy", 3, 1937));

    int choice = -1;
    while (choice != 5) {
        cout << "\n--- DIGITAL LIBRARY ---\n";
        cout << "1. Add Book\n";
        cout << "2. Show Inventory\n";
        cout << "3. Lend Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        cin.ignore();
        switch (choice) {
            case 1: {
                string title, author, category;
                int stock, year;
                cout << "Enter book title: "; getline(cin, title);
                cout << "Enter author: "; getline(cin, author);
                cout << "Enter category: "; getline(cin, category);
                cout << "Enter stock: "; cin >> stock;
                cout << "Enter publication year: "; cin >> year;
                library.addBook(Book(title, author, category, stock, year));
                break;
            }
            case 2:
                library.showInventory();
                break;
            case 3: {
                string title;
                cout << "Enter book title to lend: ";
                getline(cin, title);
                library.lendBook(title);
                break;
            }
            case 4: {
                string title;
                cout << "Enter book title to return: ";
                getline(cin, title);
                library.returnBook(title);
                break;
            }
            case 5:
                cout << "Exiting. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
