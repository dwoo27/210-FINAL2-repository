#include <iostream>
#include <string>
#include <deque> //ds for muffins
#include <vector> //ds for bracelets
#include <queue> //ds for stickers
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
void addCustomer(CoffeeLine, Customer);

int main()
{
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






}
//general function to create new customer, can be used for all booths
Customer newCustomer(string names[], string orders[]) {
	Customer newCustomer;

	newCustomer.name = names[rand() % DATA];
	newCustomer.order = orders[rand() % DATA];

	return newCustomer;
}
//adds customers to coffeeLine
void addCustomer(CoffeeLine coffeeLine, Customer c) {
	Node* node = new Node;

	node->c = c;
	node->next = nullptr;

	if (coffeeLine.head == nullptr) {
		coffeeLine.head = node;
		coffeeLine.tail = node;
	}
	else {
		coffeeLine.tail = node;
	}

	coffeeLine.count++;
}

