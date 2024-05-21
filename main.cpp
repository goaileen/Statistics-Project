//
//  main.cpp
//  p1-stats
// Project UID 5366c7e2b77742d5b2142097e51561a5
//

#include "stats.h"
//#include "stats.cpp"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    string filename;
    string columnName;
    
    cout << "enter a filename" << endl;
    cin >> filename;
    cout << "enter a column name" << endl;
    cin >> columnName;
    cout << "reading column " << columnName << " from " << filename << endl;
    
    vector<double> wow= extract_column(filename, columnName);
    
    cout << "Summary (value: frequency)" << endl;
    vector<vector<double> > summary=summarize(wow);

    for (size_t i=0; i < summary.size(); ++i) {
        cout << summary[i][0] << ": " << summary[i][1] << endl;
    }
//    for (size_t i = 0; i < extract_column(filename, columnName).size(); ++i) {
//        for (size_t j = 1; j < extract_column(filename, columnName).size(); ++j) {
//            cout << summarize(extract_column(filename, columnName))[i][0] << ": " << summarize(extract_column(filename, columnName)[0][j] << endl; }
                                                                                              
                              
    cout << endl;
    cout << "count = " << count(wow) << endl;
    cout << "sum = " << sum(wow) << endl;
    cout << "mean = " << mean(wow) << endl;
    cout << "stdev = " << stdev(wow) << endl;
    cout << "median = " << median(wow) << endl;
    cout << "mode = " << mode(wow) << endl;
    cout << "min = " << min(wow) << endl;
    cout << "max = " << max(wow) << endl;
    
    cout << "  0th percentile = " << percentile(wow, 0.0) << endl;
    cout << " 25th percentile = " << percentile(wow, 0.25) << endl;
    cout << " 50th percentile = " << percentile(wow, 0.50) << endl;
    cout << " 75th percentile = " << percentile(wow, 0.75) << endl;
    cout << "100th percentile = " << percentile(wow, 1.0) << endl;
    
}
