#ifndef CL_LIB
#define CL_LIB

#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>
#include <vector>

template <class Itr>
class Iters{
    Itr start;
    Itr end;
    Itr runner;

    protected:
    //DEFAULT CONSTRUCTOR
        Iters() {};

    public:
    //PUBLIC CONSTRUCTOR  
        Iters(Itr first, Itr last) : start(first), end(last){
            runner = (first==last) ? last : last-1;
        };

    //SETTER
        void set_iters(Itr first, Itr last){
            start = first;
            end = last;
            runner = (first==last) ? last : last-1;
        }   //USED IN CASE OF DEFAULT INITIALIZATION, TO IMPLEMENT IN ANOTHER STRUCTURE
    
    //ACCESS
        void print_end() const;     //WORKING
        void print_run() const;     //WORKING
        virtual int get_size() const;       //WORKING
        Itr get_runner() const;             //WORKING

    //MODIFIERS
        void run_runner();  //WORKING
        void shuffle();     //WORKING
};

template <typename T>
class ConstStack : public Iters<typename std::vector <T> :: iterator > {
    std::vector <T> stored {};

    public:
    //CONSTRUCTOR
        ConstStack(std::vector <T> input) 
            : stored(input) 
        { 
            this -> set_iters(stored.begin(), stored.end());
        };
    
    //GETTERS
        int get_size() const override;      //WORKING
    
    //MODIFIERS
        T get_last();       //WORKING

};

#include "imp_iters.hpp"
#include "imp_cstack.hpp"

#endif