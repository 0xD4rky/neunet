#include <vector>
#include <iostream>
#include "layer.cpp"

class Network {
public:
    Network(const std::vector<int>& layers);
    std::vector<double> predict(const std::vector<double>& inputs);
    const std::vector<Layer>& getLayers() const;  // Add this accessor

private:
    std::vector<Layer> networkLayers;
};

Network::Network(const std::vector<int>& layers) {
    std::cout << "Creating Network.\n";
    for (size_t i = 1; i < layers.size(); ++i) {
        networkLayers.push_back(Layer(layers[i], layers[i - 1]));
    }
}

std::vector<double> Network::predict(const std::vector<double>& inputs) {
    std::vector<double> outputs = inputs;
    for (auto& layer : networkLayers) {
        outputs = layer.forward(outputs);
    }
    return outputs;
}

const std::vector<Layer>& Network::getLayers() const {
    return networkLayers;
}
