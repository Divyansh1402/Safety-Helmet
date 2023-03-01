#include "../include/Screen.h"
#include <cstdlib>
#include <iostream>

bool isInt(std::string s){
    for(int c_s : s){
        if (!isdigit(c_s)){
            return false;
        }
    }
    return true;
}

void Screen::readConfig(){
    std::fstream config;
    config.open("./fog.conf", std::ios::in);

    //for zone number
    config >> zone_;

    //for number of helmets (kinda lamelol)
    int no;
    config >> no;
    //for helmet numbers
    while(no--){
        int temp;
        config >> temp;
        helmet_.push_back(temp);
        dht_[temp] = {0,0};
        mqtt_[temp] = 0;
    }
}

void Screen::readData(std::string & data, bool & changed){
    if (changed){
        //
        std::string temp = "";
        int count = 0;
        int arr[4];
        for(int c_d : data){
            if (c_d == ' '){ 
                if (isInt(temp)){ arr[count] = stoi(temp); }
                count++; temp = "";
            }
            else{ temp += c_d;}
            if(count==4) break;
        }
        //updating the values
        dht_[arr[3]] = {arr[0],arr[1]};
        mqtt_[arr[3]] = arr[2];
        changed = false;
    }
}

void Screen::display(){
    for(auto h : helmet_){
        std::cout << h << " " << mqtt_[h] << " " <<
          dht_[h].first << " " << dht_[h].second << std::endl;
    }
}