#include <iostream>
#include <string>

// Enumeration for ingredient types
enum class IngredientType {
    FLOUR,
    SUGAR,
    SALT,
    MILK,
    EGGS,
    UNKNOWN
};

class Ingredient {
private:
    double amount;
    IngredientType type;

public:
    // Default constructor
    Ingredient() : amount(0.0), type(IngredientType::UNKNOWN) {}

    // Overloaded constructor
    Ingredient(double amount, IngredientType type) : amount(amount), type(type) {}

    // Accessor methods
    double getAmount() const { return amount; }
    IngredientType getType() const { return type; }

    // Overloaded equality operator
    bool operator==(const Ingredient &other) const {
        return (amount == other.amount) && (type == other.type);
    }

    // Function to get ingredient name as string
    std::string ingredientName() const {
        switch (type) {
            case IngredientType::FLOUR: return "Flour";
            case IngredientType::SUGAR: return "Sugar";
            case IngredientType::SALT: return "Salt";
            case IngredientType::MILK: return "Milk";
            case IngredientType::EGGS: return "Eggs";
            default: return "Unknown";
        }
    }
};

int main() {
    // Example usage
    Ingredient flour(2.5, IngredientType::FLOUR);
    std::cout << "Amount of " << flour.ingredientName() << ": " << flour.getAmount() << " kg" << std::endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Include for input validation

// Enumeration for ingredient types
enum class IngredientType {
    FLOUR,
    SUGAR,
    SALT,
    MILK,
    EGGS,
    UNKNOWN
};

// Class for Ingredient
class Ingredient {
private:
    double amount;
    IngredientType type;

public:
    Ingredient(double amount, IngredientType type) : amount(amount), type(type) {}

    double getAmount() const { return amount; }
    IngredientType getType() const { return type; }

    std::string ingredientName() const {
        switch (type) {
            case IngredientType::FLOUR: return "Flour";
            case IngredientType::SUGAR: return "Sugar";
            case IngredientType::SALT: return "Salt";
            case IngredientType::MILK: return "Milk";
            case IngredientType::EGGS: return "Eggs";
            default: return "Unknown";
        }
    }
};

// Class for Cake
class Cake {
private:
    static const int MAX_INGREDIENTS = 5;
    Ingredient* ingredients[MAX_INGREDIENTS];
    int validIngredientsCount;

    void addIngredient(Ingredient* ingredient) {
        if (validIngredientsCount < MAX_INGREDIENTS) {
            ingredients[validIngredientsCount++] = ingredient;
        }
    }

    void saveIngredientsToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            if (validIngredientsCount == 0) {
                std::cout << "No valid ingredients to save." << std::endl;
                outFile.close();
                return;
            }

            for (int i = 0; i < validIngredientsCount; ++i) {
                outFile << ingredients[i]->ingredientName() << " " << ingredients[i]->getAmount() << std::endl;
            }
            outFile.close();
            std::cout << "Valid ingredients saved to " << filename << std::endl;
        } else {
            std::cout << "Failed to open or create " << filename << std::endl;
        }
    }

    void showAllIngredients() const {
        for (int i = 0; i < validIngredientsCount; ++i) {
            std::cout << "Ingredient " << i + 1 << ": " << ingredients[i]->ingredientName() << " (" 
                      << ingredients[i]->getAmount() << " units)" << std::endl;
        }
    }

    IngredientType selectIngredientType() const {
        int choice;
        std::cout << "Select ingredient type:\n";
        std::cout << "1. Flour\n";
        std::cout << "2. Sugar\n";
        std::cout << "3. Salt\n";
        std::cout << "4. Milk\n";
        std::cout << "5. Eggs\n";
        std::cout << "Enter your choice: ";

        // Validate input
        while (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input buffer
        }

        switch (choice) {
            case 1: return IngredientType::FLOUR;
            case 2: return IngredientType::SUGAR;
            case 3: return IngredientType::SALT;
            case 4: return IngredientType::MILK;
            case 5: return IngredientType::EGGS;
            default: return IngredientType::UNKNOWN;
        }
    }

public:
    Cake() : validIngredientsCount(0) {
        for (int i = 0; i < MAX_INGREDIENTS; ++i) {
            ingredients[i] = nullptr;
        }
    }

    void AddIngredient() {
        if (validIngredientsCount >= MAX_INGREDIENTS) {
            std::cout << "Array is full. Cannot add more ingredients." << std::endl;
            return;
        }

        IngredientType type = selectIngredientType();
        double amount;
        std::cout << "Enter amount of " << Ingredient(0, type).ingredientName() << ": ";
        std::cin >> amount;

        // Check if an ingredient of the same type already exists
        for (int i = 0; i < validIngredientsCount; ++i) {
            if (ingredients[i]->getType() == type) {
                std::cout << "An ingredient of the same type already exists in the array." << std::endl;
                return;
            }
        }

        // Assign the ingredient
        ingredients[validIngredientsCount] = new Ingredient(amount, type);
        std::cout << "Ingredient added successfully." << std::endl;

        // Update the count of valid ingredients
        validIngredientsCount++;
    }

    void SaveIngredientsToFile() {
        saveIngredientsToFile("cake.txt");
    }

    void ShowAllIngredients() const {
        showAllIngredients();
    }

    void Bake() {
        while (validIngredientsCount < MAX_INGREDIENTS) {
            AddIngredient();
        }

        SaveIngredientsToFile();
        ShowAllIngredients();
    }
};


#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Include for input validation

// Enumeration for ingredient types
enum class IngredientType {
    FLOUR,
    SUGAR,
    SALT,
    MILK,
    EGGS,
    UNKNOWN
};

// Class for Ingredient
class Ingredient {
private:
    double amount;
    IngredientType type;

public:
    Ingredient(double amount, IngredientType type) : amount(amount), type(type) {}

    double getAmount() const { return amount; }
    IngredientType getType() const { return type; }

    std::string ingredientName() const {
        switch (type) {
            case IngredientType::FLOUR: return "Flour";
            case IngredientType::SUGAR: return "Sugar";
            case IngredientType::SALT: return "Salt";
            case IngredientType::MILK: return "Milk";
            case IngredientType::EGGS: return "Eggs";
            default: return "Unknown";
        }
    }
};

// Class for Cake
class Cake {
private:
    static const int MAX_INGREDIENTS = 5;
    Ingredient* ingredients[MAX_INGREDIENTS];
    int validIngredientsCount;

    void addIngredient(Ingredient* ingredient) {
        if (validIngredientsCount < MAX_INGREDIENTS) {
            ingredients[validIngredientsCount++] = ingredient;
        }
    }

    void saveIngredientsToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            if (validIngredientsCount == 0) {
                std::cout << "No valid ingredients to save." << std::endl;
                outFile.close();
                return;
            }

            for (int i = 0; i < validIngredientsCount; ++i) {
                outFile << ingredients[i]->ingredientName() << " " << ingredients[i]->getAmount() << std::endl;
            }
            outFile.close();
            std::cout << "Valid ingredients saved to " << filename << std::endl;
        } else {
            std::cout << "Failed to open or create " << filename << std::endl;
        }
    }

    void showAllIngredients() const {
        for (int i = 0; i < validIngredientsCount; ++i) {
            std::cout << "Ingredient " << i + 1 << ": " << ingredients[i]->ingredientName() << " (" 
                      << ingredients[i]->getAmount() << " units)" << std::endl;
        }
    }

    IngredientType selectIngredientType() const {
        int choice;
        std::cout << "Select ingredient type:\n";
        std::cout << "1. Flour\n";
        std::cout << "2. Sugar\n";
        std::cout << "3. Salt\n";
        std::cout << "4. Milk\n";
        std::cout << "5. Eggs\n";
        std::cout << "Enter your choice: ";

        // Validate input
        while (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input buffer
        }

        switch (choice) {
            case 1: return IngredientType::FLOUR;
            case 2: return IngredientType::SUGAR;
            case 3: return IngredientType::SALT;
            case 4: return IngredientType::MILK;
            case 5: return IngredientType::EGGS;
            default: return IngredientType::UNKNOWN;
        }
    }

public:
    Cake() : validIngredientsCount(0) {
        for (int i = 0; i < MAX_INGREDIENTS; ++i) {
            ingredients[i] = nullptr;
        }
    }

    void AddIngredient() {
        if (validIngredientsCount >= MAX_INGREDIENTS) {
            std::cout << "Array is full. Cannot add more ingredients." << std::endl;
            return;
        }

        IngredientType type = selectIngredientType();
        double amount;
        std::cout << "Enter amount of " << Ingredient(0, type).ingredientName() << ": ";
        std::cin >> amount;

        // Check if an ingredient of the same type already exists
        for (int i = 0; i < validIngredientsCount; ++i) {
            if (ingredients[i]->getType() == type) {
                std::cout << "An ingredient of the same type already exists in the array." << std::endl;
                return;
            }
        }

        // Assign the ingredient
        ingredients[validIngredientsCount] = new Ingredient(amount, type);
        std::cout << "Ingredient added successfully." << std::endl;

        // Update the count of valid ingredients
        validIngredientsCount++;
    }

    void SaveIngredientsToFile() {
        saveIngredientsToFile("cake.txt");
    }

    void ShowAllIngredients() const {
        showAllIngredients();
    }

    void Bake() {
        while (validIngredientsCount < MAX_INGREDIENTS) {
            AddIngredient();
        }

        SaveIngredientsToFile();
        ShowAllIngredients();
    }
};

int main() {
    Cake cake;
    cake.Bake();
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Include for input validation

// Enumeration for ingredient types
enum class IngredientType {
    FLOUR,
    SUGAR,
    SALT,
    MILK,
    EGGS,
    UNKNOWN
};

// Class for Ingredient
class Ingredient {
private:
    double amount;
    IngredientType type;

public:
    Ingredient(double amount, IngredientType type) : amount(amount), type(type) {}

    double getAmount() const { return amount; }
    IngredientType getType() const { return type; }

    std::string ingredientName() const {
        switch (type) {
            case IngredientType::FLOUR: return "Flour";
            case IngredientType::SUGAR: return "Sugar";
            case IngredientType::SALT: return "Salt";
            case IngredientType::MILK: return "Milk";
            case IngredientType::EGGS: return "Eggs";
            default: return "Unknown";
        }
    }
};

// Class for Cake
me << std::endl;
        }
    }

    void showAllIngredients() const {
        for (int i = 0; i < validIngredientsCount; ++i) {
            std::cout << "Ingredient " << i + 1 << ": " << ingredients[i]->ingredientName() << " (" 
                      << ingredients[i]->getAmount() << " units)" << std::endl;
        }
    }

    IngredientType selectIngredientType() const {
        int choice;
        std::cout << "Select ingredient type:\n";
        std::cout << "1. Flour\n";
        std::cout << "2. Sugar\n";
        std::cout << "3. Salt\n";
        std::cout << "4. Milk\n";
        std::cout << "5. Eggs\n";
        std::cout << "Enter your choice: ";

        // Validate input
        while (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input buffer
        }

        switch (choice) {
            case 1: return IngredientType::FLOUR;
            case 2: return IngredientType::SUGAR;
            case 3: return IngredientType::SALT;
            case 4: return IngredientType::MILK;
            case 5: return IngredientType::EGGS;
            default: return IngredientType::UNKNOWN;
        }
    }

public:
    Cake() : validIngredientsCount(0) {
        for (int i = 0; i < MAX_INGREDIENTS; ++i) {
            ingredients[i] = nullptr;
        }
    }

    void AddIngredient() {
        if (validIngredientsCount >= MAX_INGREDIENTS) {
            std::cout << "Array is full. Cannot add more ingredients." << std::endl;
            return;
        }

        IngredientType type = selectIngredientType();
        double amount;
        std::cout << "Enter amount of " << Ingredient(0, type).ingredientName() << ": ";
        std::cin >> amount;

        // Check if an ingredient of the same type already exists
        for (int i = 0; i < validIngredientsCount; ++i) {
            if (ingredients[i]->getType() == type) {
                std::cout << "An ingredient of the same type already exists in the array." << std::endl;
                return;
            }
        }

        // Assign the ingredient
        ingredients[validIngredientsCount] = new Ingredient(amount, type);
        std::cout << "Ingredient added successfully." << std::endl;

        // Update the count of valid ingredients
        validIngredientsCount++;
    }

    void SaveIngredientsToFile() {
        saveIngredientsToFile("cake.txt");
    }

    void ShowAllIngredients() const {
        showAllIngredients();
    }

    void Bake() {
        while (validIngredientsCount < MAX_INGREDIENTS) {
            AddIngredient();
        }

        SaveIngredientsToFile();
        ShowAllIngredients();
    }
};

int main() {
    Cake cake;
    cake.Bake();
    return 0;
}

