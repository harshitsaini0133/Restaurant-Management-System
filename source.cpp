#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Table {
    int tableNumber;
    int capacity;
    bool status; // true for occupied, false for vacant

public:
    Table(int tableNumber, int capacity) {
        this->tableNumber = tableNumber;
        this->capacity = capacity;
        this->status = false; // initially vacant
    }

    int getTableNumber() {
        return tableNumber;
    }

    int getCapacity() {
        return capacity;
    }

    bool getStatus() {
        return status;
    }

    void setStatus(bool status) {
        this->status = status;
    }
};

class Menu {
    string itemName;
    float price;
    bool availability;

public:
    Menu(string itemName, float price, bool availability) {
        this->itemName = itemName;
        this->price = price;
        this->availability = availability;
    }

    string getItemName() {
        return itemName;
    }

    float getPrice() {
        return price;
    }

    bool getAvailability() {
        return availability;
    }

    void setAvailability(bool availability) {
        this->availability = availability;
    }
};

class Order {
    int orderNumber;
    int tableNumber;
    vector<string> itemsOrdered;
    float totalPrice;

public:
    Order(int orderNumber, int tableNumber) {
        this->orderNumber = orderNumber;
        this->tableNumber = tableNumber;
        this->totalPrice = 0.0;
    }

    int getOrderNumber() {
        return orderNumber;
    }

    int getTableNumber() {
        return tableNumber;
    }

    vector<string> getItemsOrdered() {
        return itemsOrdered;
    }

    float getTotalPrice() {
        return totalPrice;
    }

    void addItem(string itemName, float price) {
        itemsOrdered.push_back(itemName);
        totalPrice += price;
    }
};

class Restaurant {
    string name;
    string location;
    int openingTime;
    int closingTime;
    vector<Table> tables;
    vector<Menu> menu;
    vector<Order> orders;

public:
    Restaurant(string name, string location, int openingTime, int closingTime) {
        this->name = name;
        this->location = location;
        this->openingTime = openingTime;
        this->closingTime = closingTime;
    }

    void addTable(int tableNumber, int capacity) {
        Table table(tableNumber, capacity);
        tables.push_back(table);
    }

    void addMenuItem(string itemName, float price, bool availability) {
        Menu item(itemName, price, availability);
        menu.push_back(item);
    }

    void placeOrder(int orderNumber, int tableNumber, string itemName) {
        Order order(orderNumber, tableNumber);
        for (Menu item : menu) {
            if (item.getItemName() == itemName) {
                order.addItem(itemName, item.getPrice());
                orders.push_back(order);
                cout << "Order placed successfully!" << endl;
                return;
            }
        }
        cout << "Item not available!" << endl;
    }

    void viewOrders() {
        cout << "Orders:" << endl;
        for (Order order : orders) {
            cout << "Order Number: " << order.getOrderNumber() << endl;
            cout << "Table Number: " << order.getTableNumber() << endl;
            cout << "Items Ordered: ";
            for (string item : order.getItemsOrdered()) {
                cout << item << " ";
            }
            cout << endl;
            cout << "Total Price: " << order.getTotalPrice() << endl;
            cout << endl;
        }
    }
};

int main() {
    Restaurant restaurant("My Restaurant", "New York", 10, 22);

    restaurant.addTable(1, 4);
    restaurant.addTable(2, 4);
    restaurant.addTable(3, 4);

    restaurant.addMenuItem("Burger", 10.99, true);
    restaurant.addMenuItem("Pizza", 14.99, true);
    restaurant.addMenuItem("Salad", 8.99, true);

    restaurant.placeOrder(1, 1, "Burger");
    restaurant.placeOrder(2, 1, "Pizza");
    restaurant.placeOrder(3, 2, "Salad");

    restaurant.viewOrders();

    return 0;
}