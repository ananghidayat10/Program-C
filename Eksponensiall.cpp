#include <iostream>
#include <cmath>

using namespace std;

// Mencari Persamaan Linear
const int n = 7; //n a/ Jumlah data
int data[n][2] = { //2 a/ XnYn
  { 1, 2 },
  { 3, 5 },
  { 7, 12 },
  { 9, 14 },
  { 11, 15 },
  { 20, 20 },
  { 22, 25 }
};

int main () {
  int sumXY = 0, sumX = 0, sumY = 0, sumX2 = 0;

  for (int i = 0; i < n; ++i) {
    sumXY += data[i][0] * data[i][1];
    sumX += data[i][0];
    sumY += data[i][1];
    sumX2 += pow(data[i][0], 2);
  }
//Mencari Rata-Rata X,Y
  float avgY = sumY / n;
  float avgX = sumX / n;

  float a1 = (n * sumXY - sumX * sumY)
           / (n * sumX2 - pow(sumX, 2));

  float a0 = avgY - a1 * avgX;

  float totalErrorY = 0;

  for (int i = 0; i < n; ++i) {
    float prediction = a0 + a1 * data[i][0];
    totalErrorY += abs(data[i][1] - prediction);
  }

  float meanAbsErrorY = totalErrorY / n;

  cout << "y = "
       << a0
       << " + "
       << a1
       << "x"
       << ", err ~"
       << meanAbsErrorY
       << endl;

  return 0;
}
