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
//overloaded functions
void addCustomer(CoffeeLine&, Customer); //coffee
void addCustomer(deque<Customer>&, Customer); //muffins
void addCustomer(vector<Customer>&, Customer); //bracelets
void addCustomer(queue<Customer>&, Customer);//stickers

void displayCoffeeLine(CoffeeLine&);
void displayMuffinLine(deque<Customer>&);
void displayBraceletLine(vector<Customer>&);//bracelets
void displayStickerLine(queue<Customer>&);//stickers


bool serveCustomer(CoffeeLine&, Customer&);
bool serveCustomer(deque<Customer>&, Customer&);
bool serveCustomer(vector<Customer>&, Customer&);//bracelets
bool serveCustomer(queue<Customer>&, Customer&);//stickers

void simMarket(CoffeeLine&, deque<Customer>&, vector<Customer>&, queue<Customer>&,
	string[], string[], string[], string[], string[]);


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

	string muffins[DATA] = {
	"Blueberry", "ChocolateChip", "BananaNut", "Pumpkin", "Lemon",
	"AppleCinnamon", "DoubleChocolate", "Corn", "Cranberry", "Plain",
	"Raspberry", "PoppySeed", "Bran", "Strawberry", "CinnamonSugar",
	"Carrot", "Zucchini", "Peach", "MaplePecan", "OrangeCranberry",
	"CoffeeCake", "Smore", "BirthdayCake", "HoneyOat", "Almond"
	};

	string bracelets[DATA]{
	"Rainbow", "Blue", "Pink", "Green", "Purple",
	"Gold", "Silver", "Heart", "Star", "Flower",
	"Sunset", "Ocean", "Cloud", "Beaded", "Friendship",
	"Butterfly", "Moon", "Crystal", "Neon", "Pastel",
	"Charm", "Initials", "Smile", "Peace", "Galaxy"
	};

	string stickers[DATA]{

	};
	
	//ceate new coffeeLine and initialize values to default
	CoffeeLine coffeeLine;
	coffeeLine.head = nullptr;
	coffeeLine.tail = nullptr;
	coffeeLine.count = 0;

	//create deque for muffinLine
	deque<Customer> muffinLine;

	//create vector for braceletLine
	vector<Customer> braceletLine;

	//create queue for braceletLine
	queue<Customer> stickerLine;

	//Milestone 2
	//initialize and add 3 customers to coffeeLine
	for (int i = 0; i < 3; i++) {
		addCustomer(coffeeLine, newCustomer(names, drinks));
	}

	//Milestone 3
	//initialize and add 3 customers to muffinLine
	for (int i = 0; i < 3; i++) {
		addCustomer(muffinLine, newCustomer(names, muffins));
	}

	//Milestone 4
	for (int i = 0; i < 3; i++) {
		addCustomer(braceletLine, newCustomer(names, bracelets));
	}

	simMarket(coffeeLine, muffinLine, braceletLine, stickerLine, names, drinks, muffins, bracelets, stickers);





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
//adds customers to muffinLine
void addCustomer(deque<Customer>& muffinLine, Customer c) {
	muffinLine.push_back(c);
}

//adds customers to braceletLine
void addCustomer(vector<Customer>& braceletLine, Customer c) {
	braceletLine.push_back(c);
}
//adds customers to muffinLine
void addCustomer(deque<Customer>& muffinLine, Customer c) {
	muffinLine.push_back(c);
}

//adds customers to braceletLine
void addCustomer(vector<Customer>& braceletLine, Customer c) {
	braceletLine.push_back(c);
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
//displays state of muffin line
void displayMuffinLine(deque<Customer>& muffinLine) {
	int pos = 1;
	cout << "Current muffin line: " << endl;
	if (muffinLine.empty()) {
		cout << "Muffin line is empty." << endl;
		return;
	}

	for (const auto& customer : muffinLine) {
		cout << pos << ". " << customer.name << ": " << customer.order << endl;
		pos++;
	}
}

//displays state of braceletLine
void displayBraceletLine(vector<Customer>& braceletLine) {
	int pos = 1;
	cout << "Current bracelet line: " << endl;
	if (braceletLine.empty()) {
		cout << "Bracelet line is empty." << endl;
		return;
	}

	for (const auto& customer : braceletLine) {
		cout << pos << ". " << customer.name << ": " << customer.order << endl;
		pos++;
	}
}

//displays state of braceletLine
void displayStickerLine(vector<Customer>& stickerLine) {
	int pos = 1;
	cout << "Current Sticker line: " << endl;
	if (stickerLine.empty()) {
		cout << "Sticker line is empty." << endl;
		return;
	}

	while (!stickerLine.empty()) {
		Customer c = stickerLine.front();
		cout << pos << ". " << c.name << << ": " << c.order << endl;
		stick
}


//serves first customer in coffee line 
bool serveCustomer(CoffeeLine& coffeeLine, Customer& servedCustomer) {
	if (coffeeLine.head == nullptr) {
		return false;
	}
	Node* temp = coffeeLine.head;
	servedCustomer = temp->c;
	coffeeLine.head = coffeeLine.head->next;

	if (coffeeLine.head == nullptr) {
		coffeeLine.tail = nullptr;
	}
	delete temp;
	coffeeLine.count--;

	return true;
}

//serves first customer in muffin line
bool serveCustomer(deque<Customer>& muffinLine, Customer& servedCustomer) {
	if (muffinLine.empty()) {
		return false;
	}

	servedCustomer = muffinLine.front();
	muffinLine.pop_front();

	return true;

}

//serves first customer in bracelet line 
bool serveCustomer(vector<Customer>& braceletLine, Customer& servedCustomer) {
	if (braceletLine.empty()) {
		return false;
	}

	servedCustomer = braceletLine.front();
	braceletLine.erase(braceletLine.begin());

	return true;
}

//serves first customer in sticker line 
bool serveCustomer(vector<Customer>& stickerLine, Customer& servedCustomer) {
	if (stickerLine.empty()) {
		return false;
	}

	servedCustomer = stickerLine.front();
	stickerLine.pop_back();

	return true;
}

void simMarket(CoffeeLine& coffeeLine,deque<Customer>& muffinLine, vector<Customer>& braceletLine, queue<Customer>& stickerLine,
	string names[], string drinks[], string muffins[], string bracelets[], string stickers[]) {
	cout << "Market Opens" << endl;
	displayCoffeeLine(coffeeLine);
	cout << endl;
	displayMuffinLine(muffinLine);
	cout << endl;
	displayBraceletLine(braceletLine);
	cout << endl;


	//copied loop structure and formatting from my SDLC assignment
	for (int i = 1; i <= PERIODS; i++) {
		cout << endl << "------------------------" << endl;
		cout << "Time Period: " << i << endl;
		cout << "------------------------" << endl;
		
		Customer servedCustomer;

		//Coffee Booth processes
		cout << "Coffee Booth: " << endl;
		if (serveCustomer(coffeeLine, servedCustomer)) {
			cout << "Served: " << servedCustomer.name << ": " << servedCustomer.order << endl;
		}
		else {
			cout << "Coffee line is empty" << endl;
		}

		if (rand() % 2 == 0) {
			Customer c = newCustomer(names, drinks);
			addCustomer(coffeeLine, c);

			cout << "Joined: " << c.name << ": " << c.order << endl;
		}
		else {
			cout << "No new customers here" << endl;

		}

		cout << "Customers waiting for coffee: " << coffeeLine.count << endl;
		displayCoffeeLine(coffeeLine);
		cout << endl;
		//Muffin Booth processes
		cout << "Muffin Booth: " << endl;
		
		if (serveCustomer(muffinLine, servedCustomer)) {
			cout << "Served: " << servedCustomer.name << ": " << servedCustomer.order << endl;
		}
		else {
			cout << "Muffin line is empty" << endl;
		}


		if (rand() % 2 == 0) {
			Customer c = newCustomer(names, muffins);
			addCustomer(muffinLine, c);

			cout << "Joined: " << c.name << ": " << c.order << endl;
		}
		else {
			cout << "No new customers here" << endl;

		}

		cout << "Customers waiting for muffins: " << muffinLine.size() << endl;
		displayMuffinLine(muffinLine);
		cout << endl;

		//Bracelet Booth processes
		cout << "Bracelet Booth: " << endl;

		if (serveCustomer(braceletLine, servedCustomer)) {
			cout << "Served: " << servedCustomer.name << ": " << servedCustomer.order << endl;
		}
		else {
			cout << "Bracelet line is empty" << endl;
		}


		if (rand() % 2 == 0) {
			Customer c = newCustomer(names, bracelets);
			addCustomer(braceletLine, c);

			cout << "Joined: " << c.name << ": " << c.order << endl;
		}
		else {
			cout << "No new customers here" << endl;

		}

		cout << "Customers waiting for bracelets: " << braceletLine.size() << endl;
		displayBraceletLine(braceletLine);
		cout << endl;

	}


}


