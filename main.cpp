#include <iostream>
#include <cmath>

using namespace std;

typedef uint32_t number_t;

class Table
{
public:
    Table(number_t size) {
        this->size = size;
        this->table = new bool[size + 1];
        memset(table, true, size + 1);
    }

    void calculate() {
        auto limit = (number_t) sqrt(size);

        for (number_t i=2; i<limit; i++) {
            this->strikeOutMultipliersOf(i);
        }
    }

    void printPrimeNumbers() {
        for (number_t i=2; i<=this->size; i++) {
            if (this->table[i]) {
                cout << i << " ";
            }
        }
    }
private:
    bool* table;
    number_t size;

    void strikeOutMultipliersOf(number_t number) {
        if (!this->table[number]) {
            return;
        }

        for (number_t i=number*2; i <= this->size; i+=number) {
            this->table[i] = false;
        }
    }
};

number_t inputMaxNumber()
{
    number_t number;
    cin >> number;
    if (!cin.good()) {
        throw runtime_error("Bad input!");
    }

    return number;
}

int main() {
    number_t size = inputMaxNumber();
    Table table = Table(size);

    table.calculate();
    table.printPrimeNumbers();

    cout << endl;
    return 0;
}
