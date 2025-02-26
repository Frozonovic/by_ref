/**
 * @file by_ref.h
 * @brief Declarations for the by_ref program.
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */

#pragma once


#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>

/**
 * Receives input from the user and handles accordingly
 *
 * @param values Object to store inputted user values
 */
void get_value(std::vector<double>& values);

/**
 * Computes the statistics based on the inputted user values
 *
 * @param values Object storing inputted user values
 * @param count Number of inputted user values
 * @param sum Total of given values
 * @param mean  Average of given values
 */
void calc_stats(std::vector<double>& values, unsigned long* count, double* sum,
                double* mean);

/**
 * Prints the computed statistics to standard output
 *
 * @param count Number of inputted user values
 * @param sum Total of given values
 * @param mean Average of given values
 */
void print_stats(unsigned long& count, double& sum, double& mean);