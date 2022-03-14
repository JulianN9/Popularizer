#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "Dpops.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;

void populate( bool batch, bool percentage )
{
    vector<Dpops> Vpops;
    int sland, scap, sbeau, sintel, sclerk, soff, scraft, sart, ssold;
    int part, pfarm, pserf, pslave, pland, pcap, pbeau, pintel, pclerk, poff, pcraft, psold;
    int totalpercent = 0, culturepercent;
    string culture, religion;
    int totalpop, culturepop, crule, state;
    char input;
    bool loop = true;

    if(percentage)
    {
        cout << "Percentage of landowners (1=1%)?" << endl;
        getint(pland,true);
        cout << "Percentage of capitalists?" << endl;
        getint(pcap,true);
        cout << "Percentage of artisans?" << endl;
        getint(part, true);
        cout << "Percentage of bureaucrats?" << endl;
        getint(pbeau, true);
        cout << "Percentage of intelectuals?" << endl; 
        getint(pintel, true);
        cout << "Percentage of clerks?" << endl;
        getint(pclerk, true);
        cout << "Percentage of officers?" << endl;
        getint(poff, true);
        cout << "Percentage of craftsmen?" << endl;
        getint(pcraft, true);
        cout << "Percentage of soldiers?" << endl;
        getint(psold, true);
    }
    else
    {
        cout << "How many landowners?" << endl;
        getint(sland);
        cout << "How many capitalists?" << endl;
        getint(scap);
        cout << "Percentage of artisans (0=0%, 1=5%, 2=10%, 3=25%)?" << endl;
        getint(sart, true, false, true);
        switch (sart){
            case 0:
                part = 0;
                break;
            case 1:
                part = 5;
                break;
            case 2:
                part = 10;
                break;
            case 3:
                part = 25;
                break;
            default:
                cout << "error" << endl;
                break;
        }
        cout << "How many bureaucrats?" << endl;
        getint(sbeau);
        cout << "How many intellectuals?" << endl; 
        getint(sintel);
        cout << "How many clerks?" << endl;
        getint(sclerk);
        cout << "How many officers?" << endl;
        getint(soff);
        cout << "How many craftsmen?" << endl;
        getint(scraft);
        cout << "How many soldiers?" << endl;
        getint(ssold);
    }


    while ( loop )
    {
        int tland = sland, tcap = scap, tbeau = sbeau, tintel = sintel, tclerk = sclerk, toff = soff, tcraft = scraft, tsold = ssold;
        cout << "What is the province number" << endl;
        getint(state);
        cout << "What is the total population of the province (1 = 1k)?" << endl;
        getint(totalpop);
        totalpop *= 1000;
        int tart = (part*totalpop)/100;
        if(percentage){
            tland = (pland*totalpop)/100;
            cout << "The total amount of landowners is: " << tland << endl;
            tcap = (pcap*totalpop)/100;
            cout << "The total amount of capitalists is: " << tcap << endl;
            cout << "The total amount of artisans is: " << tart << endl;
            tbeau = (pbeau*totalpop)/100;
            cout << "The total amount of beaurocrats is: " << tbeau << endl;
            tintel = (pintel*totalpop)/100;
            cout << "The total amount of intellectuals is: " << tintel << endl;
            tclerk = (pclerk*totalpop)/100;
            cout << "The total amount of clerks is: " << tclerk << endl;
            toff = (poff*totalpop)/100;
            cout << "The total amount of officers is: " << toff << endl;
            tcraft = (pcraft*totalpop)/100;
            cout << "The total amount of craftsmen is: " << tcraft << endl;
            tsold = (psold*totalpop)/100;
            cout << "The total amount of soldiers is: " << tsold << endl;
        }
        else{
            cout << "The total amount of artisans is: " << tart << endl;
        }


        while (totalpercent != 100)
        {
            if (totalpercent > 100 || totalpercent < 0){;
                totalpercent = 0;
                cout << "Went over 100 percent, try again." << endl;
            }
            cout << "For the remainder (these three should add up to 100), what is the percentage of farmers (1 = 1%)?" << endl;
            getint(pfarm,true);
            cout << "Of serf?" << endl;
            getint(pserf,true);
            cout << "Of slaves?" << endl;
            getint(pslave,true); 

            totalpercent = pfarm + pserf + pslave;
        }


        totalpercent = 0;
        cout << "We will now loop through every culture and religion group in the state"<< endl;

        while(totalpercent != 100){
            if (totalpercent > 100 || totalpercent < 0){
                Vpops.clear();
                totalpercent = 0;
                cout << "Went over 100 percent, try again." << endl;
            }
            cout << "Population: " << Vpops.size()+1 << endl;
            cout << "What is the culture of this population (exact name for the file)?" << endl;
            getstring(culture);
            cout << "What is the religion of this culture (exact name)?" << endl;
            getstring(religion);
            cout << "Is this pop ruling (1), middle (2) or lower (3) class? (this determines distribution of jobs)" << endl;
            getint(crule,true,true);
            cout << "What is the percentage of the population of this province?" << endl;
            getint(culturepercent,true);


            culturepop = (culturepercent*totalpop)/100;

            Vpops.push_back(Dpops(culture,religion,culturepop,crule));

            totalpercent += culturepercent;
        }

        Dpops Totals = Dpops( "Totals","If you see this, you have an error",totalpop, 0 );
        Totals.addpops(tland,1);
        Totals.addpops(tcap,2);
        Totals.addpops(toff,3);
        Totals.addpops(tbeau,4);
        Totals.addpops(tintel,5);
        Totals.addpops(tclerk,6);
        Totals.addpops(tsold,7);
        Totals.addpops(tcraft,8);
        Totals.addpops(tart,9);

        int length = Vpops.size();
        int debug_a = 0;

        for( int i = 1; i < 10; i++){
            if(Totals.assignPops(Vpops,1,i)){
                if(Totals.assignPops(Vpops,2,i)){
                    if(Totals.assignPops(Vpops,3,i)){
                        debug_a ++;
                    }
                }
            }
        }
        cout << debug_a << endl;

        for( int i = 0; i < length; i++){
            int farmers, serfs, slaves;
            farmers = (pfarm*Vpops[i].rpops())/100;
            serfs = (pserf*Vpops[i].rpops())/100;
            slaves = (pslave*Vpops[i].rpops())/100;
            Vpops[i].addpops(farmers,10);
            Vpops[i].addpops(serfs,11);
            Vpops[i].addpops(slaves,12);
        }


        string filename = std::to_string(state) + ".txt";

        ofstream outflow;
        outflow.open (filename);

        outflow << std::to_string(state) << " = {\n";
        for( int i = 0; i < length; i++){
            Vpops[i].print();
            Vpops[i].output(outflow);
        }
        outflow << "}";

        outflow.close();
        Vpops.clear();

        if (!batch){
            loop = false;
        }
        else{
            cout << "Do you want to continue this batch? (y/n)" << endl;
            cin >> input;
            if( input != 'y'){
                loop = false;
            }
        }
    }

}

int main (){
    bool batch = false, realinput = false, run = true, percentage = false;
    char input;

    cout << "Welcome, do you wan to run in batch mode (y/n/h)" << endl;
    while ( !realinput ){
        cin >> input;
        switch (input)
        {
            case 'y':
                batch = true;
                realinput = true;
                break;
            case 'n':
                realinput = true;
                break;
            case 'h':
                cout << "Batch mode allows multiple provinces with the same pop distribution to be done consecutively"<<endl;
                break;
            default:
                break;
        }
    }

    realinput = false;
    cout << "Do you wan to use percentages instead of numbers for pops? (y/n/h)" << endl;
    while ( !realinput ){
        cin >> input;
        switch (input)
        {
            case 'y':
                percentage = true;
                realinput = true;
                break;
            case 'n':
                percentage = false;
                realinput = true;
                break;
            case 'h':
                cout << "Percentage mode (y) makes all inputs percentages (inputted 0-100), turning it off (n) will only leave artisan and farmer/slave/serf pops as percentages."<<endl;
                break;
            default:
                break;
        }
    }

    while( run ){
        populate( batch, percentage );
        cout << "Do you want to run again? (y/n)" << endl;
        cin >> input;
        switch (input)
        {
        case 'y':
            break;
        
        default:
            run = false;
            break;
        }
    }

    return 0;
}