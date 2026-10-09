#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
// vector pair//
//  vector<pair<int ,string>> x;
//  x.first---> int and x.second---> string
string elementOrder[4] = {"Water", "Fire", "Air", "Earth"};
        int ElementIndex(string element)
        {
            for (int i = 0; i < 4; i++)
            {
                if (elementOrder[i] == element)
                {
                    return i;
                }
            }
            return false;
        }
            double multiplier(string attacker, string defender)
            {
                int attackerIndex = ElementIndex(attacker);
                int defenderIndex = ElementIndex(defender);
                if ((attackerIndex + 1) % 4 == (defenderIndex))
                {
                    return 2.0;
                }
                if ((defenderIndex + 1) % 4 == (attackerIndex))
                {
                    return 0.5;
                }
                else
                    return 1.0;
            }
        
        bool is_crit_hit()
        {
            if (rand() % 10 == 0)
            {
              
                return true;
            }
            return false;
        }
class bender
{ // constructor decl.
    string name, element;
    int hp, maxHp, attack, defense, speed;
    vector<pair<string, int>> moves;

public:
    bender(string n, string e, int h, int a, int d, int s, vector<pair<string, int>> m); // constructor
    // display f(x)
    bool valid();
    // doing all this cause ai told using friend f(x) arent the "true spirit" of OOP's encapsulation
    int getSpeed();
    int getAttack();
    int getDefense();
    int getHP();
    int getmaxHp();
    string getName();
    string getElement();
    // attack feat.
    bool attack_bender(bender &Defender, int a);
    bool checkFaint(bender &Defender);
};
// class ends
// constructor defn.
bender::bender(string n, string e, int h, int a, int d, int s, vector<pair<string, int>> m)
{
    name = n;
    element = e;
    hp = h;
    attack = a;
    maxHp = h;
    defense = d;
    speed = s;
    moves = m;
}

// check validity f(x)
bool bender::valid()
{
    if ((hp <= 200 && hp > 0) && (attack <= 100 && attack > 0) && (defense <= 100 && defense > 0) && (speed) <= 100 && speed > 0)
        return true;
    else
    {
        return false;
    }
}
int bender::getAttack()
{
    return attack;
}
int bender::getDefense()
{
    return defense;
}
int bender::getSpeed()
{
    return speed;
}
int bender::getHP()
{
    return hp;
}
int bender::getmaxHp()
{
    return maxHp;
}
string bender::getName()
{
    return name;
}
string bender::getElement()
{
    return element;
}
// attack f(x)----------------------------------------------------------------------------------------------------------------
bool bender::attack_bender(bender &Defender, int moveIndex)
{
    if (moveIndex > 3 || moveIndex < 0)
    {
        cout << "Invalid attack" << endl;
        return false;
    }
    else
    {
    
        cout << name << " used " << moves[moveIndex].first << "!" << endl;
     // kael used shyt!
     bool wasCrit=is_crit_hit();
     int attackerIndex = ElementIndex(element);
     int defenderIndex = ElementIndex(Defender.getElement());
        if ((attackerIndex + 1) % 4 == (defenderIndex))
        {
            cout << "Super Effective" << endl;
        
        }
        if ((defenderIndex + 1) % 4 == (attackerIndex))
        {
            cout << "Not Very Effective" << endl;
        }
if (wasCrit==true)
{
    cout<<"Critical Hit!!!!"<<endl;
}

        int damage = round((attack * moves[moveIndex].second) / static_cast<double>(Defender.getDefense()));
        double type_multiplier = multiplier(element, Defender.getElement());
        double critical_multiplier=1.0;
        if (wasCrit==true)
        {
        critical_multiplier = 2.0;
        }
        else
        {
            int critical_multiplier = 1.0;
        }
        double final_damage = damage * type_multiplier * critical_multiplier;
        int finalDamage = max(1, static_cast<int>(round(final_damage)));
        Defender.hp = Defender.hp - finalDamage;
        cout << Defender.getName() << " took " << finalDamage << " damage!" << endl
             << endl;
        // checkFaint(Defender);

        if (checkFaint(Defender) == true)
        {
            cout << Defender.getName() << " fainted!"<<endl;
            cout<< name<<" wins the duel!"<<endl<<endl;
        }
        if (wasCrit==true)
        {
            return true;
        }
        else { return false;}
        
    }
}
    // attack f(x) ends---------------------------------------------------------------------------------------------------------------
    bool bender::checkFaint(bender & Defender)
    {
        if (Defender.hp <= 0)
        {
            Defender.hp = 0;
            return true;
        }
        return false;
    }
    // duel class start
    class duel
    {
        bender &opp1, &opp2;
        int turns=0;
        int count_critical_hits=0;

    public:
        duel(bender &a, bender &b);
        void start_duel();
        void turns_of_battle();
        void gameover();
    };
    duel::duel(bender & a, bender & b) : opp1(a), opp2(b) {}
    // member initialization list ":" , i was using normal opp1 = a first and getting error but ai told me it
    //  doesnt have any meaning as a reference should have address from "birth" so use ":".
    void duel::start_duel()
    {
        cout << "=== DUEL BEGINS! ===" << endl;
        cout << opp1.getName() << " (" << opp1.getElement() << ", HP: " << opp1.getHP() << "/" << opp1.getmaxHp() << ")" << " VS ";
        cout << opp2.getName() << " (" << opp2.getElement() << ", HP: " << opp2.getHP() << "/" << opp2.getmaxHp() << ")" << endl;
      turns_of_battle();
        // cout << "Turn " << "1: " << (opp1.getSpeed() > opp2.getSpeed() ? opp1.getName() : opp2.getName()) << " goes first!" << endl; // ternary op.
    }
void duel::turns_of_battle()
{
    bool opp1GoesNext;

    if (opp1.getSpeed() > opp2.getSpeed())
    {
        opp1GoesNext = true;
    }
    else if (opp2.getSpeed() > opp1.getSpeed())
    {
        opp1GoesNext = false;
    }
    else
    {
        opp1GoesNext = (rand() % 2 == 0);
        cout<<"As Benders have same speed, We go to a toss"<<endl;
        cout<<(opp1GoesNext ? opp1.getName() : opp2.getName() );
        cout<<" Won the toss"<<endl;
        
    }

    while (opp1.getHP() > 0 && opp2.getHP() > 0)
    {
        turns++;

        if (opp1GoesNext)
        {
            cout << "Turn " << turns << ": " << opp1.getName() << "'s turn!" << endl;
            int move;
            cout << "Enter move (0-3) for " << opp1.getName() << ": ";
            cin >> move;
            cout<<endl;
            bool wasCrit = opp1.attack_bender(opp2, move);
            if (wasCrit) count_critical_hits++;
        }
        else
        {
            cout << "Turn " << turns << ": " << opp2.getName() << "'s turn!" << endl;
            int move;   
            cout << "Enter move (0-3) for " << opp2.getName() << ": ";
            cin >> move;
            cout<<endl;
            bool wasCrit = opp2.attack_bender(opp1, move);
            if (wasCrit) count_critical_hits++;
        }

        opp1GoesNext = !opp1GoesNext; // flip whose turn it is
    }

    gameover();
}  
void duel::gameover(){
bender *winner=(opp1.getHP()>0)? &opp1 : &opp2;
cout<<"Duel Summary:"<<endl;
cout<<"- Winner: "<<winner->getName()<<endl;//new thing pointers access member f(x) with "->" and not "."
cout<<"- Turns: "<<turns<<endl;
cout<<"- Critical Hits: "<<count_critical_hits<<endl;
}
    int main()
    {
        srand(time(0));
      bender Nadia("Nadia","Water",85,48,60,72,{{"Wave Crash",35},{"Splash Kick",25},{"Guard",0},{"Riptide",50}});
      bender Talon("Talon","Air",90,52,55,72,{{"Gale Strike",38},{"Wind Cutter",28},{"Updraft",0},{"Cyclone Blast",48}});
      if (Nadia.valid()==false||Talon.valid()==false)
      {
        cout<<"OP OR UNDERPOWERED BENDER"<<endl;
        return false;
      }
      duel Duel2(Nadia,Talon);
      Duel2.start_duel();
        return 0;
    }
