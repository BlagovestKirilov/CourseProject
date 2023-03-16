#include "Textbook.h"

Textbook::Textbook(std::string title_, std::string author_, int edition_, std::string isbn_,
    std::string releaseDate_, int printRun_, bool approved_, std::string approvalDate_,
    double price_, Distributor distributor_) :
    title(title_), author(author_), edition(edition_), isbn(isbn_), releaseDate(releaseDate_),
    printRun(printRun_), approved(approved_), approvalDate(approvalDate_), price(price_),
    distributor(distributor_) {}

// Getters
std::string Textbook::getTitle() const {
    return title;
}

std::string Textbook::getAuthor() const {
    return author;
}

int Textbook::getEdition() const {
    return edition;
}

std::string Textbook::getIsbn() const {
    return isbn;
}

std::string Textbook::getReleaseDate() const {
    return releaseDate;
}

int Textbook::getPrintRun() const {
    return printRun;
}

bool Textbook::isApproved() const {
    return approved;
}

std::string Textbook::getApprovalDate() const {
    return approvalDate;
}

double Textbook::getPrice() const {
    return price;
}

Distributor Textbook::getDistributor() const {
    return distributor;
}

// Setters
void Textbook::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Textbook::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void Textbook::setEdition(int newEdition) {
    edition = newEdition;
}

void Textbook::setIsbn(const std::string& newIsbn) {
    isbn = newIsbn;
}

void Textbook::setReleaseDate(const std::string& newReleaseDate) {
    releaseDate = newReleaseDate;
}

void Textbook::setPrintRun(int newPrintRun) {
    printRun = newPrintRun;
}

void Textbook::setApproved(bool newApproved) {
    approved = newApproved;
}

void Textbook::setApprovalDate(const std::string& newApprovalDate) {
    approvalDate = newApprovalDate;
}

void Textbook::setPrice(double newPrice) {
    price = newPrice;
}

void Textbook::setDistributor(const Distributor& newDistributor) {
    distributor = newDistributor;
}

std::ostream& operator<<(std::ostream& os, const Textbook& obj) {
    os << obj.getTitle() << '\n' << obj.getAuthor() << '\n' << obj.getEdition() << '\n' << obj.getIsbn() << '\n'
        << obj.getReleaseDate() << '\n' << obj.getPrintRun() << '\n' << obj.isApproved() << '\n'
        << obj.getApprovalDate() << '\n' << obj.getPrice() << '\n' << obj.getDistributor();
    return os;
}

std::istream& operator>>(std::istream& is, Textbook& obj) {
    std::string title, author, isbn, releaseDate, approvalDate;
    int edition, printRun;
    bool approved;
    double price;
    Distributor distributor("", "", "");
    std::getline(is, title);
    std::getline(is, author);
    is >> edition;
    is.ignore();
    std::getline(is, isbn);
    std::getline(is, releaseDate);
    is >> printRun;
    is.ignore();
    is >> approved;
    is.ignore();
    std::getline(is, approvalDate);
    is >> price;
    is.ignore();
    is >> distributor;
    obj.setTitle(title);
    obj.setAuthor(author);
    obj.setEdition(edition);
    obj.setIsbn(isbn);
    obj.setReleaseDate(releaseDate);
    obj.setPrintRun(printRun);
    obj.setApproved(approved);
    obj.setApprovalDate(approvalDate);
    obj.setPrice(price);
    obj.setDistributor(distributor);
    return is;
}
