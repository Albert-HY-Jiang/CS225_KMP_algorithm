/**

 * Implements a 'blackbox' algorithm

 */

#include "KMPsearch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h> 

using namespace std;
KMPsearch::KMPsearch(std::string dataset, std::string pattern)
{
  dataset_.assign(dataset.begin(), dataset.end());
  pattern_.assign(pattern.begin(), pattern.end());
  lps = makeLPS();
}

KMPsearch::KMPsearch(string fileName) {
    std::ifstream inputFile(fileName); 
    std::string pattern;
    std::getline(inputFile, pattern);
    std::string data((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
    
    inputFile.close();
    dataset_.assign(data.begin(), data.end());
    if (pattern.length() > 0) {
         pattern_.assign(pattern.begin(), pattern.end());
        lps = makeLPS();
    }
    
}


void KMPsearch::setPattern(std::string pattern) {
    pattern_.assign(pattern.begin(), pattern.end());
    KMPcount = 0;
    naiveCount = 0;
    lps = makeLPS();
}


void KMPsearch::setData(std::string dataset) {
    dataset_.assign(dataset.begin(), dataset.end());
}


vector<char> KMPsearch::getPattern() {
    return pattern_;
}


vector<char> KMPsearch::getData(){
    return dataset_;
}


vector<size_t> KMPsearch::search() {
    vector<size_t> result;
    unsigned dataPos= 0;
    unsigned patternPos = 0;
    while (dataset_.size() - dataPos >= pattern_.size() - patternPos) { //if remaining charCount less than pattern length impossible to have match
        KMPcount ++;
        if (pattern_[patternPos] == dataset_[dataPos]) { //character matches
            dataPos ++;
            patternPos++;
            if (patternPos == pattern_.size()) { //if patternPos is at end of pattern then match found
                result.push_back(dataPos - patternPos); 
                patternPos = lps[patternPos - 1];
            }
        }
        else {
            if (patternPos != 0) {
                patternPos = lps[patternPos-1]; //go to last matching position
            }
            else {
                dataPos = dataPos + 1; //no matches pattern at beginning and restart
            }
        }



    }
    return result;
}
unsigned KMPsearch::getNaiveComp() {
    return naiveCount;
}
unsigned KMPsearch::getKMPComp() {
    return KMPcount;
}

vector<size_t> KMPsearch::naiveSearch() {
    vector<size_t> result;
    bool match = true;
    if (pattern_.size() > dataset_.size()) {
        return result;
    }
    for (unsigned i =0; i <= dataset_.size() - pattern_.size(); i++) {
        match = true;
        for (unsigned j =0; j < pattern_.size(); j++) {
            // cout << "dataset_: " << (dataset_[i+j]);
            naiveCount ++;
            if (dataset_[i+j] != pattern_[j]) {
                
                match = false;
                break;
            }
        }
        if (match) {
            result.push_back(i);
        }
    }
    return result;
    // return vector<size_t>();
}


vector<size_t> KMPsearch::makeLPS() {
    unsigned len = 0; //length of the prefix to be found (to be put into lps)
    lps.resize(pattern_.size());  
    lps[0] = 0; //lps[0] is always 0
    unsigned pos= 1; //current position in pattern
    while (pos < pattern_.size()) { //while not at end of pattern
        KMPcount ++; 
        if (pattern_[pos] == pattern_[len]) { //prefix matches suffix
            len ++; //increase length of prefix
            lps[pos] = len; 
            pos++;
        }
        else {
            if (len != 0) {
                len = lps[len-1]; //revert length to last match
                // position is not updated!!
            }
            else { //if at index 0 then nothing left to compare
                lps[pos] = 0; 
                pos++;
            }
        }
    }
    return lps;
}

string KMPsearch::getRandomString(int n, int start, int end){
    string res ="";

    for(int i = 0; i < n; i++){
        char c = rand() % (end - start + 1) + start;
        res += c;
    }
    
    return res;
}
