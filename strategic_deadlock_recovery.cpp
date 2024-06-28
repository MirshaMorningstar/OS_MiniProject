#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <atomic>
#include <condition_variable>
#include <random>
using namespace std;
// Constants
constexpr int NUM_THREADS = 5; // Updated to 5 threads
constexpr int NUM_RESOURCES = 3;
constexpr int MAX_SLEEP = 500; // milliseconds
constexpr int MAX_ITERATIONS = 10; // Terminate after 10 iterations
// Resource Manager class
class ResourceManager {
private:
mutex mtx;
condition_variable cv;
    vector<bool> resources;
public:
    ResourceManager() : resources(NUM_RESOURCES, false) {}
    bool requestResource(int threadId) {
        unique_lock<mutex> lock(mtx);
        for (int i = 0; i < NUM_RESOURCES; ++i) {
            if (!resources[i]) {
                resources[i] = true;
                cout << "\033[1;32mThread " << threadId << "\033[0m acquired resource " << i << endl;
                return true;
} }
        return false; // No available resources
    }
    void releaseResource(int resourceIdx) {
        lock_guard<mutex> lock(mtx);
        resources[resourceIdx] = false;
        cv.notify_all();
}
    bool isDeadlocked() const {
        // Simplified deadlock detection logic
        return false;
}
    void recoverFromDeadlock() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distr(0, NUM_RESOURCES - 1);
        for (int i = 0; i < NUM_RESOURCES / 2; ++i) {
            int resourceIdx = distr(gen);
            resources[resourceIdx] = false;
            cout << "\n\033[1;31mPreempted resource " << resourceIdx <<
            "\033[0m\n";
        }
} };
// Thread function
void threadFunction(int id, ResourceManager& resourceManager) {
    int iterations = 0;
    while (iterations < MAX_ITERATIONS) {
        if (resourceManager.requestResource(id)) {
            // Critical section
            this_thread::sleep_for(chrono::milliseconds(rand() %
MAX_SLEEP));
            resourceManager.releaseResource(rand() % NUM_RESOURCES);
            iterations++;
}
else {
            // Deadlock detected, initiate recovery mechanism
            cout << "\033[1;33mDeadlock detected by Thread " << id <<
"\033[0m\n";
            resourceManager.recoverFromDeadlock();
        }
} }
int main() {
    srand(time(nullptr));
    ResourceManager resourceManager;
    cout << "\033[1;36m========== Resource Management System ==========\033[0m\n\n";
    vector<thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(thread(threadFunction, i,
ref(resourceManager)));
}
    for (auto& t : threads) {
        t.join();
}
return 0;
}
