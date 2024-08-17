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