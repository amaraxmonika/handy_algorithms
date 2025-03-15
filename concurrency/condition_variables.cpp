#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>
 
std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv

int global_count = 1;

void odd() {
    std::unique_lock<std::mutex> lk(cv_m);
    while (global_count < 10) {
        cv.wait(lk, []{ return global_count % 2 != 0; });
        printf("%d", global_count);
        global_count++;
    }
}

void even() {
    std::unique_lock<std::mutex> lk(cv_m);
    while (global_count < 10) {
        cv.wait(lk, []{ return global_count % 2 == 0; });
        printf("%d", global_count);
        global_count++;
    }
}
 
void signals() {
    while (global_count < 10) {
        std::cout << "a";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cv.notify_all();
    }
}
 
int main() {
    std::thread t3(signals), t1(even), t2(odd);
    t3.join();
    t1.join(); 
    t2.join(); 
}
