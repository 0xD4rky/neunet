#ifndef NET_H
#define NET_H

#include <vector>
#include "layer.h"

class Net{

    public:
        Net(const std::vector<int>& layer_sizes);
        std::vector<double> forward(const std::vector<double>& inputs);
        void train(const std::vector<std::vector<double>>& data, 
               const std::vector<int>& labels, 
               int epochs, double learning_rate);
        double predict(const std::vector<double>& inputs);

    private:
        std::vector<Layer> layers;
        void backpropagate(const std::vector<double>& expected);
        double calculate_loss(const std::vector<double>& output, const std::vector<double>& target) const;

};



#endif