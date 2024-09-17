## Project Summary

Our proposed extra credit project for UIUC's [CS225 - Data Structure](https://siebelschool.illinois.edu/academics/courses/cs225) is to implement the 'KMP algorithm' for searching a large text file for specific patterns.

## Code

All code files can be found in the `code/` directory. To run the code:

1. Create a `build` directory inside `code/`

2. CD into `build` and run `cmake ..` and `make`.

3. Modify the `main.cpp` file to run whichever `.txt` to be searched through.

4. '.txt' in 'data/' has the predefined pattern to search for on the first line. You can change the target pattern by using the 'setPattern' function in the KMPSearch class.

5. 'search' and 'naiveSearch' functions will return the position of the matching pattern within the dataset. The number of the corresponding comparisons used can be found by using the 'KMPCount' and 'naiveCount' functions.

## Data

The test data are in '.txt' files containing simple sentences, paragraphs from the webpages, novels, and raw DNA sequences.

## Documents

The proposal, weekly log, final report, and presentation video can be found in the `documents/` directory.

## Feedback

All feedback from our project mentor can be found in the `feedback/` directory.
