#pragma once
#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <vector>
#include "Layer.h"
#include "DataPoint.h"

using namespace std;

class NeuralNetwork {
    public:
        vector<Layer> layers;

        NeuralNetwork(vector<int> layerSizes);

        vector<double> calculateOutputs(vector<double> inputs);

        int classify(vector<double> inputs);

        double nodeLoss(double activation, double expected);

        double loss(DataPoint dataPoint);

        double loss(vector<DataPoint> data);
};


#endif