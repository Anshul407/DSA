#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const int MAX_E = 100;
const int MAX_ML = 50;
class Employee {
public:
int key;
string name;
Employee() : key(0), name("") {}
};
class HashTable {
Employee table[MAX_ML];
bool occupied[MAX_ML];
public:
HashTable() {
for (int i = 0; i < MAX_ML; ++i)
occupied[i] = false;
}
int hashFunction(int key, int m) { return key % m; }
void insert(const Employee& employee, int m) {
int key = employee.key;
int hashValue = hashFunction(key, m);
while (occupied[hashValue])
hashValue = (hashValue + 1) % m;
table[hashValue] = employee;
occupied[hashValue] = true;
}
void displayTable() {
cout << setw(10) << "Memory Location"<< setw(10) << "Key"<< setw(15)
<< "Employee Name" << endl;
for (int i = 0; i < MAX_ML; ++i) {
if (occupied[i])
cout << setw(10) << i << setw(10) << table[i].key << setw(15)
<< table[i].name << endl;
}
}
};
int main() {
HashTable employeeHashTable;
Employee emp1;
emp1.key = 70013;
emp1.name = "Anshul Kunwar";
Employee emp2;
emp2.key = 70024;
emp2.name = "Rohit Raj";
Employee emp3;
emp3.key = 70025;
emp3.name = "Paramjit";
int m = 10;
employeeHashTable.insert(emp1, m);
employeeHashTable.insert(emp2, m);
employeeHashTable.insert(emp3, m);
cout << "Hash Table:" << endl;
employeeHashTable.displayTable();
return 0;
}
