#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

class Dpops{
private:
    std::string culture, religion;

    int tpops, rule;

    int landpops, cappops, artpops, beaurpops, intelpops, clerkpops, offpops, craftpops, farmpops, serfpops, slavepops, soldierpops;

public:
    Dpops();

    Dpops( std::string clt, std::string rlg, int culturepop, int culturerule );

    int ruleout();

    void print();

    void output(std::ofstream &outstream);

    int rpops();

    int popsout( int which );

    void addpops( int sol, int which );

    bool assignPops(std::vector<Dpops> &Vpops, int wc, int wj);
};

void getint(int &f, bool percent = false, bool crule = false);

void getstring(std::string &f);

void calcRemaining(int *nc, std::vector<Dpops> Vpops);