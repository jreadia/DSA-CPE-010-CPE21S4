#include <iostream>
#include <string>
using namespace std;

// Class of Fruits
class Fruit {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Fruit(string newName = "Fruit", double newPrice = 1.0, int newQuantity = 1) {
        name = move(newName);
        price = newPrice;
        quantity = newQuantity;
    }

    // Destructor
    ~Fruit() {}

    // Copy Constructor
    Fruit(const Fruit &copyFruit) {
        cout << "Copy Constructor Called" << endl;
        name = copyFruit.name;
        price = copyFruit.price;
        quantity = copyFruit.quantity;
    }

    // Calculate the total sum of all the fruits
    double calculateSum() {
        return price * quantity;
    }

    // Display Attributes
    void printDetails() {
        cout << this->name << " | PHP " << this->price << " | " << this->quantity << " pieces" << endl;
    }
};

// Class of Vegetables
class Vegetable {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Vegetable(string newName = "Vegetable", double newPrice = 1.0, int newQuantity = 1) {
        name = move(newName);
        price = newPrice;
        quantity = newQuantity;
    }

    // Destructor
    ~Vegetable() {}

    // Copy Constructor
    Vegetable(const Vegetable &copyVegetable) {
        cout << "Copy Constructor Called" << endl;
        name = copyVegetable.name;
        price = copyVegetable.price;
        quantity = copyVegetable.quantity;
    }

    // Calculate the total sum of all the vegetables
    double calculateSum() {
        return price * quantity;
    }

    // Display Attributes
    void printDetails() {
        cout << this->name << " | PHP " << this->price << " | " << this->quantity << " pieces" << endl;
    }
};

int main() {

    // Create instances of Jenna's Grocery List
    Fruit apple("Apple", 10, 7);
    Fruit banana("Banana", 10, 8);
    Vegetable brocolli("Brocolli", 60, 12);
    Vegetable lettuce("Lettuce", 50, 10);

    // Create an array of pointers to the base class
    void* groceryList[4];

    // Add instances to the array
    groceryList[0] = &apple;
    groceryList[1] = &banana;
    groceryList[2] = &brocolli;
    groceryList[3] = &lettuce;

    // Display details of each item
    cout << "Jenna's Original Grocery List:" << endl;
    for (int i = 0; i < 4; ++i) {
        if (i < 2) {
            static_cast<Fruit*>(groceryList[i])->printDetails();
        } else {
            static_cast<Vegetable*>(groceryList[i])->printDetails();
        }
    }
    cout << endl;

    // Remove Lettuce from the grocery list
    groceryList[3] = nullptr;

    // Display details of each item after removal
    cout << "Jenna's Grocery List after removing Lettuce:" << endl;
    for (int i = 0; i < 4; ++i) {
        if (groceryList[i] != nullptr) {
            if (i < 2) {
                static_cast<Fruit*>(groceryList[i])->printDetails();
            } else {
                static_cast<Vegetable*>(groceryList[i])->printDetails();
            }
        }
    }

return 0;
}