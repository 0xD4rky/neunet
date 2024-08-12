#ifndef LAYER.H
#define LAYER.H

#include <vector>
#include "neuron.h"

class Layer{
    public:
        Layer(int no_neurons,int input_size);
        std::vector<double> forward(std::vector<double>& inputs);
        void compute_gradient(const std::vector<double>& delta_next_layer);
        void update_weights(double learning_rate);
    private:
        std::vector<Neuron>& get_neurons;
        const std::vector<double>& get_activations;
        const std::vector<double>& get_deltas;
};

#endif