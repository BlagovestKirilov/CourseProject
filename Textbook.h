#pragma once

#include <iostream>
#include <string>
#include "Distributor.h"

class Textbook {
private:
    std::string title;
    std::string author;
    int edition;
    std::string isbn;
    std::string releaseDate;
    int printRun;
    bool approved;
    std::string approvalDate;
    double price;
    Distributor distributor;

public:
    Textbook(std::string title_, std::string author_, int edition_, std::string isbn_,
        std::string releaseDate_, int printRun_, bool approved_, std::string approvalDate_,
        double price_, Distributor distributor_);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getEdition() const;
    std::string getIsbn() const;
    std::string getReleaseDate() const;
    int getPrintRun() const;
    bool isApproved() const;
    std::string getApprovalDate() const;
    double getPrice() const;
    Distributor getDistributor() const;

    // Setters
    void setTitle(const std::string& newTitle);
    void setAuthor(const std::string& newAuthor);
    void setEdition(int newEdition);
    void setIsbn(const std::string& newIsbn);
    void setReleaseDate(const std::string& newReleaseDate);
    void setPrintRun(int newPrintRun);
    void setApproved(bool newApproved);
    void setApprovalDate(const std::string& newApprovalDate);
    void setPrice(double newPrice);
    void setDistributor(const Distributor& newDistributor);

    friend std::ostream& operator<<(std::ostream& os, const Textbook& obj);
    friend std::istream& operator>>(std::istream& is, Textbook& obj);
};

