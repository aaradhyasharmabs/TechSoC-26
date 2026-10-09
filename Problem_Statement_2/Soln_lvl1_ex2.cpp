#include <iostream>
#include <vector>
#include <string>
#include <array>
#include<cmath>
using namespace std;
// vector pair//
//  vector<pair<int ,string>> x;
//  x.first---> int and x.second---> string
class bender
{ // constructor decl.
    string name, element;
    int hp, maxHp, attack, defense, speed;
    vector<pair<string, int>> moves;

public:
    bender(string n, string e, int h, int a,  int d, int s, vector<pair<string, int>> m); // constructor
    // display f(x)
    void display();
    bool valid();
    //doing all this cause ai told using friend f(x) arent the "true spirit" of OOP's encapsulation
    int getSpeed();
    int getAttack();
    int getDefense();
    int getHP();
    string getName();
    //attack feat.
    void attack_bender(bender& Defender, int a);
    bool checkFaint(bender& Defender);
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
// display f(x)
void bender::display()
{
    cout << name << ' ' << "(" << element << ")" << " - " << "HP: " << hp << "/" << maxHp << ", " << "Attack: " << attack << " Defence: " << defense << " Speed: " << speed << endl;
    cout << "Moves: ";
    for (auto x : moves)
    {
        cout << x.first << "(" << x.second << "), ";
    }
    cout << endl
         << endl;
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
//prep for lvl 2,3
int bender::getAttack(){
    return attack;
}
int bender::getDefense(){
    return defense;
}
int bender::getSpeed(){
    return speed;
}
int bender::getHP(){
    return hp;
}
string bender::getName(){
    return name;
}
void bender::attack_bender(bender& Defender , int moveIndex){
if (moveIndex>3||moveIndex<0)
{
cout<<"Invalid attack"<<endl;
return;
}
else{
    int damage=round((attack * moves[moveIndex].second) / static_cast<double>(Defender.getDefense()));
   Defender.hp =Defender.hp-damage;
   cout<<name<<" used "<<moves[moveIndex].first<<"!"<<endl;
   cout<<Defender.getName()<<" took "<<damage<<" damage!"<<endl<<endl;
   checkFaint(Defender);
Defender.display();
if (checkFaint(Defender)==true)
{
    cout<<Defender.getName()<<" fainted: True"<<endl<<endl;
}
else{
    cout<<Defender.getName()<<" fainted: False"<<endl<<endl;
}
}
}
bool bender::checkFaint(bender& Defender){
if (Defender.hp<=0)
{
    Defender.hp=0;
    return true;
}
return false;


}
int main()
{
bender Zephyr("Zephyr","Air",28,12,50,95,{{"Gust",0},{"Wind Slap",18},{"Tumble",12},{"Cyclone",22}});
bender Doran("Doran","Earth",145,80,75,40,{{"Boulder Throw",75},{"Rock Fist",42},{"Tremor",48},{"Mountain Crush",85}});
    if (Zephyr.valid() == false)
    {
        cout << "OP OR UNDERPOWERED BENDER" << endl;
        return false;
    }
    if (Doran.valid() == false)
    {
        cout << "OP OR UNDERPOWERED BENDER" << endl;
        return false;
    }
Zephyr.display();
Doran.display();
Doran.attack_bender(Zephyr,0);

    return 0;
}