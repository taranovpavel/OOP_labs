#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    string line;
    vector<int> trains;
    char n = 'n';
    cout << "Enter trains by console (y/n): ";
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
    }
    else {
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
    int left = 0, right = 0;
    for (int i = 0; i < trains.size(); i++) {
        switch (trains[i])
        {
            case 0:
                right++;
			    break;
            case 1:
				left++;
                break;
			default:
                break;
        }
    }
    cout << "Trains 1 (left): " << left << endl;
    cout << "Trains 0 (right): " << right<< endl;


    return 0;
}

