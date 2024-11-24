#include "neuron.h"
#include "../util/utils.h"
#include <random>

Neuron::Neuron(size_t numInputs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(0.0, 1.0);
    
    // Initialize weights with Xavier/Glorot initialization
    double scale = std::sqrt(2.0 / numInputs);
    for (size_t i = 0; i < numInputs; i++) {
        weights_.push_back(dist(gen) * scale);
    }
    bias_ = dist(gen) * scale;
}

double Neuron::activate(const std::vector<double>& inputs) {
    double sum = bias_;
    for (size_t i = 0; i < inputs.size(); i++) {
        sum += inputs[i] * weights_[i];
    }
    output_ = utils::sigmoid(sum);
    return output_;
}

void Neuron::updateWeights(const std::vector<double>& inputs, 
                          double delta, double learningRate) {
    for (size_t i = 0; i < weights_.size(); i++) {
        weights_[i] += learningRate * delta * inputs[i];
    }
    bias_ += learningRate * delta;
}
