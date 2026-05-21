#include <iostream>
#include <string>
#include <deque> //ds for muffins
#include <vector> //ds for bracelets
#include <queue> //ds for stickers
#include <ctime>
using namespace std;

const int PERIODS = 10;
const int DATA = 25;

struct Customer { //general struct for customer to be used for all booths
	string name;
	string order;
};

struct Node { //struct for nodes in coffee booth
	Customer c;
	Node* next;
};

struct CoffeeLine { //struct for linked list for coffee booth
	Node* head;
	Node* tail;
	int count;
};

Customer newCustomer(string[], string[]);
void addCustomer(CoffeeLine&, Customer);
void displayCoffeeLine(CoffeeLine&);
void simCoffee(CoffeeLine&);
void serveCustomer(CoffeeLine&, Customer&);


int main()
{
	//Milestone 1
	srand(time(0));

	//data generated using LLM
	string names[DATA] = {
	"Alex", "Jordan", "Taylor", "Morgan", "Casey",
	"Riley", "Jamie", "Avery", "Cameron", "Skyler",
	"Reese", "Dakota", "Quinn", "Parker", "Rowan",
	"Emerson", "Finley", "Hayden", "Kendall", "Logan",
	"Bailey", "Harper", "Payton", "Sawyer", "Tatum"
	};

	string drinks[DATA] = {
	"Latte", "Mocha", "Americano", "ColdBrew", "Espresso",
	"Cappuccino", "Macchiato", "Chai", "DripCoffee", "IcedCoffee",
	"FlatWhite", "Cortado", "NitroColdBrew", "VanillaLatte", "CaramelMacchiato",
	"HazelnutLatte", "WhiteMocha", "MatchaLatte", "DirtyChai", "CafeAuLait",
	"RedEye", "Affogato", "IcedAmericano", "HoneyLatte", "PumpkinLatte"
	};

	//ceate new coffeeline and initialize values to default
	CoffeeLine coffeeLine;
	coffeeLine.head = nullptr;
	coffeeLine.tail = nullptr;
	coffeeLine.count = 0;


	//Milestone 2
	//initialize and add 3 customers to coffeeLine
	for (int i = 0; i < 3; i++) {
		addCustomer(coffeeLine, newCustomer(names, drinks));
	}

	displayCoffeeLine(coffeeLine);





}
//general function to create new customer, can be used for all booths
Customer newCustomer(string names[], string orders[]) {
	Customer newCustomer;

	newCustomer.name = names[rand() % DATA];
	newCustomer.order = orders[rand() % DATA];

	return newCustomer;
}
//adds customers to coffeeLine
void addCustomer(CoffeeLine& coffeeLine, Customer c) {
	Node* node = new Node;

	node->c = c;
	node->next = nullptr;

	if (coffeeLine.head == nullptr) {
		coffeeLine.head = node;
		coffeeLine.tail = node;
	}
	else {
		coffeeLine.tail->next = node;
		coffeeLine.tail = node; 
	}

	coffeeLine.count++;
}
//displays state of coffee line
void displayCoffeeLine(CoffeeLine& coffeeLine) {
	Node* current = coffeeLine.head;
	int pos = 1;

	cout << "Current coffee line: " << endl;
	if (current == nullptr) {
		cout << "Coffee line is empty." << endl;
		return;
	}

	while (current != nullptr) {
		cout << pos << ". " << current->c.name << ": " << current->c.order << endl;
		current = current->next;
		pos++;
	}

}


void simCoffee(CoffeeLine&) {

}

void serveCustomer(CoffeeLine&, Customer&) {

}
