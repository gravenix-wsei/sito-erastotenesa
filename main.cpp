#include <iostream>
#include <cmath>

using namespace std;

typedef uint32_t number_t;

class PrimeTable
{
public:
    explicit PrimeTable(number_t size) {
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
        cout << endl;
    }

    void printTwinPrimes() {
        for (number_t i=2; i<=this->size; i++) {
            if (this->isFirstTwinPrime(i)) {
                cout << "(" << i << ", " << i+2 << ") ";
            }
        }
        cout << endl;
    }

    void printQuadrupletPrimes() {
        for (number_t i=2; i<=this->size; i++) {
            if (this->isFirstTwinPrime(i) && this->isFirstTwinPrime(i+6)) {
                cout << "(" << i << ", " << i+2 << ", " << i+6 << ", " << i+8 << ") ";
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

    bool isFirstTwinPrime(number_t number) {
        return this->table[number] && this->table[number + 2];
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
    PrimeTable table = PrimeTable(size);
    table.calculate();

    cout << "Prime numbers: ";
    table.printPrimeNumbers();
    cout << "Twin primes: ";
    table.printTwinPrimes();
    cout << "Quadruplet primes: ";
    table.printQuadrupletPrimes();

    cout << endl;
    return 0;
}
