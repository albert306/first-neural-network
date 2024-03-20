#include "stdlib.h"
#include <vector>

using namespace std;

struct DataPoint {
    public:
        vector<double> inputs;
        int label;
        vector<double> expectedOutputs;

        DataPoint(vector<double> inputs, int label, int numOfLabels);
};