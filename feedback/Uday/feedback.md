The overall progress so far looks good. Coming to the issues encountered:

What is the standard for counting comparison? Should we do it for every == sign or every iteration?

- The counting comparison is done for every time when you perform the equality check.

We realize the KMP algorithm is only efficient when there are a lot of partial matches existing in the dataset and the pattern.
The way we simulated this is through random strings by a limited range of characters. What is the intended application of the algorithm? What natural dataset would this be useful for? 

Here, are a couple of resources that clearly explains when KMP algorithm will perform better than naive search:

https://stackoverflow.com/questions/20016092/why-is-naive-string-search-algorithm-faster
https://stackoverflow.com/questions/64899867/why-naive-algorithm-is-faster-than-kmp-and-robin-karp
https://stackoverflow.com/questions/42402772/when-is-good-to-use-kmp-algorithm

To summarize KMP is useful when you have long patterns to match and also there are repititive sub patterns. For short patterns, with unique characters it might usually be the case that naive performs better than KMP. 

KMP algorithm is used in many applications. Here, is a short answer related to this: https://www.quora.com/What-are-some-applications-of-the-Knuth-Morris-Pratt-Algorithm-in-real-life

Coming to our present project, if you are finding KMP algorithm not very helpful for searching words in books, try comparing your implementations of KMP and Naive algorithm on Human DNA datasets as they contain repetitive sub-patterns and maybe that can help you visualize the difference in running times.