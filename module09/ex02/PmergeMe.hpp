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
void displayResult(const std::vector<int>& container, const std::string& type, long time);  // Für vector
std::vector<int> generateJacobsthalNumbers(int n);
void customMergeUsingJacobsthal(std::vector<int>& vec, int left, int mid, int right);
void mergeInsertionSortWithJacobsthal(std::vector<int>& vec, int left, int right);
void mergeInsertionSortWithJacobsthalDeque(std::deque<int>& deque, int left, int right);  // Für deque
void fordJohnsonSortVectorWithJacobsthal(std::vector<int>& vec);
void fordJohnsonSortDequeWithJacobsthal(std::deque<int>& deque);
int processVector(char** argv);
int processDeque(char** argv);

#endif 