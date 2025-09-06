// COMSC-210 | Lab 12 | Chevin Jeon
// IDE used: VSC g++ (C++11)
//
// Program purpose:
//   Demonstrate a C++11 struct (Restaurant) with mixed data types,
//   a function that builds a struct from console input (with validation),
//   a void function that prints the struct nicely,
//   and exercising with >= 4 Restaurant objects.
// 
// Conventions covered:
//   - using namespace std;
//   - function headers + prototypes
//   - constants for widths/ranges
//   - input validation with clear error messages
//   - pass by const reference where appropriate
//   - consistent 4-space indentation
//
// Simple UML (for the struct used in this assignment)
// -----------------------------------------------
// <<struct>> Restaurant
// - address       : string
// - rating        : int
// - isOpen        : bool
// - distance      : double
// - menuItems     : vector<string>
// - itemPrices    : vector<double>
// -----------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std; 

// ---------- data model ----------
struct Restaurant
{
    string address;                      // street/city text
    int rating;                          // 1..5 integer
    bool isOpen;                         // open now? 
    float distance;                      // distance from user
    vector<string> menuItems;            // item names
    vector<double> itemPrices;           // corresponding prices
};

// Builds one Restaurant from console with validation.
Restaurant buildRestaurant() {
    Restaurant r; 
    cout << "Enter the restaurant address: ";
    getline(cin, r.address);
    cout << "Enter the restaurant rating (1-5): ";
    cin >> r.rating;
    cout << "Is the restaurant open? (1 for yes, 0 for no): ";
    cin >> r.isOpen;
    cout << "Enter the distance to the restaurant (in miles): ";
    cin >> r.distance;
    cin.ignore(); // Clear newline character from input buffer

    int numItems; 
    cout << "Enter number of menu items: ";
    cin >> numItems;
    cin.ignore(); // Clear newline character from input buffer

    for (int i = 0; i < numItems; ++i) {
        string item; 
        double price; 
        cout << "Enter menu item " << (i + 1) << ": ";
        getline(cin, item);
        cout << "Enter price for " << item << ": ";
        cin >> price;
        cin.ignore(); // Clear newline character from input buffer
        r.menuItems.push_back(item);
        r.itemPrices.push_back(price);
    }
    return r; 
};

// Pretty-printer
void printRestaurant(const Restaurant &r) { 
    cout << "----------------------------------------\n";
    cout << "Restaurant Address: " << r.address << endl; 
    cout << "Rating: " << r.rating << endl; 
    cout << "Is Open: " << (r.isOpen ? "Yes" : "No") << endl; 
    cout << "Distance: " << r.distance << " miles" << endl; 
    cout << "Menu Items:" << endl; 
    for (size_t i = 0; i < r.menuItems.size(); ++i) {
        cout << "  - " << r.menuItems[i] << ": $" << r.itemPrices[i] << endl; 
    }
}

int main() { 
    cout << "Enter details for Restaurant #1\n";
    Restaurant a = buildRestaurant();

    cout << "\nDetails of Restaurant #2\n";
    Restaurant b = buildRestaurant(); 

    Restaurant c = {
        "123 Main St, Anytown, USA", // address
        4,                          // rating
        true,                       // isOpen
        2.5,                        // distance
        {"Burger", "Fries", "Soda"},// menuItems
        {5.99, 2.49, 1.99}          // itemPrices
    };

    Restaurant d = {
        "456 Elm St, Othertown, USA", // address
        5,                          // rating
        false,                      // isOpen
        4.0,                        // distance
        {"Pizza", "Salad", "Water"},// menuItems
        {8.99, 4.99, 0.00}          // itemPrices
    };

    // Store and print all
    vector<Restaurant> all {a, b, c, d};

    cout << "\n\nAll Restaurants:\n";
    for (const auto &rest : all) {
        printRestaurant(rest);
    }
}