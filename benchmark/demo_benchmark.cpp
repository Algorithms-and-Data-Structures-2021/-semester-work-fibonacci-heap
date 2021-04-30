#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

#include "data_structure.hpp"

using namespace std;
using namespace itis;

static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

vector<int> split(const std::string &s, char delimiter) {
  vector<int> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}

// спросить про нахождение минимума
// спросить про путь к файлу
// что должно быть в папке "тестовые наборы"
// а еще у нас insert вставляет все числа сразу

int main(int argc, char** argv) {
// путь до папки
  string pathToInputFile = R"(D:\AaDS\semester-work-fibonacci-heap-new\dataset\input-25000-0.txt)";

  ifstream file(pathToInputFile);
  string result;
  string line;

 while (getline(file, line)) {

   fibbHeap *testHeap = new fibbHeap;
   vector<int> intValues = split(line, ' ');

      //insert
   double startTime = clock();
   for (int value : intValues) {
     testHeap->insert(value);
   }
   double endTime = clock();

   cout << to_string(endTime - startTime) + " ";

      //find min
   startTime = clock();
   testHeap->findMin();
   endTime = clock();
   cout << to_string(endTime - startTime) + " ";

      //extract min
   startTime = clock();
   testHeap->extractMin();
   endTime = clock();
   cout << to_string(endTime - startTime) + " \n";
 }

    file.close();
    return 0;
}