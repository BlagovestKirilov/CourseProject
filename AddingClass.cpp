#include "AddingClass.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Distributor.h"
#include <vector>
#include "Textbook.h"
#include "Order.h"
using namespace std;

AddingClass::AddingClass() {
}

void AddingClass::addTextbook() {
    string title, author, isbn, releaseDate, approvalDate;
    int edition, printRun;
    double price;
    bool approved;
    vector<Textbook> newTextbooks;

    cout << "Enter the title of the textbook: ";
    cin.ignore();
    getline(cin, title);

    cout << "Enter the author of the textbook: ";
    getline(cin, author);

    cout << "Enter the edition of the textbook: ";
    cin >> edition;

    cout << "Enter the ISBN of the textbook: ";
    cin >> isbn;

    cout << "Enter the release date of the textbook: ";
    cin.ignore();
    getline(cin, releaseDate);

    cout << "Enter the print run of the textbook: ";
    cin >> printRun;

    cout << "Enter the price of the textbook: ";
    cin >> price;

    cout << "Is the textbook approved by the Ministry of Education? (1 for yes, 0 for no): ";
    cin >> approved;

    if (approved) {
        cout << "Enter the approval date of the textbook: ";
        cin.ignore();
        getline(cin, approvalDate);
    }

    vector<Distributor> distributors;
    std::ifstream ifs("distributors.dat");
    Distributor dist;
    while (ifs >> dist) {
        distributors.push_back(dist);
    }

    int distributorIndex;
    while (true) {
        cout << "Select a distributor:" << endl;
        for (int i = 0; i < distributors.size(); i++) {
            cout << i + 1 << ". " << distributors[i].getName()
                << " (" << distributors[i].getAddress() << ", " << distributors[i].getPhoneNumber() << ")" << endl;
        }
        cout << "Enter your choice: ";
        cin >> distributorIndex;

        if (distributorIndex >= 1 && distributorIndex <= distributors.size()) {
            break;
        }
        else {
            cout << "Error: Invalid choice. Please try again." << endl;
        }
    }

    newTextbooks.push_back(Textbook(title, author, edition, isbn, releaseDate, printRun, approved, approvalDate, price, distributors[distributorIndex - 1]));
    cout << "Textbook added successfully." << endl;
    std::ofstream outfile("textbooks.dat", std::ios::app);
    for (const auto& dist1 : newTextbooks) {
        outfile << dist1;
    }
}
   

void AddingClass::addDistributor() {
    string name, address, phoneNumber;
    vector<Distributor> newDistributors;

    cout << "Enter the name of the distributor: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the address of the distributor: ";
    getline(cin, address);

    cout << "Enter the phone number of the distributor: ";
    getline(cin, phoneNumber);

    newDistributors.push_back(Distributor(name, address, phoneNumber));
    cout << "Distributor added successfully." << endl;
    std::ofstream ofs("distributors.dat", std::ios::app); 
    for (const auto& dist : newDistributors) {
        ofs << dist;
    }
}

void AddingClass::addOrder() {
    vector<Distributor> distributors;
    vector<Textbook> textbooks;
    vector<Order> orders;
    std::ifstream ifs("distributors.dat");
    Distributor dist;
    while (ifs >> dist) {
        distributors.push_back(dist);
    }

    std::ifstream infile("textbooks.dat");
    if (infile.is_open()) {
        Textbook textbook("", "", 0, "", "", 0, false, "", 0.0, Distributor("", "", ""));
        while (infile >> textbook) {
            textbooks.push_back(textbook);
        }
        infile.close();
    }

    if (distributors.empty()) {
        cout << "Error: No distributors available. Please add a distributor first." << endl;
    }

    int distributorIndex;
    while (true) {
        cout << "Select a distributor:" << endl;
        for (int i = 0; i < distributors.size(); i++) {
            cout << i + 1 << ". " << distributors[i].getName()
                << " (" << distributors[i].getAddress() << ", " << distributors[i].getPhoneNumber() << ")" << endl;
        }
        cout << "Enter your choice: ";
        cin >> distributorIndex;

        if (distributorIndex >= 1 && distributorIndex <= distributors.size()) {
            break;
        }
        else {
            cout << "Error: Invalid choice. Please try again." << endl;
        }
    }
    Distributor currDistributor = distributors[distributorIndex - 1];
    Order order(currDistributor);

    int textbookIndex;
    int textbookCount;
    while (true) {
        cout << "Select a textbook to add to the order:" << endl;
        for (int i = 0; i < textbooks.size(); i++) {

            if (textbooks[i].getDistributor().getName().compare(currDistributor.getName()) == 0) {
                cout << i + 1 << ". " << textbooks[i].getTitle() << " by " << textbooks[i].getAuthor() << endl;
            }
        }
        cout << "Enter your choice (0 to exit): ";
        cin >> textbookIndex;

        if (textbookIndex == 0) {
            break;
        }
        else if (textbookIndex >= 1 && textbookIndex <= textbooks.size()) {
            cout << "How many textbooks of this you want: " ;
            cin >> textbookCount;
            if (textbooks[textbookIndex - 1].isApproved()) {
                for (int i = 0; i < textbookCount; i++) {
                    order.addTextbook(textbooks[textbookIndex - 1]);
                }
                cout << "Textbook added to the order successfully." << endl;
            }
            else {
                cout << "Error: The selected textbook has not been approved by the Ministry of Education." << endl;
            }
        }
        else {
            cout << "Error: Invalid choice. Please try again." << endl;
        }
    }

    orders.push_back(order);
    cout << "Total Cost: " << std::fixed << setprecision(2) << order.getTotalCost() << " lv." << endl;
    cout << "Order created successfully." << endl;
    std::ofstream ofs("orders.dat", std::ios::app); 
    for (const auto& dist : orders) {
        ofs << dist;
    }
}
     