///// C++20 (64) IS FASTER THAN C++11 (BUT SOMETIMES IT CAN CONSUME MORE MEMORY)

// Now some pragmas from https://www.geeksforgeeks.org/speed-up-naive-algorithms-in-competitive-coding-in-c-cpp/   :
// #pragma GCC optimize("O1")
// #pragma GCC optimize("O2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Os")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")           ///// THIS IS THE PRAGMA THAT OPTIMIZES A LOT
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// vectors & tuples:
#define pb push_back
#define V vector

int main(int argc, char *argv[]){ // ADDING THE ARGS PARAMETERS LIKE THIS IS SOMETIMES USED FOR OPTIMIZING THE TIME
	  clock_t start, end; 
    // Start clock 
    start = clock(); 
  /// TIME STARTED TO COUNT

  /// SOMETIMES IT'S BETTER TO DIRECTLY TYPE THE IOS COMMANDS LIKE THIS (AND NOT USING #DEFINE):
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  
  /// SOLVING PROBLEM HERE (CODE)
  ...

		// END TIMER
    end = clock(); 
 
    // Calculate the time difference 
    double time_taken 
        = double(end - start) 
        / double(CLOCKS_PER_SEC); 
 
    // Print the Calculated execution time 
    cout << "Execution time: " << time_taken /3.5 << " secs."; // good estimate in local computer: divide by some number in the range [3.0, 4.0]
 
	return 0;
}
