#pragma once
#include "layer.h"
#include <vector>

class NeuralNetwork {
public:
    NeuralNetwork(const std::vector<size_t>& topology, double learningRate);
    void train(const std::vector<std::vector<double>>& features, 
              const std::vector<double>& labels,
              size_t epochs);
    std::vector<double> predict(const std::vector<double>& inputs);
    double validate(const std::vector<std::vector<double>>& features,
                   const std::vector<double>& labels);
    
private:
    std::vector<Layer> layers_;
    double learningRate_;
    void backpropagate(const std::vector<double>& expected);
};