#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
 
boost::mutex mutex1, mutex2, mutex3;
 
void ThreadA()
{
    // Creates deadlock problem
    mutex2.lock();
    std::cout << "Thread A" << std::endl;
    mutex1.lock();
    mutex3.lock();
    mutex2.unlock();
    mutex1.unlock();
    mutex3.unlock();
}
 
void ThreadB()
{
    // Creates deadlock problem
    mutex3.lock();
    mutex1.lock();
    std::cout << "Thread B" << std::endl;
    mutex2.lock();
    mutex1.unlock();
    mutex3.unlock();
    mutex2.unlock();
}

void ThreadC()
{
    // Creates deadlock problem
    mutex1.lock();
    mutex3.lock();
    std::cout << "Thread B" << std::endl;
    mutex2.lock();
    mutex3.unlock();
    mutex1.unlock();
    mutex2.unlock();
}
void ExecuteThreads()
{
    boost::thread t1( ThreadA );
    boost::thread t2( ThreadB );
    boost::thread t3( ThreadC );
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Finished" << std::endl;
}
 
int main()
{
    ExecuteThreads();
 
    return 0;
}
