/**
 * @file by_ref.cpp
 * @brief Implementation for the by_ref program.
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */

#include "by_ref.h"

/**
 * Main entry point for executing by_ref
 *
 * @return 0 on success, else non-zero on failure
 */
int main() {
    std::vector<double> values;
    unsigned long count = 0;
    double sum = 0.0;
    double mean = 0.0;

    get_value(values);

    calc_stats(values, &count, &sum, &mean);

    print_stats(count, sum, mean);

    exit(EXIT_SUCCESS);
}


void get_value(std::vector<double>& values) {
    try {
        double input = 0;

        do {
            // Prompt user for input
            std::cout << "Enter a value: ";

            // Ensure a valid value is given
            if (!(std::cin >> input)) {
                throw std::invalid_argument("Error: Invalid argument received");
            }

            // Add value to vector
            if (input >= 0) {
                values.push_back(input);
            }

            // New-line for next prompt
            std::cout << std::endl;

        } while (input >= 0);
    } catch (const std::invalid_argument& err) {
        std::cerr << err.what() << std::endl;

        exit(1);
    }
}


void calc_stats(std::vector<double>& values, unsigned long* count, double* sum,
    double* mean) {

    if (values.empty()) {
        std::cerr << "Error: No values to compute" << std::endl;

        exit(2);
    }

    // Assign count
    *count = values.size();

    // Calculate sum
    for (auto value : values) {
        *sum += value;
    }

    // Calculate mean
    *mean = *sum / *count;

}


void print_stats(unsigned long& count, double& sum, double& mean) {
    // Precision to six decimal places
    const int DESIRED_PRECISION = 6;

    // Print results to standard out
    std::cout << "Count: " << count << std::endl;
    std::cout << "Sum: " << std::fixed << sum << std::setprecision(DESIRED_PRECISION) << std::endl;
    std::cout << "Mean: " << std::fixed << mean << std::setprecision(DESIRED_PRECISION) << std::endl;
}

