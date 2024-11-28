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


void NeuralNetwork::train(const std::vector<std::vector<double>>& features,
                         const std::vector<double>& labels,
                         size_t epochs) {
    for (size_t epoch = 0; epoch < epochs; epoch++) {
        double totalError = 0.0;
        
        for (size_t i = 0; i < features.size(); i++) {
            // Forward pass
            auto prediction = predict(features[i]);
            
            // Compute error
            std::vector<double> expected(1, labels[i]);
            totalError += utils::computeMSE(prediction, expected);
            
            // Backward pass
            backpropagate(expected);
            
            // Update weights
            for (size_t j = 0; j < layers_.size(); j++) {
                auto& layer = layers_[j];
                const auto& layerInputs = (j == 0) ? features[i] 
                    : layers_[j-1].forward(features[i]);
                layer.updateWeights(layerInputs, learningRate_);
            }
        }
        
        if (epoch % 100 == 0) {
            std::cout << "Epoch " << epoch << ", Error: " 
                     << totalError/features.size() << std::endl;
        }
    }
}
