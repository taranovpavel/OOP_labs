#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
using namespace std;


double power(double n, int p);
float power(float n, int p);
int power(int n, int p);
short power(short n, int p);
long power(long n, int p);
char power(char n, int p);

struct WorkerStruct
{
	string lastName;
	short age;
	string speciality;
	int averageSalary;
};

int main() {
	
	//1
	cout << "Exercise 1" << endl;
	string input;
	double x;
	int y;
	cout << "Enter two numbers separated by a space: ";
	getline(cin, input);
	stringstream ss(input);
	ss >> x;
	if (!(ss >> y)||y<2) {
		y = 2;
	}
	cout << "Your number: " << power(x, y) << endl << endl;

	//2
	cout << "Exercise 2" << endl;
	cout << "Double: " << power(2.5f, 4) << endl;
	cout << "Float: " << power(3.5, 4) << endl;
	cout << "Int: " << power(230, 2) << endl;
	cout << "Long: " << power(10L, 4) << endl;
	cout << "Short: " << power(short(2), 3) << endl;
	cout << "Char: " <<  power('B', 2) << endl << endl;
	
	//3
	cout << "Exercise 3" << endl;
	random_device rd;
	mt19937 gen(rd());
	vector<string> lastNames = { "Ivanov","Petrov","Sidorov","Kyznetsov","Kolchin"};
	vector<string> specialites = { "Turner","Electrician","Mechanic"};
	uniform_int_distribution<> ageDist(21, 65);
	uniform_int_distribution<> salaryDist(30000, 100000);
	uniform_int_distribution<> lastNameIndex(0, lastNames.size()-1);
	uniform_int_distribution<> specialitesIndex(0, specialites.size()-1);
	int z, w;
	int turners = 0, mechanics = 0;
	cout << "Enter the number of factories: ";
	cin >> z;
	cout << "Enter the number of workers: ";
	cin >> w;
	cout << endl;
	vector<vector<WorkerStruct>> factories(z);
	for (int i = 0; i < z; i++) {
		for (int ii = 0; ii < w; ii++) {
			WorkerStruct w;
			w.lastName = lastNames[lastNameIndex(gen)];
			w.age = ageDist(gen);
			w.speciality = specialites[specialitesIndex(gen)];
			w.averageSalary = (salaryDist(gen) + 500) / 1000 * 1000;
			factories[i].push_back({ w });
		};
		cout << "Factory " << i + 1 << endl << endl;
		for (int ii = 0; ii < w; ii++) {
			cout << "Worker " << ii + 1 << endl << "Last name: " << factories[i][ii].lastName << endl << "Age: " << factories[i][ii].age << endl << "Average salary: " << factories[i][ii].averageSalary << endl << "Speciality: " << factories[i][ii].speciality << endl << endl;
			if (factories[i][ii].speciality == "Mechanic") {
				mechanics++;
			}
			else if (factories[i][ii].speciality == "Turner") {
				turners++;
			}
		}
	}
	cout << "Total mechanics: " << mechanics << endl;
	cout << "Total turner: " << turners << endl;

	return 0;
}

double power(double n, int p = 2) {
	double result = n;
	for (int i = 1; i < p; i++) { result *= n; }
	return result;
};
float power(float n, int p = 2) {
	float result = n;
	for (int i = 1; i < p; i++) { result *= n; }
	return result;
};
int power(int n, int p = 2) {
	int result = n;
	for (int i = 1; i < p; i++) { result *= n; }
	return result;
};
long power(long n, int p = 2) {
	long result = n;
	for (int i = 1; i < p; i++) { result *= n; }
	return result;
};
short power(short n, int p = 2) {
	short result = n;
	for (int i = 1; i < p; i++) { result *= n; }
	return result;
};
char power(char n, int p = 2) {
	int result = int(n);
	for (int i = 1; i < p; i++) { result *= int(n); }
	return char(result % 256);
};