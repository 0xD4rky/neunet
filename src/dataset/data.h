#pragma once
#include <vector>
#include <string>

class Dataset {
public:
    Dataset(const std::string& filename);
    void loadData();
    void splitTrainTest(float trainRatio);
    std::vector<std::vector<double>> getTrainFeatures() const;
    std::vector<double> getTrainLabels() const;
    std::vector<std::vector<double>> getTestFeatures() const;
    std::vector<double> getTestLabels() const;
    void shuffle();
    
private:
    std::string filename_;
    std::vector<std::vector<double>> features_;
    std::vector<double> labels_;
    std::vector<std::vector<double>> trainFeatures_;
    std::vector<double> trainLabels_;
    std::vector<std::vector<double>> testFeatures_;
    std::vector<double> testLabels_;
};