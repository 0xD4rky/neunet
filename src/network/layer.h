#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "neuron.h"

class Layer{
    public:
        Layer(int no_neurons,int input_size);
        std::vector<double> forward(std::vector<double>& inputs);
        void compute_gradient(const std::vector<double>& delta_next_layer);
        void update_weights(double learning_rate);
    
        std::vector<Neuron>& get_neurons;
        const std::vector<double>& get_activations;
        const std::vector<double>& get_deltas;

    private:
        std::vector<Neuron> neurons;
        std::vector<double> activations;
        std::vector<double> deltas;
};

#endif