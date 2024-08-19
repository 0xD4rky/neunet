#include "utils.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "utils.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<double>> load_data(const std::string& filename) {
    std::vector<std::vector<double>> data;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<double> row;
        double value;

        while (ss >> value) {
            row.push_back(value);
            if (ss.peek() == ',')
                ss.ignore();
        }
        data.push_back(row);
    }

    return data;
}

std::vector<int> load_labels(const std::string& filename) {
    std::vector<int> labels;
    std::ifstream file(filename);
    std::string line;
    int label;

    while (file >> label) {
        labels.push_back(label);
    }

    return labels;
}

std::pair<std::vector<std::vector<double>>, std::vector<int>> load_dataset(const std::string& filename) {
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<double> row;
        double value;
        int label;

        while (ss >> value) {
            row.push_back(value);
            if (ss.peek() == ',')
                ss.ignore();
        }

        label = static_cast<int>(row.back()); // Last element is the label
        row.pop_back(); // Remove label from row
        data.push_back(row);
        labels.push_back(label);
    }

    return {data, labels};
}
