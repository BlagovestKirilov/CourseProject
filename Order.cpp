#include "Order.h"
using namespace std;

Order::Order(Distributor d) {
	distributor = d;
}

void Order::addTextbook(Textbook t) {
	textbooks.push_back(t);
}

double Order::getTotalCost() const {
	double total = 0.0;
	for (auto t : textbooks) {
		total += t.getPrice();
	}
	return total;
}

void Order::writeToFile(ofstream& outFile) const {
	outFile << distributor.getName() << endl;
	for (const auto& t : textbooks) {
		outFile << t.getTitle() << endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Order& order) {
	os << "Distributor Information:" << endl;
	os << "Name: " << order.distributor.getName() << endl;
	os << "Address: " << order.distributor.getAddress() << endl;
	os << "Phone Number: " << order.distributor.getPhoneNumber() << endl;
	os << "Order Information:" << endl;
	os << "Total Cost: $" << std::fixed << setprecision(2) << order.getTotalCost() << endl;
	os << "Textbooks:" << endl;
	for (auto t : order.textbooks) {
		os << "Title: " << t.getTitle() << endl;
		os << "Author: " << t.getAuthor() << endl;
		os << "Edition: " << t.getEdition() << endl;
		os << "ISBN: " << t.getIsbn() << endl;
		os << "Release Date: " << t.getReleaseDate() << endl;
		os << "Print Run: " << t.getPrintRun() << endl;
		os << "Approved: " << (t.isApproved() ? "Yes" : "No") << endl;
		os << "Approval Date: " << t.getApprovalDate() << endl;
		os << endl;
	}
	return os;
}

