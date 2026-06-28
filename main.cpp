#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CUSTOMERS = 100;
const int MAX_CARS = 100;

// ===== Structs ===== YOUSEF BEBARS
struct Customer {
    string name;
    string mobile;
    string address;
    string nationalID;
    string jobTitle;
};

struct Car {
    string brand;
    string model;
    string color;
    int distance;
    bool available;
};

struct Visa {
    string bankName;
    string cardNumber;
    string ownerName;
    int cvv;
};

// ===== Arrays =====
Customer customers[MAX_CUSTOMERS];
Car cars[MAX_CARS];

int customerCount = 0;
int carCount = 0;
bool isLoggedIn = false;

// ===== Integer Input Helper ===== RAWAN
int readInt() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

// ===== Validation Helper ===== RAWAN
bool isAllDigits(string s) {
    if (s.length() == 0) return false;
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

// ===== File Handling ===== YOUSEF FOUAD
void saveData() {
    ofstream carFile("CARS.txt");
    carFile << carCount << endl;
    for (int i = 0; i < carCount; i++) {
        carFile << cars[i].brand << endl;
        carFile << cars[i].model << endl;
        carFile << cars[i].color << endl;
        carFile << cars[i].distance << endl;
        if (cars[i].available)
            carFile << "Available" << endl;
        else
            carFile << "NotAvailable" << endl;
    }
    carFile.close();

    ofstream custFile("CUSTOMERS.txt");
    custFile << customerCount << endl;
    for (int i = 0; i < customerCount; i++) {
        custFile << customers[i].name << endl;
        custFile << customers[i].mobile << endl;
        custFile << customers[i].address << endl;
        custFile << customers[i].nationalID << endl;
        custFile << customers[i].jobTitle << endl;
    }
    custFile.close();
}

void loadData() {
    ifstream carFile("CARS.txt");
    if (carFile) {
        carFile >> carCount;
        carFile.ignore(1000, '\n');
        for (int i = 0; i < carCount; i++) {
            getline(carFile, cars[i].brand);
            getline(carFile, cars[i].model);
            getline(carFile, cars[i].color);
            carFile >> cars[i].distance;
            carFile.ignore(1000, '\n');
            string status;
            getline(carFile, status);
            cars[i].available = (status == "Available");
        }
        carFile.close();
    }

    ifstream custFile("CUSTOMERS.txt");
    if (custFile) {
        custFile >> customerCount;
        custFile.ignore(1000, '\n');
        for (int i = 0; i < customerCount; i++) {
            getline(custFile, customers[i].name);
            getline(custFile, customers[i].mobile);
            getline(custFile, customers[i].address);
            getline(custFile, customers[i].nationalID);
            getline(custFile, customers[i].jobTitle);
        }
        custFile.close();
    }
}

// ===== Sign Up ===== RAWAN
void signUp() {
    string id;

    do {
        cout << "Enter your National ID (14 digits only): ";
        cin >> id;
        if (!isAllDigits(id) || id.length() != 14)
            cout << "Invalid ID. Must be exactly 14 digits.\n";
    } while (!isAllDigits(id) || id.length() != 14);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].nationalID == id) {
            cout << "User already exists, try logging in.\n";
            return;
        }
    }


    customers[customerCount].nationalID = id;
    cin.ignore(1000, '\n');

    cout << "Enter your name: ";
    getline(cin, customers[customerCount].name);

    cout << "Enter your mobile: ";
    getline(cin, customers[customerCount].mobile);

    cout << "Enter your address: ";
    getline(cin, customers[customerCount].address);

    cout << "Enter your job title: ";
    getline(cin, customers[customerCount].jobTitle);

    customerCount++;
    cout << "Account created successfully!\n";
    saveData();
}

// ===== Login ===== HANEEN
bool login() {
    string id , name;
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter Your National ID: ";
    cin >> id;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].nationalID == id && customers[i].name == name) {
            cout << "Login Successful. Welcome, " << customers[i].name << "!\n";
            isLoggedIn = true;
            return true;
        }
    }

    cout << "User Not Found.\n";
    return false;
}

// ===== Search Car ===== YOUSEF FOUAD
void searchCar() {
    cout << "\nSearch by (brand / model / color): ";
    string keyword;
    cin >> keyword;

    bool found = false;
    for (int i = 0; i < carCount; i++) {
        if (cars[i].brand == keyword ||
            cars[i].model == keyword ||
            cars[i].color == keyword) {

            cout << "\nCar " << i + 1 << ": "
                << cars[i].brand << " "
                << cars[i].model << " "
                << cars[i].color << " "
                << cars[i].distance << "km "
                << (cars[i].available ? "Available" : "Not Available")
                << endl;
            found = true;
        }
    }

    if (!found) cout << "No cars found.\n";
}

// ===== Add Car ===== AHMAD
void addCar() {


    cout << "Brand: ";
    getline(cin, cars[carCount].brand);

    cout << "Model: ";
    getline(cin, cars[carCount].model);

    cout << "Color: ";
    getline(cin, cars[carCount].color);

    cout << "Distance (km): ";
    cars[carCount].distance = readInt();

    cars[carCount].available = true;
    carCount++;
    cout << "Car Added Successfully!\n";
    saveData();
}

// ===== List Cars ===== AMANY
void listCars() {
    if (carCount == 0) {
        cout << "No cars in the system.\n";
        return;
    }
    for (int i = 0; i < carCount; i++) {
        cout << i + 1 << ". " << cars[i].brand << " " << cars[i].model
            << " (" << (cars[i].available ? "Available" : "Not Available") << ")\n";
    }
}



// ===== Update Car ===== AMIRA

void updateCar() { //checks if car number is valid before updating
    if (carCount == 0) {
        cout << "No cars in the system.\n";
        return;
    }
    listCars();
    cout << "Enter Car Number (1 to " << carCount << "): ";
    int num = readInt();

    if (num < 1 || num > carCount) {
        cout << "Invalid car number.\n";
        return;
    }
    num--;

    cout << "New Brand: ";
    getline(cin, cars[num].brand);

    cout << "New Model: ";
    getline(cin, cars[num].model);

    cout << "New Color: ";
    getline(cin, cars[num].color);

    cout << "New Distance (km): ";
    cars[num].distance = readInt();

    cout << "Car Updated Successfully!\n";
    saveData();
}

// ===== Remove Car ===== AMIRA

void removeCar() { //checks if car number is valid before removing
    if (carCount == 0) {
        cout << "No cars in the system.\n";
        return;
    }
    listCars();
    cout << "Enter Car Number (1 to " << carCount << "): ";
    int num = readInt();

    if (num < 1 || num > carCount) {
        cout << "Invalid car number.\n";
        return;
    }
    num--;

    for (int i = num; i < carCount - 1; i++) {
        cars[i] = cars[i + 1];
    }

    carCount--;
    cout << "Car Removed Successfully!\n";
    saveData();
}

// ===== Show Cars ===== AMANY
void showCars() {
    if (carCount == 0) {
        cout << "No cars in the system.\n";
        return;
    }
    for (int i = 0; i < carCount; i++) {
        cout << "\n--- Car " << i + 1 << " ---\n";
        cout << "Brand:    " << cars[i].brand << endl;
        cout << "Model:    " << cars[i].model << endl;
        cout << "Color:    " << cars[i].color << endl;
        cout << "Distance: " << cars[i].distance << " km\n";
        cout << "Status:   " << (cars[i].available ? "Available" : "Not Available") << endl;
    }
}


// ===== Check Car ===== AMANY
void checkCar() {
    if (carCount == 0) {
        cout << "No cars in the system.\n";
        return;
    }
    listCars();
    cout << "Enter Car Number (1 to " << carCount << "): ";
    int num = readInt();

    if (num < 1 || num > carCount) {
        cout << "Invalid car number.\n";
        return;
    }

    if (cars[num - 1].available)
        cout << "Car is Available.\n";
    else
        cout << "Car is Not Available.\n";
}

// ===== Payment ===== YOUSEF BEBARS

bool payment() {
    int choice;
    cout << "\nPayment Method:\n1. Cash\n2. Visa\nChoice: ";
    choice = readInt();

    if (choice == 1) {
        cout << "Paid by Cash. Thank you!\n";
        return true;
    }
    else if (choice == 2) {
        Visa v;

        cout << "Bank Name: ";
        getline(cin, v.bankName);

        cout << "Card Number: ";
        getline(cin, v.cardNumber);

        cout << "Card Owner Name: ";
        getline(cin, v.ownerName);

        cout << "CVV: ";
        v.cvv = readInt();

        cout << "Visa Payment Successful. Thank you!\n";
        return true;
    }
    else {
        cout << "Invalid payment choice. Rental cancelled.\n";
        return false;  // invalid payment returns false so car stays available
    }
}

// ===== Rent Car ===== YOUSEF BEBARS
void rentCar() {
    if (carCount == 0) {
        cout << "No cars in the system.\n";
        return;
    }
    listCars();
    cout << "Enter Car Number (1 to " << carCount << "): ";
    int num = readInt();

    if (num < 1 || num > carCount) {
        cout << "Invalid car number.\n";
        return;
    }

    if (cars[num - 1].available) {
        bool paid = payment();
        if (paid) {
            cars[num - 1].available = false;
            cout << "Car Rented Successfully!\n";
            saveData();
        }

    }
    else {
        cout << "Car is Not Available.\n";
    }
}

// ===== Cancel Reservation ===== YOUSEF BEBARS

void cancelReservation() {
    if (carCount == 0) {
        cout << "No cars in the system.\n";
        return;
    }
    listCars();
    cout << "Enter Car Number (1 to " << carCount << "): ";
    int num = readInt();

    if (num < 1 || num > carCount) {
        cout << "Invalid car number.\n";
        return;
    }

    if (cars[num - 1].available) {
        cout << "This car is not rented. No reservation to cancel.\n";
        return;
    }

    cars[num - 1].available = true;
    cout << "Reservation Cancelled Successfully!\n";
    saveData();
}

// ===== Main ===== YOUSEF FOUAD
int main() {

    loadData();

    int choice;

    do {
        cout << "\n==== Car Rental System ====\n";
        cout << "1.  Sign Up\n";
        cout << "2.  Login\n";
        cout << "3.  Search Car\n";
        cout << "4.  Add Car\n";
        cout << "5.  Update Car\n";
        cout << "6.  Remove Car\n";
        cout << "7.  Show Car Details\n";
        cout << "8.  List Cars\n";
        cout << "9.  Check Car\n";
        cout << "10. Rent Car\n";
        cout << "11. Cancel Reservation\n";
        cout << "12. Exit\n";
        cout << "Choice: ";

        choice = readInt();  // to accept only integars

        if (choice >= 3 && choice <= 11 && !isLoggedIn) {
            cout << "You must be logged in first. Please Sign Up or Login.\n";
            continue;
        }

        switch (choice) {
        case 1:  signUp(); break;
        case 2:  login(); break;
        case 3:  searchCar(); break;
        case 4:  addCar(); break;
        case 5:  updateCar(); break;
        case 6:  removeCar(); break;
        case 7:  showCars(); break;
        case 8:  listCars(); break;
        case 9:  checkCar(); break;
        case 10: rentCar(); break;
        case 11: cancelReservation(); break;
        case 12: saveData(); cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice. Try again.\n"; break;
        }

    } while (choice != 12);

    return 0;
}
