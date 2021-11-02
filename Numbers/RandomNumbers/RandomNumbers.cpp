#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
int main(int argc, char* argv[]){
    int iteration = 2000000;
    std::map<int, int> Amounts;
    srand(time(nullptr));
    for (int i = 0; i < iteration; i++){
        int numb = rand() % 20;
        Amounts[numb]++;
    }

   for (auto const& x : Amounts){
       float percent = (float) x.second / iteration;
       cout << "At " << x.first << ": " << x.second << "---" << percent * 100 << "%"  << endl;
       
   }

    return 0;
}
