#ifndef GEN_H
#define GEN_H

#include <iostream>
#include <random>
using namespace std;

class Number_Generator
{
private:
    int* resultantArray;
    int newSize;

public:
    Number_Generator(const double* inputRatios, const int* values, int size, int p_newSize)
        : newSize(p_newSize)
    {
        double* ratios = new double[size];
        for (int i = 0; i < size; i++)
        {
            ratios[i] = inputRatios[i];
        }

        normalizeRatios(ratios, size);
        double* cumulativeRatios = getCumulativeRatios(ratios, size);

        resultantArray = new int[newSize];
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dist(0.0, 1.0);

        for (int i = 0; i < newSize; i++)
        {
            double randomNumber = dist(gen);
            for (int j = 0; j < size; j++)
            {
                if (randomNumber <=cumulativeRatios[j])
                {
                    resultantArray[i] = values[j];
                    break;
                }
            }
        }

        delete[] ratios;
        delete[] cumulativeRatios;
    }

    ~Number_Generator()
    {
        delete[] resultantArray;
    }

    void normalizeRatios(double* ratios, int size)
    {
        double total = 0.0;
        for (int i = 0; i < size; i++)
        {
            total += ratios[i];
        }

        cout << "NORMALIZED RATIOS" << endl;

        for (int i = 0; i < size; i++)
        {
            ratios[i] /= total;
            cout << ratios[i] << " ";
        }
        cout << endl;
    }

    double* getCumulativeRatios(double* ratios, int size)
    {
        double* cumulativeRatios = new double[size];
        double cumulativeSum = 0;
        cout << "COMULATIVE RATIOS" << endl;
        for (int i = 0; i < size; i++)
        {
            cumulativeSum += ratios[i];
            cumulativeRatios[i] = cumulativeSum;
            cout << cumulativeRatios[i] << ' ';
        }
        cout << endl;
        return cumulativeRatios;
    }

    void displayResultantArray() const
    {
        for (int i = 0; i < newSize; i++)
        {
            cout << resultantArray[i] << ' ';
        }
        cout << endl;
    }

    void displayCount(int find) const
    {
        int count = 0;
        for (int i = 0; i < newSize; i++)
        {
            if (resultantArray[i] == find)
            {
                count += 1;
            }
        }
        cout << "Count of " << find << " : " << count << endl;
    }
};

#endif
