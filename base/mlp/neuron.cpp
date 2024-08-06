#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>

class Neuron {
public:
    Neuron(int numInputs);
    double activate(const std::vector<double>& inputs);
    void setWeights(const std::vector<double>& newWeights);
    std::vector<double> getWeights() const;

private:
    double sigmoid(double x) const;
    std::vector<double> weights;
    double bias;
};

Neuron::Neuron(int numInputs) {
    std::cout << "Creating Neuron with " << numInputs << " inputs.\n";
    for (int i = 0; i < numInputs; ++i) {
        weights.push_back(((double) rand() / (RAND_MAX))); // Random weight initialization
    }
    bias = ((double) rand() / (RAND_MAX)); // Random bias initialization
}

double Neuron::activate(const std::vector<double>& inputs) {
    double activation = bias;
    for (size_t i = 0; i < weights.size(); ++i) {
        activation += weights[i] * inputs[i];
    }
    return sigmoid(activation);
}

double Neuron::sigmoid(double x) const {
    return 1.0 / (1.0 + std::exp(-x));
}

void Neuron::setWeights(const std::vector<double>& newWeights) {
    weights = newWeights;
}

std::vector<double> Neuron::getWeights() const {
    return weights;
}
