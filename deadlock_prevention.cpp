#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <condition_variable>
#include <random>
#include <algorithm>
using namespace std;
// Constants
constexpr int NUM_THREADS = 5;
constexpr int NUM_RESOURCES = 3;
constexpr int MAX_SLEEP = 500; // milliseconds
// Semaphore class
class Semaphore {
private:
    mutex mtx;
    condition_variable cv;
    int count;
public:
    Semaphore(int initialCount = 0) : count(initialCount) {}
    void notify() {
        lock_guard<mutex> lock(mtx);
        count++;
        cv.notify_one();
}
    void wait() {
        unique_lock<mutex> lock(mtx);
        while (count <= 0) {
cv.wait(lock);
}
count--; }
};
// Resource Manager class
class ResourceManager {
private:
    vector<bool> resources;
    mutex mtx;
public:
    ResourceManager() : resources(NUM_RESOURCES, false) {}
    int acquireResource() {
        lock_guard<mutex> lock(mtx);
        for (int i = 0; i < NUM_RESOURCES; ++i) {
            if (!resources[i]) {
                resources[i] = true;
                return i;
} }
        return -1; // No available resources
    }
    void releaseResource(int resourceIdx) {
        lock_guard<mutex> lock(mtx);
        resources[resourceIdx] = false;
} };
// Global variables
ResourceManager resourceManager;
Semaphore semaphore(NUM_RESOURCES);
mutex cout_mutex; // Declaration of cout_mutex
// Thread function
void threadFunction(int id) {
    while (true) {
        semaphore.wait(); // Wait until a resource is available
        int resourceIdx = resourceManager.acquireResource();
        if (resourceIdx != -1) {
                lock_guard<mutex> lock(cout_mutex); // Lock cout to ensure thread-safe output
             cout << "\033[1;32m[Thread " << id << "]\033[0m Acquired resource " << resourceIdx << endl;
}
            this_thread::sleep_for(chrono::milliseconds(rand() %MAX_SLEEP));
    // Release the resource
    resourceManager.releaseResource(resourceIdx);
    semaphore.notify(); // Notify that a resource is available
}
}
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "\n\033[1;36m========== Resource Management System ==========\033[0m" << endl<< endl;
    vector<thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(thread(threadFunction, i));
    }
    cout << "\033[1;36mThreads have been initialized.\033[0m" << endl<<
endl;
    for (auto& t : threads) {
        t.detach(); // Detach threads to allow them to run independently
}
    cout << "\033[1;36mMain thread sleeps to allow child threads to execute.\033[0m" << endl;
    cout <<
"\n\033[1;36m=================================================\033[0m" <<
endl;
    // Main thread sleeps to allow child threads to execute
    this_thread::sleep_for(chrono::seconds(10));
    return 0;
}