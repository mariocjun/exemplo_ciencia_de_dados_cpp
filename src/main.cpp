// Copyright (c) 2019 Cristiano L. Fontana
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

extern "C" {
#include <gsl/gsl_fit.h>
#include <gsl/gsl_statistics_double.h>
}

int main() {

    const std::string input_file_name("../anscombe.csv");
    const char *delimiter = "\t";
    const unsigned int skip_header = 3;
    const unsigned int column_x = 0;
    const unsigned int column_y = 1;
    const std::string output_file_name("../fit_Cpp11.csv");
    const unsigned int N = 100;

    std::cout << "#### Anscombe's first set with C++11 ####" << std::endl;

    std::ifstream input_file(input_file_name);

    std::vector<double> x;
    std::vector<double> y;

    unsigned int row = 0;

    while (input_file.good()) {
        std::string line;

        getline(input_file, line);

        if (row >= skip_header && line.length() > 0) {
            unsigned int column = 0;

            char *token = std::strtok(const_cast<char*>(line.c_str()), delimiter);

            while (token != nullptr)
            {
                const double value = std::stod(token);

                if (column == column_x) {
                    x.emplace_back(value);
                } else if (column == column_y) {
                    y.emplace_back(value);
                }

                column += 1;
                token = std::strtok(nullptr, delimiter);
            }
        }

        row += 1;
    }

    input_file.close();

    if (x.size() != y.size()) {
        std::cout << "ERROR: Mismatch of data arrays length." << std::endl;
    }

    const size_t entries_number = x.size();

    const double min_x = *std::min_element(x.begin(), x.end());
    const double max_x = *std::max_element(x.begin(), x.end());

    double slope;
    double intercept;
    double cov00, cov01, cov11;
    double chi_squared;

    gsl_fit_linear(x.data(), 1, y.data(), 1, entries_number,
                   &intercept, &slope,
                   &cov00, &cov01, &cov11, &chi_squared);
    const double r_value = gsl_stats_correlation(x.data(), 1, y.data(), 1, entries_number);

    std::cout << "Slope: " << slope << std::endl;
    std::cout << "Intercept: " << intercept << std::endl;
    std::cout << "Correlation coefficient: " << r_value << std::endl;

    std::ofstream output_file(output_file_name);

    const double step_x = ((max_x + 1) - (min_x - 1)) / N;

    for (unsigned int i = 0; i < N; i += 1) {
        const double current_x = (min_x - 1) + step_x * i;
        const double current_y = intercept + slope * current_x;

        output_file << current_x << "\t" << current_y << std::endl;
    }

    output_file.close();

    return EXIT_SUCCESS;
}
