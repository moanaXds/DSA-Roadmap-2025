#ifndef VECTOR_H
#define VECTOR_H



#include <iostream>
#include <string>

using namespace std;

// ------------------- HERO CLASS -------------------
class Hero {
private:
    // TODO: Add data members for hero attributes
    // ID, name, level, power, health, levelup amount
    int id; 
    string name; 
    int level; 
    int power;
    int health;
    int levelupAmount;

public:
    // TODO: Create constructors
    Hero(){}

    Hero(int id,string name, int lev, int pow,int health, int amount):id(id), name( name), level(lev), power(pow),health(health),levelupAmount(amount){}

    // TODO: Add methods for leveling up, taking damage, and displaying stats
    void levelingUp()
    {
        level++;
        power= power+levelupAmount;
        cout<<"Level : "<<level <<" "<<"power :"<<power;
    }

    void TakingDamage(int damage)
    {
        health-=damage;
    }

    int getpower()const
    {
        return power;
    }

    int gethealth()const
    {
        return health;
    }

    int getlevel()
    {
        return level;
    }

    int getid()
    {
        return id;
    }

    string getname()const
    {
        return name;
    }

    void display()
    {
        cout<<"\n----------------------\n";
        cout<<"name :"<<name<<" "<<"Level : "<<level <<" "<<"power :"<<power<<"Health "<<" "<<health;
        cout<<"\n----------------------\n";
    }
};


// ------------------- BATTLE CLASS -------------------
class Battle {
private:
    // TODO: Add attributes for battle name, hero array, capacity, and size
    Hero* arr;
    string bname;
    int size;
    int capacity;

public:
    // TODO: Add constructor and destructor
    Battle(string name, int capcity): bname(name), capacity(capcity)  
    {
        size=0;
        arr= new Hero[capacity];
    }
    
    ~Battle()
    {
        delete[] arr;
    }
    
    // TODO: Add methods to:
    // - Add a hero
    void AddHero(Hero & other)
    {
        if(size<capacity)
        {
            arr[size]=other;
            size++;
        }
        else
        {
            cout<<"space is full";

        }
        
    }
    // - Remove a hero
        // Remove a hero (by ID)
    void removeHero(int id) 
    {
        bool found = false;
        for(int i = 0; i<size; i++) 
        {
            if(arr[i].getid()==id) 
            {
                for(int j=i; j<size-1; j++) 
                {
                    arr[j]=arr[j+1];
                }
                size--;
                found= true;
                cout<<"Hr0o removed\n";
                break;
            }
        }
        if(!found) cout<<"Hero not fond\n";
    }
    // - Display all heroes
    void Display()
    {
        for(int i=0; i<size;i++)
        {
            arr[i].display();
        }
    }

    // - Find strongest hero
    void strong()
    {
        int index=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i].getpower()>arr[index].getpower())
            {
                index=i;
            }
        }
        cout<<"Strongest :\n";
        arr[index].display();
    }


    // - Calculate average power
    void avg()
    {
        int average=0; 
        for(int i=0;i<size;i++)
        {
           average=average+arr[i].getpower();
        }
        cout<<"Heroaverage power :"<< average/size;
    }



    // - Simulate damage
    void Stimulate(int damage)
    {
        for(int i=0;i<size;i++)
        {
            arr[i].TakingDamage(damage);
        }
        cout<<"damage :"<<damage;
    }



    // - Level up a specific hero
    void levelUP( int id)
    {
        for(int i=0 ;i<size; i++)
        {
            if(arr[i].getid()==id)
            {
                arr[i].levelingUp();
                return;
            }
        }
        cout<<"no heroo found\n";
    }

    // TODO: Add getters for battle size and capacity
    int getsize()
    {
        return size;
    }

    int getcapacity()
    {
        return capacity;
    }
};

#endif

