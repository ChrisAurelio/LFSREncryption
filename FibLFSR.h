#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class FibLFSR {

    public:
        FibLFSR(string seed);

        int step();

        int generate(int k);

        friend ostream& operator<< (ostream &out, const FibLFSR &f);

    private:
        vector<int> reg;
        int left;
        int right;
        int tab1;
        int tab2;
        int tab3;
};

void transform(sf::Image&, FibLFSR*);

#endif
