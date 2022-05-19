#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <thread>
#include <queue>
#include <mutex>
#include <sstream>
#include <atomic>
#include <chrono>
#include <condition_variable>
using namespace std;

/**
 * @brief Producer and Consumer problem
 * A / Some thread(s) prepare the data which play as the Producer,
 * there are numbers of consumer threads would process the generated data
 * --------------------------------------
 * Approach
 * 1. normal approach -> race condition
 * 2. adding mutex -> busy wait
 * 3. adding thread sleep -> uncertain to determine the sleeping time
 * 4. condition variable
*/

#define TOTAL_CONSUMER 5
#define TOTAL_MESSAGE 50


queue<int> messages;
atomic<int> counter = 0;
condition_variable cv;

mutex printMtx;
void print(ostream& os)
{
    lock_guard<mutex> lock(printMtx);
    cout << os.rdbuf();
}

mutex mtx;
void produce()
{
    for (int i = 0; i < TOTAL_MESSAGE; i++)
    {
        // prepare the data
        unique_lock<mutex> lock(mtx);
        messages.push(i);
        lock.unlock();
        
        // notify to the consumers that new message was generated
        cv.notify_one();
    }
    
}
void consume()
{
    while (counter < TOTAL_MESSAGE) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, []{ return !messages.empty(); });

        auto message = messages.front();
        messages.pop();
        lk.unlock();

        counter++;

        // process the message
        stringstream os;
        os << "[" << this_thread::get_id() <<"] " << "consume: " << message <<", counter: " << counter.load() << '\n';
        print(os);
    }
    
}

int main()
{
    queue<int> q;
    thread producer(produce);
    vector<thread> consumers;
    for (int i = 0; i < TOTAL_CONSUMER; i++)
    {
        consumers.emplace_back(consume);
    }
    
    for (auto &consumer : consumers)
    {
        consumer.join();
    }
    producer.join();
}