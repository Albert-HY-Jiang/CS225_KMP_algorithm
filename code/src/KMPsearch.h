/**
 * @file letter.h
 * Declaration of the Letter class.
 */

#pragma once

#include <string>
#include <vector>


class KMPsearch
{

    private:
        std::vector<char> pattern_;
        std::vector<char> dataset_;
        std::vector<size_t> lps;
        unsigned KMPcount;
        unsigned naiveCount;
    
    public:
        /**
        * Constructor to initialize dataset and pattern from string
        * @param dataset the dataset to be searched. 
        * @param pattern the pattern to search for.
        */
        KMPsearch(std::string dataset, std::string pattern);

        /**
        * Loads an input txt file and initializes pattern and data vectors
        * @param fileName The absolute path to the txt containing the input text. The first line is the pattern and rest of file is data
        */
        KMPsearch(std::string fileName);
        /**
        * Set the pattern being searched for
        * For testing purposes
        * @param pattern a string that we want to search for 
        */
        /**
        * convert string to vector
        */
        std::vector<char> convertData(std::string s);

        void setPattern(std::string pattern);
        /**
        * Set the data being searched for
        * For testing purposes
        * @param data a string that we want to search through
        */
        void setData(std::string data);
        /**
        * Get the pattern being searched for
        * For testing purposes
        * @return pattern 
        */
        std::vector<char> getPattern();
        /**
        * Get the data being searched through
        * For testing purposes
        * @return data 
        */
        std::vector<char> getData();

        unsigned getNaiveComp();
        unsigned getKMPComp();
        /**
        * Search using KMP algorithm for pattern in data and store index in vector.
        * @return vector of indexes where pattern occurs in data
        */
        std::vector<size_t> search();

        /**
         *Naive search to compare the efficiency to KMP search
        */
        std::vector<size_t> naiveSearch();
        /**
        * Make the LPS vector of lengths of the longest prefix that is also a suffix
        */
        std::vector<size_t> makeLPS();

        /**
         * Generate random string with given length
         * @param n The length of the string
         * @param start The start of the range of characters
         * @param end The end of the range
        */
       std::string getRandomString(int n, int start, int end);

};
