##include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum PartType {
    ENGINE,
    TRANSMISSION,
    BRAKES,
    SUSPENSION,
    ELECTRICAL,
    UNKNOWN
};

class SquarePart {
private:
    string brandName;
    string quantityPart;
    PartType partType;

public:
    // Accessor methods
    string getBrandName() const {
        return brandName;
    }

    void setBrandName(const string &brandName) {
        this->brandName = brandName;
    }

    string getQuantityPart() const {
        return quantityPart;
    }

    void setQuantityPart(const string &quantityPart) {
        this->quantityPart = quantityPart;
    }

    PartType getPartType() const {
        return partType;
    }

    void setPartType(PartType partType) {
        this->partType = partType;
    }

    // Overloaded equality operator
    bool operator==(const SquarePart &other) const {
        return partType == other.partType;
    }

    // Default constructor
    SquarePart() : brandName(""), quantityPart(""), partType(UNKNOWN) {}

    // Overloaded constructor
    SquarePart(const string &brandName, const string &quantityPart, PartType partType)
        : brandName(brandName), quantityPart(quantityPart), partType(partType) {}
};

class Vehicle {
private:
    vector<SquarePart> vehicleParts;
    int size;

    PartType selectPartType() {
        int choice;
        cout << "Select part type:\n";
        cout << "1. Engine\n";
        cout << "2. Transmission\n";
        cout << "3. Brakes\n";
        cout << "4. Suspension\n";
        cout << "5. Electrical\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: return ENGINE;
            case 2: return TRANSMISSION;
            case 3: return BRAKES;
            case 4: return SUSPENSION;
            case 5: return ELECTRICAL;
            default: return UNKNOWN;
        }
    }

public:
    // Constructor initializes the vector with 5 elements
    Vehicle() : size(5) {
        vehicleParts.resize(size);
    }

    // Function to add parts
    void AddPart() {
        for (size_t i = 0; i < size; ++i) {
            string brandName, quantityPart;
            PartType partType;
            cout << "Enter brand of the part " << i + 1 << ": ";
            cin >> brandName;
            cout << "Enter the quantity of the part " << i + 1 << ": ";
            cin >> quantityPart;
            partType = selectPartType();
            vehicleParts[i] = SquarePart(brandName, quantityPart, partType);
        }
    }

    void SavePartsToFile() {
        ofstream outFile("Carsmodel.txt");
        if (outFile.is_open()) {
            for (const auto &part : vehicleParts) {
                outFile << part.getBrandName() << " "
                        << part.getQuantityPart() << " "
                        << partTypeToString(part.getPartType()) << endl;
            }
            outFile.close();
            cout << "Parts saved to Carsmodel.txt" << endl;
        } else {
             cout << "Failed to open Carsmodel.txt for writing" << endl;
        }
    }

    void ShowAllParts() const {
        for (const auto &part : vehicleParts) {
            cout << "Brand Name: " << part.getBrandName() << ", "
                 << "Quantity part: " << part.getQuantityPart() << ", "
                 << "Part Type: " << partTypeToString(part.getPartType()) << endl;
        }
    }

    void Run() {
        int choice;
        do {
            cout << "\n OPTIONS Menu:\n";
            cout << "1. Add a spare part\n";
            cout << "2. Show all added spare parts\n";
            cout << "3. Save Parts to file\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    AddPart();
                    break;
                case 2:
                    ShowAllParts();
                    break;
                case 3:
                    SavePartsToFile();
                    break;
                case 4:
                    cout << "Exiting application." << endl;
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        } while (choice != 4);
    }

private:
    string partTypeToString(PartType partType) const {
        switch (partType) {
            case ENGINE: return "Engine";
            case TRANSMISSION: return "Transmission";
            case BRAKES: return "Brakes";
            case SUSPENSION: return "Suspension";
            case ELECTRICAL: return "Electrical";
            default: return "Unknown";
        }
    }
};
z
int main() {
    Vehicle vehicle;
    vehicle.Run();
    return 0;
}
