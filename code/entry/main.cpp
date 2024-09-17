/**
 * @file main.cpp
 * A fake 'run-script' to get time estimates for implemented algorithms
 * For other approaches to time your code (for benchmarking) see:
 * https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>
#include <cmath>

#include "KMPsearch.h"
/**
 * Main routine.
 * Reads in a specified dataset and outputs the time to do 'algorithm' on it
 */
int main()
{
    //Use a txt file to load your data. The first line of the file will be the pattern, and the rest data
    // string infile = "../../data/output_file_1.txt"; //replace with path to your data
    // KMPsearch res = KMPsearch(infile);

    //or set the pattern and data with strings
    std::string pattern = "pattern"; //replace with pattern you want to find in dataset
    std::string dataset = "data"; //replace with data you want to search through
    KMPsearch res = KMPsearch(dataset, pattern);
    std::vector<size_t> out = res.search();
    
    //Change the pattern or data after creating the object
    // res.setPattern("newPattern"); 
    // res.setData("newData");


    std::cout << "The pattern is at: ";
    for (unsigned i = 0; i < out.size(); i++) {
        std::cout << out[i] << " ";
    }
    std::cout << std::endl;
    res.naiveSearch();
    // See the number of comparisons the two algorithms use
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;

}
