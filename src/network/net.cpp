#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "net.h"

Net::Net(const std::vector<int>& layer_sizes){
    for (size_t i = 1; i < layer_sizes.size(); i ++){
        layers.push_back(Layer(layer_sizes[i],layer_sizes[i-1])); 
        // layers -> vector that holds objects of class Layer
        // Layer -> accepts no of layers and input size
        // current layer gives no of neurons and prev layer gives input size
    }
}

std::vector<double> Net::forward(const std::vector<double>& inputs){
    std::vector<double> activations = inputs;
    for (auto &layer : layers){
        activations = layer.forward(activations);
    }
    return activations;
}

