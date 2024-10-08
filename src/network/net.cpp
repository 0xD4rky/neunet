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

void Net::train(const std::vector<std::vector<double>>& data,
                const std::vector<int>& labels,
                int epochs, double learning_rate){
    

    for (int epoch = 0; epoch < epochs; epoch ++){
        double epoch_loss = 0.0;
        for (size_t i = 0; i < data.size(); i ++){
            auto output = forward(data[i]);
            std::vector<double> target = {static_cast<double>(labels[i])};
            epoch_loss += calculate_loss(output,target);
            backpropagate(target);
        }
        std::cout << "Epoch " << epoch + 1 << "/" << epochs << " - Loss: " << epoch_loss / data.size() << std::endl;
    }
}

void Net::backpropagate(const std::vector<double>& expected){
    // computing gradients for the output layer
    Layer& output_layer = layers.back();
    std::vector<double> output_deltas(output_layer.get_activations().size());
    for (size_t i = 0; i < output_deltas.size(); i ++){
        output_deltas[i] = output_layer.get_activations()[i] - expected[i];
    }
    output_layer.compute_gradient(output_deltas);\
    
    for(int i = layers.size() - 2; i >= 0 ; --i){
        std::vector<double> next_layer_deltas(layers[i+1].get_neurons().size());
        for (size_t j = 0; j < next_layer_deltas.size(); ++j)
        {
            next_layer_deltas[j] = 0.0;
            for(size_t k =0 ; k <layers[i+1].get_neurons().size(); ++k){
                next_layer_deltas[j] += layers[i+1].get_neurons()[k].get_weights()[j] * layers[i+1].get_deltas()[k];
            }
        }
        layers[i].compute_gradient(next_layer_deltas);
    }
}

double Net::calculate_loss(const std::vector<double>& output, const std::vector<double>& target) const{
    double loss = 0.0;
    for(size_t i = 0; i < output.size(); i ++){
        loss += std::pow((output[i] - target[i]),2);
    }
    return loss/output.size();
}

double Net::predict(const std::vector<double>& inputs){
    auto output = forward(inputs);
    return output.front();
    // since this is binary classification, return the first output only
}