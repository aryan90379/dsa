#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <future>
#include <algorithm>

using namespace std;

// ==========================================
// 1. CP JUDGE UTILITIES
// ==========================================
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string CYAN = "\033[1;36m";
const string RESET = "\033[0m";

class Timer {
    using Clock = chrono::high_resolution_clock;
    chrono::time_point<Clock> start_time;
public:
    Timer() : start_time(Clock::now()) {}
    double elapsed_ms() const {
        return chrono::duration<double, milli>(Clock::now() - start_time).count();
    }
};

string arrayToString(const vector<int>& arr) {
    if (arr.empty()) return "[]";
    string s = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        s += to_string(arr[i]);
        if (i < arr.size() - 1) s += ", ";
        if (s.length() > 50 && i < arr.size() - 2) { 
            s += "... (" + to_string(arr.size() - i - 1) + " more)]";
            return s;
        }
    }
    s += "]";
    return s;
}

// ==========================================
// 2. USER CODE
// ==========================================
class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = i-1;j>=0;j--)
            {
                if(nums[j]>nums[i]) 
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return nums; 
    }
};

// ==========================================
// 3. TEST RUNNER
// ==========================================
void runTestCase(int testNum, const string& testName, const vector<int>& nums, const vector<int>& expected) {
    Solution sol;
    
    // Create a local copy to ensure we don't mutate the original test suite data 
    // before passing it to the user's function
    vector<int> nums_copy = nums;
    
    cout << "Test " << setw(2) << left << testNum << " | " 
         << setw(35) << left << testName << " | ";
         
    Timer timer;
    vector<int> actual;
    
    // Using async to catch potential infinite loops (Timeouts)
    auto future = async(launch::async, [&]() { return sol.insertionSort(nums_copy); });
    
    if (future.wait_for(chrono::milliseconds(2000)) == future_status::timeout) {
        cout << YELLOW << "[TLE] " << RESET << "Time Limit Exceeded (>2000ms)\n";
    } else {
        try {
            actual = future.get();
            double time_taken = timer.elapsed_ms();
            
            if (actual == expected) {
                cout << GREEN << "[PASS] " << RESET 
                     << "Time: " << fixed << setprecision(3) << time_taken << " ms\n";
            } else {
                cout << RED << "[FAIL] " << RESET << "\n"
                     << "           Expected: " << arrayToString(expected) << "\n"
                     << "           Got:      " << arrayToString(actual) << "\n";
            }
        } catch (...) {
            cout << RED << "[RE]   " << RESET << "Runtime Error (Crash or Out of Bounds)\n";
        }
    }
}

// ==========================================
// 4. MAIN EXECUTION
// ==========================================
int main() {
    struct TestCase {
        string name;
        vector<int> input;
        vector<int> expected;
    };

    vector<TestCase> testCases = {
        {"Example 1", {7, 4, 1, 5, 3}, {1, 3, 4, 5, 7}},
        {"Example 2 (Duplicates)", {5, 4, 4, 1, 1}, {1, 1, 4, 4, 5}},
        {"Now your turn!", {3, 2, 3, 4, 5}, {2, 3, 3, 4, 5}},
        {"Already sorted", {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
        {"Reverse sorted", {9, 8, 7, 6, 5}, {5, 6, 7, 8, 9}},
        {"Single element", {42}, {42}},
        {"Empty array", {}, {}},
        {"All identical elements", {7, 7, 7, 7}, {7, 7, 7, 7}},
        {"Negative numbers", {-5, 2, -10, 0, 1}, {-10, -5, 0, 1, 2}}
    };

    // TC 10: Stress Test (2000 elements, Reverse Sorted)
    // Insertion Sort is O(N^2) in the worst case (reverse sorted).
    // 2000 elements is large enough to test efficiency without guaranteeing a TLE 
    // on slower machines (unlike 10^5 which would definitely TLE for insertion sort).
    vector<int> largeArray, largeExpected;
    for(int i = 2000; i >= 1; --i) {
        largeArray.push_back(i);
        largeExpected.push_back(2001 - i); 
    }
    testCases.push_back({"Stress Test (N=2000, Worst Case)", largeArray, largeExpected});

    cout << CYAN << "\n=========================================================\n";
    cout << "                  STARTING TEST SUITE                    \n";
    cout << "=========================================================\n" << RESET;

    for (size_t i = 0; i < testCases.size(); ++i) {
        runTestCase(i + 1, testCases[i].name, testCases[i].input, testCases[i].expected);
    }
    
    cout << CYAN << "=========================================================\n\n" << RESET;

    return 0;
}