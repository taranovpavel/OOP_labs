#include <iostream>
#include <string>
#include <vector>
#include <random>
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


int main()
{
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
        while (n == 'y') {
            Aeroflot a;
            string input;
            cout << "Input flight number: ";
            cin >> a.flightNumber;
            cout << "Input point of departure: ";
            cin >> a.departure;
            cout << "Input point of destination: ";
            cin >> a.destination;
            cout << "Input arrival time (22 10): ";
            cin >> a.arrivalTime.hours >> a.arrivalTime.minutes;
            cout << "Input departure time (23 10): ";
            cin >> a.departureTime.hours >> a.departureTime.minutes;
            cout << "Input point of registration: ";
            cin >> a.registration;
            Aerflots.push_back({ a });
            cout << "Add another flight? (y/n) ";
            cin >> n;
        }
    }
    if (Aerflots.size() == 0) {
        cout << "There are no flights today, we apologize" << endl;
    }
    else {
        for (int i = 0; i < Aerflots.size(); i++) {
            sort(Aerflots.begin(), Aerflots.end(),
                [](const Aeroflot& a, const Aeroflot& b) {
                    return a.destination < b.destination;
                });
            Aerflots[i].print();
        }
    }
    return 0;
}