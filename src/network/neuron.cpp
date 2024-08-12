#include "neuron.h"
#include <cmath>
#include <cstdlib>

Neuron::Neuron(int input_size){
    weights.resize(input_size);
    for (auto &weight: weights){
        weight = static_cast<double> (rand()) / RAND_MAX;
    }
    bias = static_cast<double> (rand())/ RAND_MAX;
}

double Neuron::activate(const std::vector<double>& inputs){
    double sum = bias;
    for(size_t i = 0; i < inputs.size(); i++){
        sum += inputs[i]*weights[i];
    }
    return sigmoid(sum);
}

std::vector<double>& Neuron::get_weights(){
    return weights;
}

double& Neuron:: get_bias(){
    return bias;
}

void Neuron::update(const std::vector<double>& delta_weights, double delta_bias, double learning_rate){
    for(size_t i = 0; i < weights.size(); i++){
        weights[i] = weights[i] - learning_rate*delta_weights[i];
    }
    bias = bias - learning_rate*delta_bias;
}