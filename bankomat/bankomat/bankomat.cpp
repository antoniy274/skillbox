#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int BILLS[] = { 100, 200, 500, 1000, 2000, 5000 };

void countAllBills(int bills[], int* billsCount) {
    for (int i = 0; i < 1000; ++i) {
        switch (bills[i]) {
        case 5000:
            billsCount[5]++;
            break;
        case 2000:
            billsCount[4]++;
            break;
        case 1000:
            billsCount[3]++;
            break;
        case 500:
            billsCount[2]++;
            break;
        case 200:
            billsCount[1]++;
            break;
        case 100:
            billsCount[0]++;
            break;
        }
    }
}

void billWithdrawal(int* bills, int count, int denomination) {
    for (int i = 0; i < count; ++i) {
        int j = 0;
        while (bills[j] != denomination) {
            ++j;
        }
        bills[j] = 0;
    }
}

bool isWithdrawalPossible(int sum, int* bills) {
    int billsCount[6];
    billsCount[5] = sum / 5000;
    sum %= 5000;
    billsCount[4] = sum / 2000;
    sum %= 2000;
    billsCount[3] = sum / 1000;
    sum %= 1000;
    billsCount[2] = sum / 500;
    sum %= 500;
    billsCount[1] = sum / 200;
    sum %= 200;
    billsCount[0] = sum / 100;
    sum %= 100;

    int billsInAtm[] = { 0, 0, 0, 0, 0, 0 };
    countAllBills(bills, billsInAtm);

    if (sum == 0) {
        if (billsCount[5] <= billsInAtm[5] && billsCount[4] <= billsInAtm[4] && billsCount[3] <= billsInAtm[3]
            && billsCount[2] <= billsInAtm[2] && billsCount[1] <= billsInAtm[1] && billsCount[0] <= billsInAtm[0]) {

            for (int i = 0; i < 6; ++i) {
                billWithdrawal(bills, billsCount[i], BILLS[i]);
            }
            return true;
        }
    }
    else {
        return false;
    }
}

int main() {
    ofstream atm_out("atm.txt", ios::app);
    ifstream atm_in("atm.txt", ios::binary);
    if (!atm_out.is_open() || !atm_in.is_open()) {
        cout << "Could not open the file\n";
        return 0;
    }
    char operation;
    cin >> operation;

    if (operation == '+') {
        srand(time(nullptr));
        string str;
        for (int i = 0; i < 1000; ++i) {
            atm_in >> str;
            if (atm_in.eof()) {
                atm_out << BILLS[rand() % 6] << "\n";
            }
        }
    }
    else if (operation == '-') {
        int billsInAtm[1000];

        for (int i = 0; !atm_in.eof(); ++i) {
            atm_in >> billsInAtm[i];
        }

        int withdrawal;
        cout << "Enter a withdrawal:" << endl;
        cin >> withdrawal;

        if (isWithdrawalPossible(withdrawal, billsInAtm)) {
            cout << "You withdrawn a " << withdrawal << " amount of money\n";
            atm_out.close();

            atm_out.open("atm.txt");
            if (!atm_out.is_open()) {
                cout << "Could not open the file\n";
                return 0;
            }
            for (int i = 0; i < 1000; ++i) {
                if (billsInAtm[i] == 0 || (billsInAtm[i] != BILLS[0] && billsInAtm[i] != BILLS[1]
                    && billsInAtm[i] != BILLS[2] && billsInAtm[i] != BILLS[3] && billsInAtm[i] != BILLS[4]
                    && billsInAtm[i] != BILLS[5])) {
                    continue;
                }
                atm_out << billsInAtm[i] << "\n";
            }
        }
        else {
            cout << "ATM cannot process this operation\n";
        }
    }
    atm_out.close();
    atm_in.close();
}