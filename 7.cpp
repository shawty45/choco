#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Hash Table size
const int TABLE_SIZE = 10;

// Hash function
int hashFunction(const string& key) {
    int hash = 0;
    for (char ch : key)
        hash += ch;
    return hash % TABLE_SIZE;
}

// Separate Chaining Implementation
class SeparateChaining {
    vector<list<pair<string, string>>> table;

public:
    SeparateChaining() : table(TABLE_SIZE) {}

    void insert(const string& name, const string& number) {
        int index = hashFunction(name);
        table[index].emplace_back(name, number);
    }

    string search(const string& name, int& comparisons) {
        int index = hashFunction(name);
        comparisons = 0;

        for (const auto& entry : table[index]) {
            comparisons++;
            if (entry.first == name)
                return entry.second;
        }
        return "Not Found";
    }
};

// Open Addressing (Linear Probing) Implementation
class OpenAddressing {
    vector<pair<string, string>> table;
    vector<bool> isOccupied;

public:
    OpenAddressing() : table(TABLE_SIZE), isOccupied(TABLE_SIZE, false) {}

    void insert(const string& name, const string& number) {
        int index = hashFunction(name);
        while (isOccupied[index]) {
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }
        table[index] = {name, number};
        isOccupied[index] = true;
    }

    string search(const string& name, int& comparisons) {
        int index = hashFunction(name);
        comparisons = 0;

        while (isOccupied[index]) {
            comparisons++;
            if (table[index].first == name)
                return table[index].second;
            index = (index + 1) % TABLE_SIZE;
        }
        return "Not Found";
    }
};

// Main Function to Compare Techniques
int main() {
    SeparateChaining sc;
    OpenAddressing oa;

    // Sample data
    vector<pair<string, string>> clients = {
        {"Alice", "1234"}, {"Bob", "5678"}, {"Charlie", "91011"},
        {"David", "1213"}, {"Eve", "1415"}, {"Frank", "1617"}
    };

    // Insert data
    for (const auto& client : clients) {
        sc.insert(client.first, client.second);
        oa.insert(client.first, client.second);
    }

    // Search and compare
    vector<string> searchKeys = {"Alice", "Eve", "Charlie", "Zara"};
    cout << "Searching for telephone numbers:\n";

    for (const auto& key : searchKeys) {
        int scComparisons = 0, oaComparisons = 0;

        string scResult = sc.search(key, scComparisons);
        string oaResult = oa.search(key, oaComparisons);

        cout << "Name: " << key << "\n";
        cout << "  Separate Chaining: " << scResult << " (Comparisons: " << scComparisons << ")\n";
        cout << "  Open Addressing: " << oaResult << " (Comparisons: " << oaComparisons << ")\n";
    }

    return 0;
}
