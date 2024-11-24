#pragma once
#include <vector>

class Neuron {
public:
    Neuron(size_t numInputs);
    double activate(const std::vector<double>& inputs);
    void updateWeights(const std::vector<double>& inputs, double delta, double learningRate);
    std::vector<double> getWeights() const;
    double getDelta() const;
    void setDelta(double delta); 