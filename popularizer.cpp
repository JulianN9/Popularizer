#include <string>
#include <iostream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Dpops{
        string culture, religion;
        int tpops, rule, landpops = 0, cappops = 0; 
        int artpops = 0, beaurpops = 0, intelpops = 0, clerkpops = 0, offpops = 0;
        int craftpops = 0, farmpops = 0, labpops = 0, serfpops = 0, slavepops = 0, soldierpops = 0;
    public:
        Dpops();
        int ruleout(){
            return rule;
        }
        void print(){
            cout << "The " << religion << " " << culture << " population has " << tpops << " people, of which:" <<endl;
            cout << landpops << " are landowners, " << cappops << " are capitalists, " << artpops << " are artisans " << beaurpops << " are beaurocrats, " << intelpops << " are intellectuals, " << clerkpops << " are clerks, " << endl;
            cout << offpops << " are officers, " << craftpops << " are craftsmen, " << farmpops << " are farmerns " << labpops << " are labourers, " << serfpops << " are serfs, " << slavepops << " are slaves, " << soldierpops << " are soldiers." << endl;
        }
        int rpops(){
            return tpops - ( landpops + cappops + artpops + beaurpops + intelpops + clerkpops + offpops + craftpops + farmpops + labpops + serfpops + slavepops + soldierpops );
        }
        void addpops( int sol, int which ){
            switch (which)
            {
                case 1:
                    landpops = sol;
                    break;
                case 2:
                    cappops = sol;
                    break;
                case 3:
                    artpops = sol;
                    break;
                case 4:
                    beaurpops = sol;
                    break;
                case 5:
                    intelpops = sol;
                    break;
                case 6:
                    clerkpops = sol;
                    break;
                case 7:
                    offpops = sol;
                    break;
                case 8:
                    craftpops = sol;
                    break;
                case 9:
                    farmpops = sol;
                    break;
                case 10:
                    labpops = sol;
                    break;
                case 11:
                    serfpops = sol;
                    break;
                case 12:
                    slavepops = sol;
                    break;
                case 13:
                    soldierpops = sol;
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        }
        Dpops( string clt, string rlg, int culturepop, int culturerule ){
            culture = clt;
            religion = rlg;
            tpops = culturepop;
            rule = culturerule;
        }
};

void getint(int &f, bool percent = false, bool crule = false){
    cin >> f;
    while (cin.fail() || f < 0 || ( f > 100 && percent ) || ( ( f > 3 || f < 1 ) && crule ) ){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        f = -1;
        cout << "Invalid input, try agian" << endl;
        cin >> f;
    }
}

void calcRemaining(int *nc, vector<Dpops> Vpops){
    nc[0] = 0;
    nc[1] = 0;
    nc[2] = 0;

    int length = Vpops.size();
    for( int i = 0; i < length; i++ ){
        int sc = Vpops[i].ruleout();
        switch (sc)
        {
            case 1:
                nc[0] += Vpops[i].rpops();
                break;
            case 2:
                nc[1] += Vpops[i].rpops();
                break;
            case 3:
                nc[2] += Vpops[i].rpops();
                break;
            default:
                break;
        }
    }
}

void assignRich(vector<Dpops> &Vpops, int *nc, int *tc, int j, int &tland, int &tcap){
    int landtracker = 0, captracker = 0, landtoremove, captoremove;
    int length = Vpops.size();
    for( int i = 0; i < length; i++){
        int sc = Vpops[i].ruleout();
        if ( sc == (j+1) ){
            if( nc[j] > tc[0] ){
                landtoremove = (tland*Vpops[i].rpops())/nc[j];
                captoremove = (tcap*Vpops[i].rpops())/nc[j];
                Vpops[i].addpops(landtoremove,1);
                Vpops[i].addpops(captoremove,2);
                landtracker += landtoremove;
                captracker += captoremove;
            }
            else{
                landtoremove = (tland*Vpops[i].rpops())/tc[0];
                captoremove = (tcap*Vpops[i].rpops())/tc[0];
                Vpops[i].addpops(landtoremove,1);
                Vpops[i].addpops(captoremove,2);
                landtracker += landtoremove;
                captracker += captoremove;
            }
        }
    }
    tland -= landtracker;
    tcap -= captracker;
    tc[0] -= (landtracker + captracker);
}

void assignMiddle(vector<Dpops> &Vpops, int *nc, int *tc, int j, int &tart, int &tbeau, int &tintel, int &tclerk, int &toff){
    int arttracker = 0, beautracker = 0, inteltracker = 0, clerktracker = 0, offtracker = 0;
    int arttoremove, beautoremove, inteltoremove, clerktoremove, offtoremove;
    int length = Vpops.size();
    for( int i = 0; i < length; i++){
        int sc = Vpops[i].ruleout();
        if( sc == j+1){
            if( nc[j] > tc[1] ){
                arttoremove = (tart*Vpops[i].rpops())/nc[j];
                beautoremove = (tbeau*Vpops[i].rpops())/nc[j];
                inteltoremove = (tintel*Vpops[i].rpops())/nc[j];
                clerktoremove = (tclerk*Vpops[i].rpops())/nc[j];
                offtoremove = (toff*Vpops[i].rpops())/nc[j];
                Vpops[i].addpops(arttoremove,3);
                Vpops[i].addpops(beautoremove,4);
                Vpops[i].addpops(inteltoremove,5);
                Vpops[i].addpops(clerktoremove,6);
                Vpops[i].addpops(offtoremove,7);
                arttracker += arttoremove;
                beautracker += beautoremove;
                inteltracker += inteltoremove;
                clerktracker += clerktoremove;
                offtracker += offtoremove;
            }
            else{
                arttoremove = (tart*Vpops[i].rpops())/tc[1];
                beautoremove = (tbeau*Vpops[i].rpops())/tc[1];
                inteltoremove = (tintel*Vpops[i].rpops())/tc[1];
                clerktoremove = (tclerk*Vpops[i].rpops())/tc[1];
                offtoremove = (toff*Vpops[i].rpops())/tc[1];
                Vpops[i].addpops(arttoremove,3);
                Vpops[i].addpops(beautoremove,4);
                Vpops[i].addpops(inteltoremove,5);
                Vpops[i].addpops(clerktoremove,6);
                Vpops[i].addpops(offtoremove,7);
                arttracker += arttoremove;
                beautracker += beautoremove;
                inteltracker += inteltoremove;
                clerktracker += clerktoremove;
                offtracker += offtoremove;
            }
        }
    }
    tart -= arttracker;
    tbeau -= beautracker;
    tintel -= inteltracker;
    tclerk -= clerktracker;
    toff -= offtracker;
    tc[1] -= (arttracker + beautracker + inteltracker + clerktracker + offtracker);
}

void assignPoor(vector<Dpops> &Vpops, int *nc, int *tc, int j, int &tcraft, int &tsold){
    int crafttracker = 0, soldiertracker = 0, crafttoremove, soldtoremove;
    int length = Vpops.size();
    for( int i = 0; i < length; i++){
        int sc = Vpops[i].ruleout();
        if ( sc == j+1 ){
            if( nc[j] > tc[2] ){
                crafttoremove = (tcraft*Vpops[i].rpops())/nc[j];
                soldtoremove = (tsold*Vpops[i].rpops())/nc[j];
                Vpops[i].addpops(crafttoremove,8);
                Vpops[i].addpops(soldtoremove,13);
                crafttracker += crafttoremove;
                soldiertracker += soldtoremove;
            }
            else{
                crafttoremove = (tcraft*Vpops[i].rpops())/tc[2];
                soldtoremove = (tsold*Vpops[i].rpops())/tc[2];
                Vpops[i].addpops(crafttoremove,8);
                Vpops[i].addpops(soldtoremove,13);
                crafttracker += crafttoremove;
                soldiertracker += soldtoremove;
            }
        }
    }
    tcraft -= crafttracker;
    tsold -= soldiertracker;
    tc[0] -= (crafttracker + soldiertracker);
}

void populate( bool batch )
{
    vector<Dpops> Vpops;
    int tland, tcap, tart, tbeau, tintel, tclerk, toff, tcraft, pfarm, plab, pserf, pslave, tsold;
    int totalpercent = 0, culturepercent;
    string culture, religion;
    int totalpop, culturepop, crule, state;
    char input;
    bool loop;

    cout << "How many landowners?" << endl;
    getint(tland);
    cout << "How many capitalists?" << endl;
    getint(tcap);
    cout << "How many artisans?" << endl;
    getint(tcap);
    cout << "How many beaurocrats?" << endl;
    getint(tbeau);
    cout << "How many intelectuals?" << endl; 
    getint(tintel);
    cout << "How many clerks?" << endl;
    getint(tclerk);
    cout << "How many officers?" << endl;
    getint(toff);
    cout << "How many craftsmen?" << endl;
    getint(tcraft);
    cout << "How many soldiers?" << endl;
    getint(tsold);


    while ( loop )
    {
        cout << "What is the state number" << endl;
        getint(state);
        cout << "What is the total population of the state (1 = 1k)?" << endl;
        getint(totalpop);
        totalpop *= 1000;

        while (totalpercent != 100)
        {
            if (totalpercent > 100 || totalpercent < 0){;
                totalpercent = 0;
                cout << "Went over 100 percent, try again." << endl;
            }
            cout << "For the remainder, what is the percentage of laborers (10 = 10%)?" << endl;
            getint(plab,true);
            cout << "Of farmers?" << endl;
            getint(pfarm,true);
            cout << "Of serf?" << endl;
            getint(pserf,true);
            cout << "How many slaves?" << endl;
            getint(pslave,true); 

            totalpercent = plab + pfarm + pserf + pslave;
        }


        totalpercent = 0;
        cout << "We will now loop through every population in the state"<< endl;

        while(totalpercent != 100){
            if (totalpercent > 100 || totalpercent < 0){
                Vpops.clear();
                totalpercent = 0;
                cout << "Went over 100 percent, try again." << endl;
            }
            cout << "Population: " << Vpops.size()+1 << endl;
            cout << "What is the culture of this population (exact name for the file)?" << endl;
            cin >> culture;
            cout << "What is the religion of this culutre (exact name)?" << endl;
            cin >> religion;
            cout << "Is this pop ruling (1), middle (2) or lower (3) class?" << endl;
            getint(crule,true,true);
            cout << "What is the percentage of the population of the state?" << endl;
            getint(culturepercent,true);


            culturepop = (culturepercent*totalpop)/100;

            Vpops.push_back(Dpops(culture,religion,culturepop,crule));

            totalpercent += culturepercent;
        }

        int length = Vpops.size();
        int nc [3] = {0,0,0};
        int tc [3] = {tland + tcap,tart + tbeau + tintel + tclerk + toff,0};
        tc[2] = totalpop - ( tc[0] + tc[1]);

        calcRemaining(nc, Vpops);

        assignRich( Vpops, nc, tc, 0, tland, tcap);

        if (tc[0] > 0){
            calcRemaining(nc, Vpops);

            assignRich( Vpops, nc, tc, 1, tland, tcap);

            if (tc[0] > 0){
                calcRemaining(nc, Vpops);

                assignRich( Vpops, nc, tc, 2, tland, tcap);
            }
        }

        calcRemaining(nc, Vpops);

        assignMiddle( Vpops, nc, tc, 0, tart, tbeau, tintel, tclerk, toff);

        if (tc[1] > 0){
            calcRemaining(nc, Vpops);

            assignMiddle( Vpops, nc, tc, 1, tart, tbeau, tintel, tclerk, toff);

            if (tc[1] > 0){
                calcRemaining(nc, Vpops);

                assignMiddle( Vpops, nc, tc, 2, tart, tbeau, tintel, tclerk, toff);
            }
        }

        calcRemaining(nc, Vpops);

        assignPoor(Vpops, nc, tc, 0, tcraft, tsold);

        if (tc[2] > 0){
            calcRemaining(nc, Vpops);

            assignPoor(Vpops, nc, tc, 1, tcraft, tsold);

            if (tc[2] > 0){
                calcRemaining(nc, Vpops);

                assignPoor(Vpops, nc, tc, 2, tcraft, tsold);
            }
        }

        for( int i = 0; i < length; i++){
            int farmers, laborers, serfs, slaves;
            farmers = (pfarm*Vpops[i].rpops())/100;
            laborers = (plab*Vpops[i].rpops())/100;
            serfs = (pserf*Vpops[i].rpops())/100;
            slaves = (pslave*Vpops[i].rpops())/100;
            Vpops[i].addpops(farmers,9);
            Vpops[i].addpops(laborers,10);
            Vpops[i].addpops(serfs,11);
            Vpops[i].addpops(slaves,12);
        }
        for( int i = 0; i < length; i++){
            Vpops[i].print();
        }

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
    bool batch = false, realinput = false, run = true;
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

    while( run ){
        populate( batch );
        cout << "Do you want to run again?" << endl;
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