#include "FibLFSR.h"

FibLFSR::FibLFSR(string seed) {

    for(int i = 0; i < 16; i++) {

        reg.push_back(seed[i]);
    }
}

int FibLFSR::step() {

    vector<int> seedReg = reg;

    left = seedReg[0];
    tab1 = seedReg[2];
    tab2 = seedReg[3];
    tab3 = seedReg[5];

    right = left ^ tab1 ^ tab2 ^ tab3;
    
    reg.erase(reg.begin());
    reg.push_back(right);

    return right;
}

int FibLFSR::generate(int k) {

    int binToDec = 0;

    for(int i = 0; i < k; i++) {
            
        int currBit = step();
        binToDec = (binToDec << 1) + currBit;
    }

    return binToDec;
}

ostream& operator<< (ostream &out, const FibLFSR &f) {

    for(int i = 0; i < 16; i++) {

        out << f.reg[i];
    }

    return out;
}
