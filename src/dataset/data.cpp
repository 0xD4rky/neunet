#include "data.h"
#include <fstream>
#include <algorithm>
#include "../misc/functions.h"

Dataset::Dataset(string filename){
    std::ifstream infile(filename);
    std::vector<double> line;
    double a;
    while(!infile.eof()){
        infile >> a;
        line.push_back(a);
        
        if(infile.get() == '\n'){
            double out = line[line.size()-1];
            line.pop_back();

            ins.push_back(line);
            outs.push_back({out});
            line.clear();
        }
    }
}

Dataset::~Dataset(){}

void Dataset::split(double ptrain){
    for(size_t i =0;i<ins.size();i++){
        if(random(0,1) < ptrain){
            train_ins.push_back(&ins[i]);
            train_outs.push_back(&outs[i]);
        }
        else
		{
			test_ins.push_back(&ins[i]);
			test_outs.push_back(&outs[i]);
		}
    }
}

const vector<const vector<double>*>& Dataset::In(Datatype d) const
{ 
	if(d == Datatype::TRAIN)
		return train_ins;
	return test_ins;
}

const vector<const vector<double>*>& Dataset::Out(Datatype d) const
{
	if (d == Datatype::TRAIN)
		return train_outs;
	return test_outs;
}

