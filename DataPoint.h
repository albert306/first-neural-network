#pragma once
#ifndef DATAPOINT_H_
#define DATAPOINT_H_

#include <vector>

using namespace std;

struct DataPoint {
    public:
        vector<double> inputs;
        int label;
        vector<double> expectedOutputs;

        DataPoint(vector<double> inputs, int label, int numOfLabels);
};

#endif