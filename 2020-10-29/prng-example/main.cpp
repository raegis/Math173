/*
   Example of a random number sequence
   There are two ingredients required:
     (1) a random source (or "engine") and
     (2) a probability distribution
*/

#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

int main()
{
   using namespace std::chrono;

   std::default_random_engine e; // random source
   std::uniform_int_distribution<int> u(0,1000); // uniform integers between 0 and 1000 inclusive
   // The next member of the sequence is u(e).

   std::vector<int> my_sequence(10000);
   for (int i=0; i<10000; i++) my_sequence[i] = u(e);

   for (int i: my_sequence) {
      std::cout << i << std::endl << std::flush;
      std::this_thread::sleep_for(300ms);
   }
}

