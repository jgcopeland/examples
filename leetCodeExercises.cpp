#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique
 
// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.


// Example 2:

// Input: gas = [2,3,4], cost = [3,4,3]
// Output: -1
// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
// Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 0. Your tank = 4 - 3 + 2 = 3
// Travel to station 1. Your tank = 3 - 3 + 3 = 3
// You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
// Therefore, you can't travel around the circuit once no matter where you start.
 

// Constraints:

// n == gas.length == cost.length
// 1 <= n <= 105
// 0 <= gas[i], cost[i] <= 104

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //assume constraints are met on input (equal length vectors mainly)
    //check if can travel to next station, starting from 0 (0 to 1, 1 to 2, 2 to 3,...)
    //once can, check if can make it to next after that starting (if start and go 1 to 2, check 2 to 3)
    //if cannot make second trip, check next first trip and repeat
    //continue checking next trips until end of circuit or last start point has been checked

    for(int i = 0; i<gas.size(); i++) { //for each potential start station 0 -> n-1
        int tank = gas[i]; //gas tank starts at empty
        int visited = 1; //track stations visited during route
        for(int j = i; visited != gas.size(); j++) {
            if(tank<cost[j%gas.size()]) {
                cout << "Cannot travel from station " << j << " to station " << j+1 << ".\n";
                cout << "Starting from station " << i << " is not a viable route.\n";
                break;
            }
            else {
                tank -= cost[j];
                cout << "Travelled from station " << j << " to station " << j+1 << ".\n";
            }
        }
        if(visited == gas.size()) {
            return i;
        }
    }
    return -1;
}

int main() {
    //LeetCode Exercises
    //134. Gas Station
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    canCompleteCircuit(vector<int>& gas, vector<int>& cost);
    
    
    return 0;
}