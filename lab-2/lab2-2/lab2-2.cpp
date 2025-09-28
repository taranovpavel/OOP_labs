#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

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
void find(int num, string str, const vector<Group>& G, string field) {
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
    else if (field == "name" || field == "lastName") {
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
    random_device rd;
    mt19937 gen(rd());
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
    char n = 'n';
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
            cout << "\nEnter the field you want to sort by (age/id/name/lastName): ";
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
                Group124.erase(Group124.begin() + index - 1);
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
    return 0;
}

