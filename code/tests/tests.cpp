#include <catch2/catch_test_macros.hpp>

#include "KMPsearch.h"

#include <sstream>
#include <iostream>
using namespace std;

/**
 * test lps array for simple string
*/
TEST_CASE("test lps1", "[weight=5]")
{
    string pattern = "ABCDE";
    string dataset = "";
    KMPsearch res = KMPsearch(dataset, pattern);
    vector<size_t> lps = res.makeLPS();
    vector<size_t> expected = {0, 0, 0, 0, 0};
    cout << "LPS1 comparisons: " << res.getKMPComp() << endl;
    REQUIRE(expected == lps);
}

/**
 * test lps array for simple string
*/
TEST_CASE("test lps2", "[weight=5]")
{
    string pattern = "AABAACAABAA";
    string dataset = "";
    KMPsearch res = KMPsearch(dataset, pattern);
    vector<size_t> lps = res.makeLPS();
    vector<size_t> expected = {0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5};
    cout << "LPS2 comparisons: " << res.getKMPComp() << endl;
    REQUIRE(expected == lps);
}



/**
 * search for a simple pattern in short string
 */
TEST_CASE("Simple testcase 1", "[weight=5]")
{
    string pattern = "ABC";
    string dataset = "ABCuhluhu";

	vector<size_t> expected = {0};
    KMPsearch res = KMPsearch(dataset, pattern);
    vector<size_t> out = res.search();
    cout << "Simple testcase 1 comparisons: " << res.getKMPComp() << endl;
    REQUIRE(expected == out);
}

/**
 * search for a simple pattern in short string
 */
TEST_CASE("Simple testcase 2", "[weight=5]")
{
    string pattern = "AABAACAABAA";
    string dataset = "AABAADABAAABAACAABAA";
    KMPsearch res = KMPsearch(dataset, pattern);
    vector<size_t> out = res.search();
    vector<size_t> expected = {9};
    REQUIRE(expected == out);
}

TEST_CASE("Test with input", "[weight=5]")
{
    string pattern = "ABABCABAB";
    string dataset = "ABABDABACDABABCABABABABDABACDABABCABABABABDABACDABABCABABABABDABACDABABCABAB";

	
    KMPsearch res = KMPsearch(dataset, pattern);
    vector<size_t> out = res.search();
    vector<size_t> expected = res.naiveSearch();
    cout << "Output: ";
    for (unsigned i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }
    cout << endl;
     cout << "Expected: ";
    for (unsigned i = 0; i < out.size(); i++) {
        cout << expected[i] << " ";
    }
    cout << endl;
    std::cout <<"naive Input comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP Input comparisons: " << res.getKMPComp() << std::endl;
    // cout << "output: " << out << endl;
    REQUIRE(expected == out);
}

/**
 * Test naive search
 */
TEST_CASE("Naive simple 1", "[weight=5]")
{
    string pattern = "ABC";
    string dataset = "ABCuhluhu";

	vector<size_t> expected = {0};
    KMPsearch res = KMPsearch(dataset, pattern);
    vector<size_t> out = res.naiveSearch();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    REQUIRE(expected == out);
}

/**
 * testing pattern search using data file 1
 */
TEST_CASE("file ABCtest.txt input", "[weight=5]")
{
	
    string infile = "../../data/ABCtest.txt";
    KMPsearch res = KMPsearch(infile);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}
/**
 * testing pattern search using data file 2
 */
TEST_CASE("file onelineinput.txt input", "[weight=5]")
{
	
    string infile = "../../data/onelineinput.txt";
    KMPsearch res = KMPsearch(infile);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

/**
 * testing pattern search using data file 3
 */
TEST_CASE("file cs225webpage.txt input", "[weight=5]")
{
	
    string infile = "../../data/cs225webpage.txt";
    KMPsearch res = KMPsearch(infile);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("file dna output file 1 (small) input", "[weight=5]")
{
    string infile = "../../data/outputFilesDNA/output_file_2.txt";
    KMPsearch res = KMPsearch(infile);
    std::string search = "AGGCTAGGCTAAGGCT";
    res.setPattern(search);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("file dna output file 4 (medium) input", "[weight=5]")
{
    string infile = "../../data/outputFilesDNA/output_file_4.txt";
    KMPsearch res = KMPsearch(infile);
    std::string search = "AGGCTAGGCTAAGGCT";
    res.setPattern(search);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("file dna output 10 (large) input", "[weight=5]")
{
    string infile = "../../data/outputFilesDNA/output_file_10.txt";
    KMPsearch res = KMPsearch(infile);
    std::string search = "AGGCTAGGCTAAGGCT";
    res.setPattern(search);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("file book small input", "[weight=5]")
{
    string infile = "../../data/books/small.txt";
    KMPsearch res = KMPsearch(infile);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("file book grimfairytales input", "[weight=5]")
{
    string infile = "../../data/books/grimmfairytales.txt";
    KMPsearch res = KMPsearch(infile);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("file dna output 2 input", "[weight=5]")
{
    string infile = "../../data/DNAoutput100/output_file_2.txt";
    KMPsearch res = KMPsearch(infile);
    std::string search = "AGGCTAGGCTAAGGCT";
    res.setPattern(search);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("file book mobydick input", "[weight=5]")
{
    string infile = "../../data/books/mobydick.txt";
    KMPsearch res = KMPsearch(infile);
    vector<size_t> expected = res.naiveSearch();
    vector<size_t> out = res.search();
    std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

TEST_CASE("Randomly generated testcase", "[weight=5]")
{
    KMPsearch res = KMPsearch(" "," ");
    string pattern = res.getRandomString(4, 65, 66);
    string dataset = res.getRandomString(1000, 65, 66);

    cout <<pattern << endl;
    // cout <<dataset << endl;

    res.setData(dataset);
    res.setPattern(pattern);
    
    vector<size_t> out = res.search();
    vector<size_t> expected = res.naiveSearch();
    std::cout <<"naive random comparisons: " << res.getNaiveComp() << std::endl;
    std::cout <<"KMP random comparisons: " << res.getKMPComp() << std::endl;
    REQUIRE(expected == out);
}

// TEST_CASE("file book art of war input", "[weight=5]")
// {
//     string infile = "../../data/books/aliceinwonderland.txt";
//     KMPsearch res = KMPsearch(infile);
//     vector<size_t> expected = res.naiveSearch();
//     vector<size_t> out = res.search();
//     std::cout <<"naive comparisons: " << res.getNaiveComp() << std::endl;
//     std::cout <<"KMP comparisons: " << res.getKMPComp() << std::endl;
//     REQUIRE(expected == out);
// }
// TEST_CASE("Output Data", "[weight=5]")
// {
//     string infile = "../../data/onelineinput.txt";
//     KMPsearch res = KMPsearch(infile);
//     vector<char> data = res.getPattern();
//     res.setPattern("dog");
//     vector<size_t> expected = res.naiveSearch();
//     vector<size_t> out = res.search();
//     for (unsigned i = 0; i < data.size(); i++) {
//         cout << data[i];
//     }
//     REQUIRE(expected == out);
// }
