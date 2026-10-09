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

    bender Kael("Kael", "Fire", 100, 58, 38, 88,
                {{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}});
    if (Kael.valid() == false)
    {
        cout << "OP OR UNDERPOWERED BENDER" << endl;
        return false;
    }
    bender Mira("Mira", "Water", 92, 50,  38, 88,
                {{"Water Whip", 35}, {"Tide Rush", 25}, {"Mist Veil", 0}, {"Tidal Wave", 70}});
    if (Mira.valid() == false)
    {
        cout << "OP OR UNDERPOWERED BENDER" << endl;
        return false;
    }
    Kael.display();
    Mira.display();
    // display part done
    // game starts now
    Kael.attack_bender(Mira,0);//attacks that i played
    Mira.attack_bender(Kael,1);//attacks that i played
    Kael.attack_bender(Mira,0);//attacks that i played
    
    
    return 0;
}