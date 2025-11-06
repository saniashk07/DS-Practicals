#include <iostream> #include <string> using namespace std;

class LoadBalancer {
int n_servers;	// number of servers
int hash_num[100];		// numeric request IDs (0 = empty) string hash_ip[100];	// string request IPs ("" = empty)

public:
// Constructor LoadBalancer(int n) {
n_servers = n;
for (int i = 0; i < n_servers; i++) { hash_num[i] = 0;
hash_ip[i] = "";
}
}
 
// Hash function for numbers int hashFunction(int val) {
return val % n_servers;
}

// Hash function for IPs (sum of numbers between dots) int hashFunction(string ip) {
int sum = 0, num = 0; for (char c : ip) {
if (c == '.') {
sum += num; num = 0;
} else {
num = num * 10 + (c - '0');
}
}
sum += num; // add last part return sum % n_servers;
}

// Insert numeric request using linear probing void insert(int val) {
int idx = hashFunction(val); int start = idx;

while (hash_num[idx] != 0) { // find empty slot idx = (idx + 1) % n_servers;
if (idx == start) return; // table full
}

hash_num[idx] = val;
cout << "Request " << val << " is handled by Server " << idx + 1 << endl;
}

// Insert IP request using linear probing void insert(string ip) {
int idx = hashFunction(ip); int start = idx;
 
while (hash_ip[idx] != "") { // find empty slot idx = (idx + 1) % n_servers;
if (idx == start) return; // table full
}

hash_ip[idx] = ip;
cout << "Request " << ip << " is handled by Server " << idx + 1 << endl;
}

// Display summary void display() {
cout << "\nServer Load Summary:\n"; for (int i = 0; i < n_servers; i++) {
cout << "Server " << i + 1 << " <- ";
if (hash_num[i] != 0) cout << hash_num[i]; if (hash_ip[i] != "") cout << hash_ip[i];
if (hash_num[i] == 0 && hash_ip[i] == "") cout << "<empty>"; cout << endl;
}
}
};

int main() {
int n, r, choice;
cout << "Enter number of servers: "; cin >> n;

cout << "Enter number of requests: "; cin >> r;

LoadBalancer lb(n);

cout << "Choose input type (1 = IDs, 2 = IPs): "; cin >> choice;

if (choice == 1) {
for (int i = 0; i < r; i++) { int id;
cout << "Request " << i + 1 << " ID: "; cin >> id;
 
lb.insert(id);
}
} else if (choice == 2) {
for (int i = 0; i < r; i++) { string ip;
cout << "Request " << i + 1 << " IP: "; cin >> ip;
lb.insert(ip);
}
}

lb.display(); return 0;
}


