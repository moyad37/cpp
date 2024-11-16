// #ifndef PMERGEME_HPP
// #define PMERGEME_HPP

// #include <iostream>
// #include <vector>
// #include <deque>
// #include <algorithm>
// #include <ctime>
// #include <cstdlib>
// #include <limits>

// /* Function declarations */
// int parseInput(char **argv);
// void displayArguments(char **argv);
// int processVector(char **argv, clock_t &time);
// int processDeque(char **argv, clock_t &time);
// void displayResult(const std::vector<int> &container, const std::string &type, clock_t time);
// void displayResult(const std::deque<int> &container, const std::string &type, clock_t time);

// #endif
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <limits>
#include <cstdlib>

int parseInput(char** argv);
void displayArguments(char** argv);
void displayResult(const std::vector<int>& container, const std::string& type, long time);
void displayResult(const std::deque<int>& container, const std::string& type, long time);
std::vector<int> generateJacobsthalNumbers(int n);
void customMergeUsingJacobsthal(std::vector<int>& vec, int left, int mid, int right);
void mergeInsertionSortWithJacobsthal(std::vector<int>& vec, int left, int right);
void fordJohnsonSortVectorWithJacobsthal(std::vector<int>& vec);
int processVector(char** argv);
int processDeque(char** argv);

#endif // PMERGEME_HPP
