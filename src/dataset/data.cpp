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

void Dataset::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::vector<size_t> indices(features_.size());
    for (size_t i = 0; i < indices.size(); i++) {
        indices[i] = i;
    }
    std::shuffle(indices.begin(), indices.end(), gen);
    
    std::vector<std::vector<double>> shuffledFeatures;
    std::vector<double> shuffledLabels;
    
    for (size_t idx : indices) {
        shuffledFeatures.push_back(features_[idx]);
        shuffledLabels.push_back(labels_[idx]);
    }
    
    features_ = shuffledFeatures;
    labels_ = shuffledLabels;
    // adding labels to the network
}