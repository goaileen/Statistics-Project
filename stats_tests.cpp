/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// Precision for floating point comparison
const double epsilon = 0.00001;

void test_summarize();
void test_sum_small_data_set();
void test_count();
void test_mean();
void test_median();
void test_mode();
void test_min();
void test_max();
void test_stdev();
void test_percentile();

int main() {
    test_summarize();
    test_sum_small_data_set();
    test_count();
    test_mean();
    test_median();
    test_mode();
    test_min();
    test_max();
    test_stdev();
    test_percentile();
}
void test_summarize() {
    cout << "test_summarize" << endl;
    vector<double> dataset = {0, 2, 15, 2, 15, 1};
    vector<vector<double>> correct{{0,1},{1,1}, {2,2}, {15,2}};
    assert(summarize(dataset) == correct);

    vector<double> dataset1 = {0};
    vector<vector<double>> correct1{{0,1}};
    assert(summarize(dataset1) == correct1);

    vector<double> dataset2 = {-5,-4,-4};
    vector<vector<double>> correct2{{-5, 1}, {-4, 2}};
    assert(summarize(dataset2) == correct2);

    vector<double> dataset3 = {-5, -5, -5};
    vector<vector<double>> correct3{{-5,3}};
    assert(summarize(dataset3) == correct3);
    
    cout << "PASS!" << endl;

}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);
    
    vector<double> data2;
    data2.push_back(-4);
    data2.push_back(0);
    
    assert(sum(data2) == -4);
    
    vector<double> data3;
    data3.push_back(7);
    data3.push_back(19);
    data3.push_back(-4);
    data3.push_back(-14);
    
    assert(sum(data3) == 8);
    
    vector<double> data4;
    data4.push_back(0);
    
    assert(sum(data4) == 0);
    
  cout << "PASS!" << endl;
    
}

void test_count(){
    cout << "test_count" << endl;
    assert(count({1, 2, 3, 4, 5}) == 5);
    assert(count({-5, -2, 3}) == 3);
    assert(count({-2}) == 1);
    
    cout << "PASS!" << endl;
}

void test_mean(){
    cout << "test_mean" << endl;
    assert(mean({1, 2, 9}) == 4);
    assert(mean({-2, -3, -7, -4}) == -4);
    assert(mean({0, 2, -2,}) == 0);
    
    cout << "PASS!" << endl;
    
}
void test_median(){
    cout << "test_median" << endl;
    assert(median({-3, 7, 0, 9, 1}) == 1);
    assert(median({2, 0, -2}) == 0);
    assert(median({-5, -9, -2, -3}) == -3);
    assert(median({10}) == 10);
    
    cout << "PASS!" << endl;
    
}
void test_mode(){
    cout << "test_mode" << endl;
    assert(mode({1, 2, 3, 2}) == 2);
    assert(mode({3}) == 3);
    assert(mode({1, 2, 1, 2}) == 1);
    assert(mode({-1, 2, 1, -1}) == -1);
    assert(mode({0, 4}) == 0);
    
    cout << "PASS!" << endl;
    
}
void test_min(){
    cout << "test_min" << endl;
    assert(min({-2, 0, 4, 1}) == -2);
    assert(min({10, 0, 7, 3}) == 0);
    assert(min({5, 12, 8, 10}) == 5);
    
    cout << "PASS!" << endl;
    
}
void test_max(){
    cout << "test_max" << endl;
    assert(max({-2, -3, -1,}) == -1);
    assert(max({-4, 0, 5, 8}) == 8);
    assert(max({-5, 0}) == 0);
    cout << "PASS!" << endl;
    
}
void test_stdev(){
    cout << "test_stdev" << endl;
    vector<double> v = {5, 3, 2, 6, 1};
    double answer = 2.0736441353328;
    assert(abs(stdev(v) - answer) < 0.0001);
    cout << "PASS!" << endl;
    
}
void test_percentile(){
    cout << "test_percentile" << endl;
    assert(percentile({10, 4, 0, 7, 15}, 1) == 15);
    assert(percentile({3}, 0.75) == 3);
    assert(percentile({3, 9, 4}, 0) == 3);
    assert(percentile({1, 4, -2, 0, -4}, .25) == -2);
    assert(percentile({5, 2, 0, 5}, 0.5) == 3.5);
    assert(percentile({12, 2}, .25) == 4.5);
    cout << "PASS!" << endl;
    
}
