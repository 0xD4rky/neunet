#include "layer.cpp"

class Network{
    public:
        Network(const std::vector<int>& layers);
        std :: vector<double> predict(const std::vector<double>& inputs);
    private:
        std :: vector<Layer> networkLayers;
        // each ele of vector holds an object of Layer
        // layer object contains {neurons, forward pass}
};

Network::Network(const std::vector<int>& layers){

// each int represents no of neu in a layer
    
    for(int i = 0; i < layers.size(); i ++){
        networkLayers.push_back(Layer(layers[i],layers[i-1]));
        // Layer const -> {no of neu, no of neu of prev layer}
    }
}

std::vector<double> Network::predict(const std::vector<double>& inputs){
    std::vector<double> outputs = inputs;
    for(auto& layer: networkLayers){
        outputs = layer.forward(outputs);
    }
    return outputs;
}