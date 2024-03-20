#include "stdlib.h"
#include <vector>
#include <string>
#include "Layer.h"

using namespace std;

class Layer {
    public:
        int numOfNodesIn, numOfNodesOut;
        vector<vector<double>> weights; // weights[0][2] weight of connection from node 0 to node 2
        vector<double> biases;
        
        Layer(int numOfNodesIn, int numOfNodesOut) {
            this->numOfNodesIn = numOfNodesIn;
            this->numOfNodesOut = numOfNodesOut;
        }

        double activationFunction(double input) {
            return (input > 0) ? 1 : 0;
        }

        vector<double> calculateOutputs(vector<double> inputs) {
            vector<double> outputs;
            for (int i = 0; i < numOfNodesOut; i++) {
                double weightetInputs = biases[i];
                for (int j = 0; j < numOfNodesIn; j++) {
                    weightetInputs += inputs[j] * weights[j][i];
                }
                outputs[i] = activationFunction(weightetInputs);
            }
            return outputs;
        }
};