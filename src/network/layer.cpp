#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "layer.h"

Layer::Layer(int no_neurons,int input_size){
    for(size_t i = 0; i < no_neurons; i ++){
        neurons.push_back(Neuron(input_size));
    }
}

std::vector<double> Layer::forward(std::vector<double>& inputs){
    activations.clear();
    for (auto &neuron: neurons){
        activations.push_back(neuron.activate(inputs));
    }
    return activations;
}   

void Layer::compute_gradient(const std::vector<double>& delta_next_layer){
    deltas.resize(neurons.size());
    for (size_t i = 0;i < neurons.size(); i ++ ){
        double activation = activations[i];
        deltas[i] = sigmoid_derivative(activation) * delta_next_layer[i];
    }
}