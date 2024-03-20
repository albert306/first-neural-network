#include "stdlib.h"
#include <vector>
#include <string>
#include "Layer.h"

using namespace std;

class NeuralNetwork {
    public:
        vector<Layer> layers;

        NeuralNetwork(vector<int> layerSizes) {
            for (int i = 0; i < layerSizes.size() - 1; i++) {
                layers[i] = Layer(layerSizes[i], layerSizes[i + 1]);
            }
        }

        vector<double> calculateOutputs(vector<double> inputs) {
            for (Layer layer : layers) {
                inputs = layer.calculateOutputs(inputs);
            }
            return inputs;
        }

        int classify(vector<double> inputs) {
            vector<double> outputs = this->calculateOutputs(inputs);
            
            // find nodeindex with highest activation
            double highestActivation = -INFINITY;
            int highestActivationIndex = 0;
            for (int i = 0; i < outputs.size(); i++) {
                if (outputs[i] > highestActivation) {
                    highestActivation = outputs[i];
                    highestActivationIndex = i;
                }
            }
            return highestActivationIndex;
        }
};