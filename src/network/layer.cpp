#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "layer.h"

Layer::Layer(int no_neurons,int input_size){
    for(int i = 0; i < no_neurons; i ++){
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

void Layer::update_weights(double learning_rate){
    for (size_t i = 0; i < neurons.size(); i ++){
        auto&  weights = neurons[i].get_weights();
        std::vector<double> delta_weights(weights.size());
        for (size_t j = 0; j < delta_weights.size(); ++j){
            delta_weights[j] = deltas[j]*activations[j];
        }
        neurons[i].update(delta_weights,deltas[i],learning_rate);
    }
}

std::vector<Neuron>& Layer::get_neurons(){
    return neurons;
}

const std::vector<double>& Layer::get_activations() const{
    return activations;
}

const std::vector<double>& Layer::get_deltas() const{
    return deltas;
}


