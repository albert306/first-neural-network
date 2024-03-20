#include "stdlib.h"
#include <vector>
#include <string>

using namespace std;

class Layer {
    public:
        int numOfNodesIn, numOfNodesOut;
        vector<vector<double>> weights; // weights[0][2] weight of connection from node 0 to node 2
        vector<double> biases;
        
        Layer(int numOfNodesIn, int numOfNodesOut);
        
        vector<double> calculateOutputs(vector<double> inputs);
};