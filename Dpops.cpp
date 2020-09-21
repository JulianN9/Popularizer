#include "Dpops.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;

std::string culture, religion;

int tpops, rule;

int landpops, cappops, artpops, beaurpops, intelpops, clerkpops, offpops, craftpops, farmpops, serfpops, slavepops, soldierpops;

Dpops::Dpops(){
    culture = "";
    religion = "";
    tpops = 0, rule = 0;
    landpops = 0, cappops = 0; 
    artpops = 0, beaurpops = 0, intelpops = 0, clerkpops = 0, offpops = 0;
    craftpops = 0, farmpops = 0, serfpops = 0, slavepops = 0, soldierpops = 0;
}

Dpops::Dpops( std::string clt, std::string rlg, int culturepop, int culturerule ){
    culture = clt;
    religion = rlg;
    tpops = culturepop;
    rule = culturerule;
    landpops = 0, cappops = 0; 
    artpops = 0, beaurpops = 0, intelpops = 0, clerkpops = 0, offpops = 0;
    craftpops = 0, farmpops = 0, serfpops = 0, slavepops = 0, soldierpops = 0;
}

int Dpops::ruleout(){
    return rule;
}

void Dpops::print(){
    cout << "The " << religion << " " << culture << " population has " << tpops << " people, of which:" <<endl;
    cout << landpops << " are landowners, " << cappops << " are capitalists, " << artpops << " are artisans " << beaurpops << " are bureaucrats, " << intelpops << " are intellectuals, " << clerkpops << " are clerks, " << endl;
    cout << offpops << " are officers, " << craftpops << " are craftsmen, " << farmpops << " are farmers " << serfpops << " are serfs, " << slavepops << " are slaves, " << soldierpops << " are soldiers." << endl;
}

void Dpops::output(std::ofstream &outstream){
    if (landpops>1){
        outstream << "\taristocrats = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << landpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }
    if (cappops>1){
        outstream << "\tcapitalists = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << cappops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }
    if (artpops>1){
        outstream << "\tartisans = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << artpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }
    if (beaurpops>1){
        outstream << "\tbureaucrats = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << beaurpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }         
    if (intelpops>1){
        outstream << "\tclergymen = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << intelpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }   
    if (clerkpops>1){
        outstream << "\tclerks = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << clerkpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }         
    if (offpops>1){
        outstream << "\tofficers = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << offpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }
    if (craftpops>1){
        outstream << "\tcraftsmen = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << craftpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }    
    if (farmpops>1){
        outstream << "\tfarmers = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << farmpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }
    if (serfpops>1){
        outstream << "\tserfs = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << serfpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }     
    if (slavepops>1){
        outstream << "\tslaves = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << slavepops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }
    if (soldierpops>1){
        outstream << "\tsoldiers = { \n"
                  << "\t\tculture = " << culture << "\n"
                  << "\t\treligion = " << religion << "\n"
                  << "\t\tsize = " << soldierpops << "\n"
                  << "\t}" << "\n"
                  << "\n";
    }
}

int Dpops::rpops(){
    return tpops - ( landpops + cappops + artpops + beaurpops + intelpops + clerkpops + offpops + craftpops + farmpops + serfpops + slavepops + soldierpops );
}

int Dpops::popsout( int which ){
    int output;
    switch (which){
        case 1:
            output = landpops;
            break;
        case 2:
            output = cappops;
            break;
        case 3:
            output = offpops;
            break;
        case 4:
            output = beaurpops;
            break;
        case 5:
            output = intelpops;
            break;
        case 6:
            output = clerkpops;
            break;
        case 7:
            output = soldierpops;
            break;
        case 8:
            output = craftpops;
            break;
        case 9:
            output = artpops;
            break;
        case 10:
            output = farmpops;
            break;
        case 11:
            output = serfpops;
            break;
        case 12:
            output = slavepops;
            break;

        default:
            cout << "internal error 1" << endl;
            break;
    }
    return output;
}

void Dpops::addpops( int sol, int which ){
    switch (which){
        case 1:
            landpops += sol;
            break;
        case 2:
            cappops += sol;
            break;
        case 3:
            offpops += sol;
            break;
        case 4:
            beaurpops += sol;
            break;
        case 5:
            intelpops += sol;
            break;
        case 6:
            clerkpops += sol;
            break;
        case 7:
            soldierpops += sol;
            break;
        case 8:
            craftpops += sol;
            break;
        case 9:
            artpops += sol;
            break;
        case 10:
            farmpops += sol;
            break;
        case 11:
            serfpops += sol;
            break;
        case 12:
            slavepops += sol;
            break;

        default:
            cout << "internal error 2" << endl;
            break;
    }
}

bool Dpops::assignPops(std::vector<Dpops> &Vpops, int wc, int wj){
    int tracker = 0;
    int tally = 0;
    int total = 0;
    int length = Vpops.size();
    bool end;

    for( int i = 0; i < length; i++){
        int sc = Vpops[i].ruleout();
        if ( sc == wc ){
            total += Vpops[i].rpops();
        }
    }
    for( int i = 0; i < length; i++){
        int sc = Vpops[i].ruleout();
        if ( sc == wc ){
            if( total > popsout(wj) || popsout(wj) == 0 ){
                if ( popsout(wj) == 0) tracker= 0;
                else if( (popsout(wj)*Vpops[i].rpops())/total > 0 ) tracker = (popsout(wj)*Vpops[i].rpops())/total;
                else if( popsout(wj)*(Vpops[i].rpops()/total) > 0 ) tracker = popsout(wj)*(Vpops[i].rpops()/total);
                else if( Vpops[i].rpops()*(popsout(wj)/total) > 0 ) tracker = Vpops[i].rpops()*(popsout(wj)/total);
                else{
                    tracker = 0;
                    if( popsout(wj) != 1){
                        cout << "BIG ERROR, REPEAT: BIG FUCKING ERROR" << endl;
                    }
                } 
                Vpops[i].addpops(tracker,wj);
                tally += tracker;
            }
            else{
                tracker = Vpops[i].rpops();
                Vpops[i].addpops(tracker,wj);
                tally += tracker;
            }
        }
    }
    addpops(-1*tally, wj);

    if(popsout(wj)>0) end = false;
    else end = true;

    return end;
}

void getint(int &f, bool percent, bool crule, bool fourth){
    cin >> f;
    while (cin.fail() || f < 0 || ( f > 100 && percent ) || ( ( f > 3 || f < 1 ) && crule ) || ( ( f > 3 || f < 0 ) && fourth ) ){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        f = -1;
        cout << "Invalid input, try agian" << endl;
        cin >> f;
    }
}

void getstring(std::string &f){
    cin >> f;
    while (cin.fail() || f.empty() ){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Empty input, try agian" << endl;
        cin >> f;
    }
}
