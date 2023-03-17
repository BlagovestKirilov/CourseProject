#include "AddingClass.h"

using namespace std;
int main() {
    AddingClass adder;
    int choice = 0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a textbook" << endl;
        cout << "2. Add a distributor" << endl;
        cout << "3. Create an order" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            adder.addTextbook();
        }
        else if (choice == 2) {
            adder.addDistributor();
        }
        else if (choice == 3) {
            adder.addOrder();
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        }
    }
    return 0;
}