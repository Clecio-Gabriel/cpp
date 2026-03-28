#include <iostream>
#include <string>

using string = std::string;

string passw_check(string in);

int main(){

    string input{};
    while(std::getline(std::cin >> std::ws, input)){
        std::cout << passw_check(input) << "\n";
    }

    return 0;
}


string passw_check(string in){

    bool haveNum = false;
    bool haveUpper = false;
    bool haveLower = false;
    bool noInvalidChar = true;

    // [1] - is the password size inside the acceptable interval[6,32]?
    if (in.length()>5 and in.length()<33){
        //If it's included in the inverval, we'll check it's elements.
        for (int asciinum : in){   //USING ASCII TABLE
            
            //[2] - Is this element a number?
            if (asciinum>47 and asciinum<58){    
                if (haveNum==false){    //If so, we can confirm haveNum is true
                    haveNum = true;
                }
                continue;
            }

            //[3] - Is this element an uppercase letter?
            else if (asciinum>64 and asciinum<91){     
                if (haveUpper==false){  //If so, we can confirm haveUpper is true
                    haveUpper = true;
                }
                continue;
            }

            //[4] - Is this element an lowercase letter?
            else if (asciinum>96 and asciinum<123){
                if(haveLower==false){   //If so, we can confirm haveLower is true
                    haveLower = true;
                }
                continue;
            }

            //[5] - If it's different from all of the above, then it's an invalid char
            else{
                noInvalidChar = false;
                break;
            }
        }
    }

    if (haveNum and haveUpper and haveLower and noInvalidChar){
        return "Senha valida.";
    }
    return "Senha invalida.";
}