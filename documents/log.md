## Date of Git Commit

### Goals 

### Tasks Complete

### Issues encountered (Questions for mentors)

### Plans for next week


## Nov 4 2023

### Goals 
1. Create NaiveSearching algorithm for comparison (Completed)
2. Start coding constructor and search algorithm for KMP search for small input. (Completed)
3. Create more tests for preprocessing function to prove correctness (Not completed)
4. Find more example datasets. (Completed)
5. Step through algorithm on paper. (Completed)

### Tasks Complete
Rachel wrote the LPS algorithm, naive search, and constructors.
Albert wrote the search algorithm and updated testcases.

### Issues encountered (Questions for mentors)
What is the standard for counting comparison? Should we do it for every == sign or every iteration?
How should we handle especially large dataset that will go over the unsign variable size limit?

### Plans for next week
More testing specifically on large datasets.
Write more testcases for edge cases and preprocessing functions(LPS and constructors).
Start think about benchmarking, more analysis of algorithm.


## Nov 11 2023

### Goals 
1. Test functionality of naive and KMP search (Completed)
2. Add more test cases, including random generated strings (Completed)
3. Create more tests for preprocessing function to prove correctness (Completed)
4. Output the specific location of the matching pattern within the file for user-friendliness (Not completed)


### Tasks Complete
Rachel wrote the more testcases and datasets.
Albert wrote the random string generator.
We realize our set functions were not updating correctly, and we fixed it.

### Issues encountered (Questions for mentors)
What is the standard for counting comparison? Should we do it for every == sign or every iteration?

We realize the KMP algorithm is only efficient when there are a lot of partial matches existing in the dataset and the pattern.
The way we simulated this is through random strings by a limited range of characters. What is the intended application of the algorithm? What natural dataset would this be useful for? 
We found it is not very helpful for searching for words in natural language (ie. a book)

### Plans for next week
Reorganize the class and functions (move irrelevant function out of the class)
Starting writing report and analysis of the algorithm (performance under different circumstances)
Schedule a meeting with mentors and ask for more advice.
Think about how the range of characters, length of the pattern and dataset, and the structure of the pattern and dataset would affect the performance of the algorithm. 


## Nov 28 2023

### Goals 
1. Meet with mentor
2. Discuss how to benchmark
3. Find data that represents the effectiveness of the algorithm
4. Make sure comparisons is correct

### Tasks Complete
Talked to mentors about how the code base works and they agreed that the functionality is correct. 
We walked through test suite which they also said accurately tested all aspects of the code. 
Discussed whether our method of comparisons was correct. They said it was while also giving us ideas on how to benchmark using time instead of just comparisons. 
Mentor gave us the idea of using DNA samples as our dataset

### Issues encountered (Questions for mentors)
No issues were encountered this week

### Plans for next week
Find DNA samples that can be used for testing.
Create graphs for benchmarking
Finish the final report and video

## Dec 2 2023

### Goals 
1. Find DNA data that can be used for benchmarking
2. Benchmark the sets using variable datasets and pattern length
3. Create the slideshow presentation for the video
 

### Tasks Complete
Rachel wrote a python script to parse through very large DNA set into manageable chunks. Also split up the data for benchmarking.
Albert started on the final report and wrote about the Big O for KMP. 

### Issues encountered (Questions for mentors)
Encountered some issues on the results of benchmarking being very variable. We need to reexamine how many datapoints we take for the graphs. 

### Plans for next week
Rebenchmark with more points. 
Finish the video and report. 


## Nov 28 2023

### Goals 
1. Meet with mentor
2. Discuss how to benchmark
3. Find data that represents the effectiveness of the algorithm
4. Make sure comparisons is correct

### Tasks Complete
Talked to mentors about how the code base works and they agreed that the functionality is correct. 
We walked through test suite which they also said accurately tested all aspects of the code. 
Discussed whether our method of comparisons was correct. They said it was while also giving us ideas on how to benchmark using time instead of just comparisons. 
Mentor gave us the idea of using DNA samples as our dataset

### Issues encountered (Questions for mentors)
No issues were encountered this week

### Plans for next week
Find DNA samples that can be used for testing.
Create graphs for benchmarking
Finish the final report and video

## Dec 2 2023

### Goals 
1. Finish benchmarking
2. Finish the report
3. Finish the video

### Tasks Complete
Rachel finished the slide deck for the video and rebenchmarked getting results that made more sense. Realized the scale should not be log. 
Albert finished writing the report.

### Issues encountered (Questions for mentors)
No issues. 

### Plans for next week
Celebrate by taking finals 