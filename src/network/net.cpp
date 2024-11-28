#include "network.h"
#include "../util/utils.h"
#include <iostream>


NeuralNetwork::NeuralNetwork(const std::vector<size_t>& topology, 
                           double learningRate) 
    : learningRate_(learningRate) {
    
    for (size_t i = 0; i < topology.size() - 1; i++) {
        layers_.emplace_back(topology[i + 1], topology[i]);
    }
}