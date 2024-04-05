#pragma once
#ifndef LAYER_H_
#define LAYER_H_

#include <vector>

using namespace std;

class Layer {
    public:
        int numOfNodesIn, numOfNodesOut;
        vector<vector<double>> weights; // weights[0][2] weight of connection from node 0 to node 2
        vector<double> biases;
        
        Layer(int numOfNodesIn, int numOfNodesOut) {
            this->numOfNodesIn = numOfNodesIn;
            this->numOfNodesOut = numOfNodesOut;
        };

        void initializeRandom();

        void toString();

        double activationFunction(double input);
        
        vector<double> calculateOutputs(vector<double> inputs);
};

#endif