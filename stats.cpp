//
//  stats.cpp
//  p1-stats
// Project UID 5366c7e2b77742d5b2142097e51561a5
//
//

#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
    sort(v);
    vector<vector<double> > dataset;
    double value = 0;
    double frequency = 1;
    
    for (size_t i = 0; i < v.size(); ++i) {
        vector<double> pair;
        value = v[i];
        
        if (i != v.size() - 1 && v[i] == v[i+1]) {
            ++frequency;
        }else if (i != v.size() - 1 && v[i] != v[i+1]) {
            pair.push_back(value);
            pair.push_back(frequency);
            dataset.push_back(pair);
            
            frequency = 1;
        }else if (i == v.size()-1){
            pair.push_back(value);
            pair.push_back(frequency);
            dataset.push_back(pair);
        }
            
    }
        return dataset;
    }

int count(vector<double> v) {
    double count = v.size();
    return count;
}

double sum(vector<double> v) {
    double total = 0;
      for (size_t i = 0; i < v.size(); ++i) {
        total += v[i];
      }
      return total;
}


double mean(vector<double> v) {
    double sum = 0;
    for (size_t i = 0; i < v.size(); i += 1) {
        sum += v[i];
      }
    double mean = sum / v.size();
    return mean;
}

double median(vector<double> v) {
    double median = 0;
    sort(v);
    if (v.size() % 2 == 0) {
        median = v[v.size() / 2];
    }
    else {
        median = v[(ceil(v.size() / 2))];
    }
    return median;
}

double mode(vector<double> v) {
    sort(v);
    vector<vector<double> > dataset = summarize(v);
    double mode = dataset[0][0];
    double num = dataset[0][1];
    
    for (size_t i = 0; i < dataset.size() - 1; i++) {
        if (dataset[i+1][1] > num) {
            mode = dataset[i + 1][0];
            num = dataset[i + 1][1];
        }
        
    }
    return mode;
}

double min(vector<double> v) {
    sort(v);
    double min = v[0];
    return min;
}

double max(vector<double> v) {
    sort(v);
    double max = v[v.size() - 1];
    return max;
}

double stdev(vector<double> v) {
    double total = 0;
    double stdev = 0;
    for (size_t i = 0; i < v.size(); i++) {
        total += pow(v[i] - mean(v), 2);
    }
    stdev = sqrt (total / (count(v) - 1));
    return stdev;
}

double percentile(vector<double> v, double p) {
    double percentile = 0;
    double fractpart = 0;
    double intpart = 0;
    double rank = 0;
    sort(v);
    if (v.size() == 1 || p == 0) {
        percentile = min(v);
    }
    else if (p == 1) {
        percentile = max(v);
    }
    else {
    rank = p * (v.size() - 1);
    fractpart = modf(rank, &intpart);
    percentile = v[intpart] + ( fractpart * (v[intpart + 1] - v[intpart]) );
    }
    
    return percentile;
}
