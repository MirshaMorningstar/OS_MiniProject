#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
const int NUM_RESOURCES = 3;
const int NUM_PROCESSES = 5;
vector<int> available(NUM_RESOURCES);
vector<vector<int>> maximum(NUM_PROCESSES, vector<int>(NUM_RESOURCES));
vector<vector<int>> allocation(NUM_PROCESSES, vector<int>(NUM_RESOURCES));
vector<vector<int>> need(NUM_PROCESSES, vector<int>(NUM_RESOURCES));
vector<bool> resourceGranted(NUM_PROCESSES, false); // Flag to track if
mutex mtx;
bool isSafe(int processId) {
    vector<int> work = available;
    vector<bool> finish(NUM_PROCESSES, false);
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        work[i] -= allocation[processId][i];
        need[processId][i] = 0;
    }
    finish[processId] = true;
    bool canProceed = true;
    while (canProceed) {
        canProceed = false;
        for (int i = 0; i < NUM_PROCESSES; ++i) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < NUM_RESOURCES; ++j) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
} }
                if (canAllocate) {
                    canProceed = true;
                    finish[i] = true;
                    for (int j = 0; j < NUM_RESOURCES; ++j) {
                         work[j] += allocation[i][j];
                         need[i][j] = 0;
} 
}
} }
   
}
    return all_of(finish.begin(), finish.end(), [](bool b) { return b; });
}
void releaseResources(int processId) {

 lock_guard<mutex> lock(mtx);
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        available[i] += allocation[processId][i];
        allocation[processId][i] = 0;
        need[processId][i] = 0;
}
    resourceGranted[processId] = false; // Reset the flag when releasing
}
void requestResources(int processId, const vector<int>& request) {
    lock_guard<mutex> lock(mtx);
    if (resourceGranted[processId]) {
        cout << "\033[1;32mProcess " << processId << " has already been granted resources\033[0m\n";
return; }
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        if (request[i] > need[processId][i] || request[i] > available[i]) {
            cout << "\033[1;33mProcess " << processId << " is waiting...\033[0m\n";
return; }
}
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        available[i] -= request[i];
        allocation[processId][i] += request[i];
        need[processId][i] -= request[i];
}
    if (isSafe(processId)) {
        cout << "\033[1;32mProcess " << processId << " has been granted resources\033[0m\n";
        resourceGranted[processId] = true; // Set the flag when resources
}
else {
        cout << "\033[1;31mProcess " << processId << " must wait, deadlock might occur\033[0m\n";
        // Rollback resources
        for (int i = 0; i < NUM_RESOURCES; ++i) {
            available[i] += request[i];
            allocation[processId][i] -= request[i];
            need[processId][i] += request[i];

        }
    }
}
void processThread(int processId)
 {
    vector<int> request(NUM_RESOURCES);
    while (true) {
        for (int i = 0; i < NUM_RESOURCES; ++i) {
            request[i] = rand() % (maximum[processId][i] -
allocation[processId][i] + 1);
        }
        requestResources(processId, request);
        // Skip further requests if resources have been granted
        if (resourceGranted[processId]) {
            return;
}
        this_thread::sleep_for(chrono::milliseconds(2000));
        releaseResources(processId);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
int main() {
    // Initialize available resources
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        cout << "\033[1;34mEnter available instances of resource " << i <<
": \033[0m";
        cin >> available[i];
    }
    // Initialize maximum resources for each process
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        cout << "\033[1;34mEnter maximum instances of resource for process" << i << ":\033[0m\n";
        for (int j = 0; j < NUM_RESOURCES; ++j) {
cout << "\033[1;34mResource " << j << ": \033[0m";
 cin >> maximum[i][j];
            need[i][j] = maximum[i][j];
        }
}
    vector<thread> threads;
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        threads.emplace_back(processThread, i);
    }
    for (auto& t : threads) {
        t.join();
}
return 0; }