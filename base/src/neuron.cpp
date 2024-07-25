#include <iostream>
#include <vector>
#include <stdlib.h>

class Neuron{

    /*
    1. set weights
    2. set biases
    3. set activation function
    */
    public:
        Neuron(int number_of_inputs);
        
        void set_weights(const std::vector<double>& new_weights);
        double activate(const std::vector<double>& inputs);
        std::vector<double> get_weights() const;

    private:
        std::vector<double> weights;
        double bias;

};

Neuron::Neuron (int num_of_inputs){
    for(int i=0;i< num_of_inputs;i++){
        weights.push_back(((double) rand())/ (RAND_MAX));
    }
    bias = ((double)rand())/RAND_MAX;
    // w&b : [0,1]
}

double Neuron::activate(const std::vector<double>& inputs){
    double activation = 0;
    for(int i=0;i<weights.size();i++){
        activation = weights[i]*inputs[i];
    }
    activation += bias;
    activation = 1.0/(1.0  +exp(-activation));
    return activation;
}

void Neuron::set_weights(const std::vector<double>& newWeights) {
    weights = newWeights;
}

std::vector<double> Neuron::get_weights() const {
    return weights;
}