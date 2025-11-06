#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of players: ";
    cin >> n;

    int player[20];
    cout << "Enter the scores for players:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Score " << i + 1 << ": ";
        cin >> player[i];
    }

    cout << "\nStarting Level-Up Process (Bubble Sort)...\n";

    for (int i = 0; i < n - 1; i++) {
        cout << "\nLevel " << i + 1 << ":\n";
        for (int j = 0; j < n - i - 1; j++) {
            if (player[j] > player[j + 1]) {
                cout << "Swapping score " << player[j]
                     << " with " << player[j + 1]
                     << " - Leveling up!\n";
                int temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
        }
    }

    cout << "\nLevel Complete! Final Sorted Scores:\n";
    for (int i = 0; i < n; i++) {
        cout << "Score " << i + 1 << ": " << player[i] << endl;
    }

    return 0;
}
