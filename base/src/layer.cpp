#include <vector>
#include <iostream>
#include "neuron.cpp"

class Layer {
public:
    Layer(int numNeurons, int numInputsPerNeuron);
    std::vector<double> forward(const std::vector<double>& inputs);
    const std::vector<Neuron>& getNeurons() const;  // Add this accessor

private:
    std::vector<Neuron> neurons;
};

Layer::Layer(int numNeurons, int numInputsPerNeuron) {
    std::cout << "Creating Layer with " << numNeurons << " neurons, each with " << numInputsPerNeuron << " inputs.\n";
    for (int i = 0; i < numNeurons; ++i) {
        neurons.push_back(Neuron(numInputsPerNeuron));
    }
}

std::vector<double> Layer::forward(const std::vector<double>& inputs) {
    std::vector<double> outputs;
    for (auto& neuron : neurons) {
        outputs.push_back(neuron.activate(inputs));
    }
    return outputs;
}

const std::vector<Neuron>& Layer::getNeurons() const {
    return neurons;
}
