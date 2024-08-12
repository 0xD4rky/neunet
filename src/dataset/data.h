#pragma once

#include <vector>

enum Datatype{
    TRAIN,
    TEST
};
// for accessing the data using test or train

class Dataset{
    public:
        Dataset(string filename);
        ~Dataset ();

        const std::vector<const std::vector<double>*>& In(Datatype d) const;
        const std::vector<const std::vector<double>*>& Out(Datatype d) const; //accessors pointing to vectors
        void split(double ptrain);

    private:
        std::vector<std::vector<double>> ins;
        std::vector<std::vector<double>> outs;
        std::vector<const std::vector<double>*> train_ins;
        std::vector<const std::vector<double>*> train_outs;
        std::vector<const std::vector<double>*> test_ins;
        std::vector<const std::vector<double>*> test_outs;

};

