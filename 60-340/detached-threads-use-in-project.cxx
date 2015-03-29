#include <atomic>
#include <chrono>
#include <random>
#include <thread>
#include <future>
#include <ctime>
#include <iostream>
#include <exception>

using namespace std;

std::atomic<bool> threads_started{false};
std::atomic<unsigned> num_of_threads{0};

void a_task(char output_char, unsigned num_chars)
{
  static unsigned count = 1;

  // Use a scope to ensure that all local objects' destructors are called
  // when this scope closes. Before opening the scope, increment the atomic...
  ++num_of_threads;
  threads_started.store(true);

  {
    try
    {
      // Choose a random seed based on time...
      default_random_engine dre(time(nullptr)+count);
      uniform_int_distribution<unsigned> unidist(10, 750);
      
      // Increment count...
      ++count;
      
      // Output sleep a random amount of time then output_char.
      // Repeat num_chars times.
      for (unsigned i=0; i<num_chars; ++i)
      {
        this_thread::sleep_for(chrono::milliseconds(unidist(dre)));
        cout.put(output_char).flush();
      }
    }
    catch (exception const& e)
    {
      cerr 
        << "EXCEPTION in " << __func__
        << ", thread id = " << this_thread::get_id()
        << ", desc = " << e.what()
        << endl
      ;
      throw;
    }
    catch (...)
    {
      cerr
        << "EXCEPTION in " << __func__
        << ", thread id = " << this_thread::get_id()
        << endl
      ;
      throw;
    }
  }

  // Now that the scope has been closed, we can safely decrement the atomic...
  --num_of_threads;
}

int main()
{
  //
  // In C++ you must either .join() to wait for a thread to finish, or, you
  // must run it detached. The code below shows how to run the threads deteached.
  //
  // If you don't .join() or .detach() when the thread destructor is called
  // (assuming it has a running thread) the std::terminate() function will be
  // immediately called to abort the program. You must use .join() / .datach()!
  //
  // Know that if you detach() a thread and your program quits those threads
  // are immediately killed. If you want the program to stay running until
  // those threads are done then use a condition variable or an atomic.
  //
  // FYI, the number of cores on a computer is obtained by:
  //
  //   thread::hardware_concurrency()
  //
  // If you were creating threads in a loop (or in a web server) you don't want to
  // create too many threads. A good maximum number of threads is:
  //
  //   thread::hardware_concurrency()+1
  //
  // unless they do a lot of blocking (i.e., sleeping, waiting for I/O, etc.).
  //
  // If you limit your web server's number of threads you'll want to use atomic to 
  // do this. (There are other ways that are much better but this will work.) 
  // Simply have:
  //
  //   std::atomic<size_t> num_of_threads{0};
  //
  // and have this loop BEFORE you create the thread just after accept()ing the
  // network connection:
  //
  //  while(num_of_threads > thread::hardware_concurrency())
  //     std::this_thread::sleep_for(std::chrono::milliseconds(50));
  //
  try
  {
    thread task1(a_task, '.', 10);
    thread task2(a_task, '*', 10);
    thread task3(a_task, '@', 10);

    task1.detach();
    task2.detach();
    task3.detach();
   
    //
    // How do you wait until all detached threads have finished running?
    //
    // You need two variables to do this (min.):
    //   1) threads_started is whether or not any threads have started
    //   2) num_of_threads is the number of threads still running
    //

    // Wait until threads_started is set to true...
    while (!threads_started.load())
      std::this_thread::sleep_for(std::chrono::milliseconds(50));

    // Wait until all threads are done...
    while (num_of_threads.load() != 0)
      std::this_thread::sleep_for(std::chrono::milliseconds(50));

    // Output an end-of-line...
    cout << endl;
  }
  catch (exception const& e)
  {
    cerr
      << "EXCEPTION desc = " << e.what()
      << endl
    ;
  }
}
