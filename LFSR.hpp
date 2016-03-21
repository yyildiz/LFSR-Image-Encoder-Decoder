#ifndef LFSR_HPP
#define LFSR_HPP

#include <iostream>
#include <vector>
#include <string>

class LFSR{
    public:
        LFSR(std::string seed, int tap);
        int step();
        int generate(int k);
        friend std::ostream& operator<< (std::ostream& stream, LFSR const& lfsr);
        std::vector<int> stringToVector(std::string str);
    private:
        std::vector<int> _seed;
        int _tap;
};

#endif
