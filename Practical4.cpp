#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cards: ";
    cin >> n;

    int cards[50];  // assuming max 100 cards
    cout << "\nEnter the card values:\n";
    for (int i = 0; i < n; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> cards[i];
    }

    cout << "\nOrganizing Cards Using Insertion Sort:\n";

    // Insertion Sort logic
    for (int i = 1; i < n; i++) {
        int key = cards[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && cards[j] > key) {
            cards[j + 1] = cards[j];
            j--;
        }
        cards[j + 1] = key;

        cout << "\nAfter inserting card " << cards[i] << ": ";
        for (int k = 0; k <= i; k++) {
            cout << cards[k] << " ";
        }
        cout << "\n";
    }

    cout << "\nFinal Sorted Hand:\n";
    for (int i = 0; i < n; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;

    return 0;
}
