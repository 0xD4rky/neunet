#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "../misc/functions.h"

class Neuron{
    public:
        Neuron(int input_size);
        double activate(const std::vector<double>& inputs);
        
        // accessors to update and get W&Bs

        std::vector<double>& get_weights();
        double& get_bias();
        void update(const std::vector<double>& delta_weights, double delta_bias, double learning_rate);

    private:
        std::vector<double> weights;
        double bias;
};


#endif
