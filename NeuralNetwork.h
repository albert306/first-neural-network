#pragma once
#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <vector>
#include <iostream>
#include "Layer.h"
#include "DataPoint.h"

using namespace std;

class NeuralNetwork {
    public:
        vector<Layer> layers;

        NeuralNetwork(vector<int> layerSizes) {
            for (int i = 0; i < layerSizes.size() - 1; i++) {
                layers.push_back(Layer(layerSizes[i], layerSizes[i + 1]));
                std::cout << "layer " << i << " initialized: ";
                layers[i].initializeRandom();
                layers[i].toString();
                std::cout << std::endl;
            }
        }

        vector<double> calculateOutputs(vector<double> inputs);

        int classify(vector<double> inputs);

        double nodeLoss(double activation, double expected);

        double loss(DataPoint dataPoint);

        double loss(vector<DataPoint> data);
};


#endif