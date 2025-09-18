#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <fstream>
using namespace std;

struct Time {
    int hours;
    int minutes;
};
class Aeroflot {
public:
    int flightNumber;
    string departure;
    string destination;
    Time arrivalTime;
    Time departureTime;
    string registration;
    void print() const {
        cout << flightNumber << " "
            << destination << " "
            << departure << " "
            << arrivalTime.hours << ":" << (arrivalTime.minutes < 10 ? "0" : "") << arrivalTime.minutes << " "
            << departureTime.hours << ":" << (departureTime.minutes < 10 ? "0" : "") << departureTime.minutes << " "
            << registration << endl;
    }
};
class Group {
public:
    string name;
    string lastName;
    short age;
    int id;
    void print() const {
        cout << id << " "
            << name << " "
            << lastName << " "
            << age << endl;
    }
};
void find(int num,string str , const vector<Group>& G, string field) {
    if (field == "age") {
        for (int i = 0; i < G.size(); i++) {
            if (G[i].age == num) {
                G[i].print();
            }
        }
    }
    else if (field == "id") {
        for (int i = 0; i < G.size(); i++) {
            if (G[i].id == num) {
                G[i].print();
            }
        }
    }
    else if (field == "name"|| field == "lastName") {
        for (int i = 0; i < G.size(); i++) {
            if (G[i].name == str || G[i].lastName == str) {
                G[i].print();
            }
        }
    }
    else {
        cout << "Error";
    }
    
}

void sorting(vector<Group>& G, const string& field) {
    sort(G.begin(), G.end(), [&](const Group& a, const Group& b) {
        if (field == "id") return a.id < b.id;
        if (field == "age") return a.age < b.age;
        if (field == "name") return a.name < b.name;
        if (field == "lastName") return a.lastName < b.lastName;
        return false;
        });
}

int main()
{
    //1
    random_device rd;
    mt19937 gen(rd());
    vector<string> departures = { "Moscow (SVO)",  "London (LHR)","New York (JFK)","Paris (CDG)","Istanbul (IST)" };
    vector<string> destinations = { "Dubai (DXB)","Berlin (BER)","Tokyo (HND)","Rome (FCO)","Almaty (ALA)" };
    vector<string> registrations = { "Check-in A12","Check-in B7","Check-in C3","Check-in D18","Check-in E5" };
    uniform_int_distribution<> hoursDist(0, 23);
    uniform_int_distribution<> minutesDist(0, 50);
    uniform_int_distribution<> departureIndex(0, departures.size() - 1);
    uniform_int_distribution<> destinationIndex(0, destinations.size() - 1);
    uniform_int_distribution<> registrationIndex(0, registrations.size() - 1);
    vector<Aeroflot> Aerflots;
    char n = 'n';
    cout << "Create a random list? (y/n) ";
    cin >> n;
    if (n == 'y') {
        int h, m, size;
        cout << "Enter the number of elements: ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            h = hoursDist(gen);
            m = (minutesDist(gen) + 5) / 10 * 10;
            Aeroflot a;
            a.flightNumber = i + 1;
            a.departure = departures[departureIndex(gen)];
            a.destination = destinations[destinationIndex(gen)];
            a.arrivalTime.hours = h;
            a.arrivalTime.minutes = m;
            if (h == 23) {
                a.departureTime.hours = 0;
            }
            else {
                a.departureTime.hours = h + 1;
            }
            a.departureTime.minutes = m;
            a.registration = registrations[registrationIndex(gen)];
            Aerflots.push_back({ a });
        }
    }
    cout << "Create your list? (y/n) ";
    cin >> n;
    if (n == 'y') {
        Aeroflot a;
        string input;
        cout << "Input flight number: ";
        cin >> a.flightNumber;
        cout << "Input point of departure: ";
        cin >> a.departure;
        cout << "Input point of destination: ";
        cin >> a.destination;
        cout << "Input arrival time (22 10): ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, input);
        stringstream ss(input);
        ss >> a.arrivalTime.hours >> a.arrivalTime.minutes;
        cout << "Input departure time (23 10): ";
        getline(cin, input);
        stringstream ss1(input);
        ss1 >> a.departureTime.hours >> a.departureTime.minutes;
        cout << "Input point of registration: ";
        cin >> a.registration;
        Aerflots.push_back({ a });
    }
    sort(Aerflots.begin(), Aerflots.end(),
        [](const Aeroflot& a, const Aeroflot& b) {
            return a.destination < b.destination;
        });
    if (Aerflots.size() == 0) {
        cout << "There are no flights today, we apologize" << endl;
    }
    else {
        for (int i = 0; i < Aerflots.size(); i++) {
            Aerflots[i].print();
        }
    }

    //2
    vector<string> names = { "James","Michael","Robert","David","William","Emily","Sophia","Olivia","Isabella","Charlotte" };
    vector<string> lastNames = { "Smith","Johnson","Williams","Brown","Taylor","Anderson","Thomas","Jackson","White","Harris" };
    uniform_int_distribution<> agesDist(18, 25);
    uniform_int_distribution<> nameIndex(0, names.size() - 1);
    uniform_int_distribution<> lastNameIndex(0, lastNames.size() - 1);
    vector<Group> Group124;
    for (int i = 0; i < 30; i++) {
        Group G;
        G.name = names[nameIndex(gen)];
        G.lastName = lastNames[lastNameIndex(gen)];
        G.age = agesDist(gen);
        G.id = i + 1;
        Group124.push_back({ G });
    }
    n = 'n';
    short option;
    cout << "Open table? (y/n) ";
    cin >> n;
    while (n == 'y') {
        cout << endl;
        for (int i = 0; i < Group124.size(); i++) {
            Group124[i].print();
        }
        cout << "\nEnter 1 to search\nEnter 2 to sort\nEnter 3 to add\nEnter 4 to delete\n";
        cin >> option;
        string type;
        Group G;
        switch (option) {
        case 1:
            cout << "\nEnter the field you want to search by (age/id/name/lastName): ";
            cin >> type;
            if (type == "age") {
                int a;
                cout << "Enter type: ";
                cin >> a;
                find(a, "", Group124, type);
            }
            else if (type == "id") {
                int a;
                cout << "Enter type: ";
                cin >> a;
                find(a, "", Group124, type);
            }
            else if (type == "name" || type == "lastName") {
                string a;
                cout << "Enter type: ";
                cin >> a;
                find(0, a, Group124, type);
            }
            else {
                cout << "Error";
            }
            break;
        case 2:
            cout << "\nEnter the sort you want to sort by (age/id/name/lastName): ";
            cin >> type;
            sorting(Group124, type);
            cout << endl;
            break;
        case 3:
            cout << "\nEnter name: ";
            cin >> G.name;
            cout << "Enter last name: ";
            cin >> G.lastName;
            cout << "Enter age: ";
            cin >> G.age;
            G.id = Group124.size() + 1;
            Group124.push_back({ G });
            break;
        case 4:
            int index;
            cout << "\nEnter id you want to delete: ";
            cin >> index;
            if (index > 0 && index <= Group124.size()) {
                Group124.erase(Group124.begin() + index-1);
            }
            for (int i = 0; i < Group124.size(); i++) {
                Group124[i].id = i + 1;
            }
            break;
        default:
            cout << "\nWe dont have this option";
            break;
        }
        cout << "\nClose table? (y/n) ";
        cin >> n;
        if (n == 'y') { n = 'n'; }
        else if (n == 'n') { n = 'y'; };
    }

    //3
    string line;
    vector<int> trains;
    n = 'n';
    cout << "\n\nEnter trains by console (y/n): ";
    cin >> n;
    if (n == 'y') {
        cout << "Enter 0 or 1 separated by space: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            trains.push_back(num);
        }
    }else{
        cout << "\nEnter trains by file (y/n): ";
        cin >> n;
        if (n == 'y') {
            ifstream file("trains.txt");
            char ch;
            while (file.get(ch)) {
                if (ch == '0') trains.push_back(0);
                else if (ch == '1') trains.push_back(1);
            }
        }
    }
    int left = 0;
    for (int i = 0; i < trains.size(); i++) {
        left += trains[i];
    }
    cout << "Trains 0: " << (trains.size()-left) << endl;
    cout << "Trains 1: " << left << endl;
   
    
    return 0;
}

