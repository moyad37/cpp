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
#include <cstdlib>
#include <limits>

// Function declarations
int parseInput(char **argv);
void displayArguments(char **argv);
int processVector(char **argv);
int processDeque(char **argv);
void displayResult(const std::vector<int> &container, const std::string &type, clock_t time);
void displayResult(const std::deque<int> &container, const std::string &type, clock_t time);

// Ford-Johnson sorting algorithm for vector
void fordJohnsonSort(std::vector<int> &vec);
void merge(std::vector<int> &vec, int left, int mid, int right);

#endif