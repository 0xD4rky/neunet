#include "data.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

Dataset::Dataset(const std::string& filename) : filename_(filename) {}

void Dataset::loadData() {
    std::ifstream file(filename_);
    std::string line;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<double> row;
        double value;
        
        // Read first two columns as features
        for (int i = 0; i < 2; i++) {
            ss >> value;
            row.push_back(value);
        }
        features_.push_back(row);
        
        // Read third column as label
        ss >> value;
        labels_.push_back(value);
    }
}

void Dataset::splitTrainTest(float trainRatio) {
    size_t trainSize = static_cast<size_t>(features_.size() * trainRatio);
    
    trainFeatures_.assign(features_.begin(), features_.begin() + trainSize);
    trainLabels_.assign(labels_.begin(), labels_.begin() + trainSize);
    
    testFeatures_.assign(features_.begin() + trainSize, features_.end());
    testLabels_.assign(labels_.begin() + trainSize, labels_.end());
}

