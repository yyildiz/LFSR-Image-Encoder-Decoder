#include "LFSR.hpp"

using namespace std;

LFSR::LFSR(string seed, int tap){
    _seed = stringToVector(seed);
    if(tap <= (int)_seed.size()){
        _tap = tap;
    }
}

int LFSR::step(){
    int tapPos = _seed.size() - _tap - 1;
    int s	= _seed[0] ^ _seed[tapPos];
    _seed.erase(_seed.begin());
    _seed.insert(_seed.end(), s);

    return s;

}

int LFSR::generate(int k){
    int var = 0;
    for(int i = 0; i < k; i++){
        var = var*2 + step();
    }
    return var;
}

vector<int> LFSR::stringToVector(string str){
    int a;
    std::vector<int> vec;
    for(int i = 0; i < (int)str.length(); i++){
        a = str[i]-48;
        vec.push_back(a);
    }
    return vec;
}

std::ostream& operator<< (std::ostream& stream, LFSR const& lfsr){
    for(int i = 0; i < (int)lfsr._seed.size(); i++){
        stream << lfsr._seed[i];
    }
    return stream;
}
