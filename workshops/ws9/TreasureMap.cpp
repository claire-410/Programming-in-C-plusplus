// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <future>
#include <thread>
#include <vector>
#include "TreasureMap.h"

namespace sdds{
   constexpr size_t NUM = 4;

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
       if (map) {
          std::ofstream file(filename, std::ios::out | std::ios::binary);
          if (file) {
             file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
             file.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));
             for (std::size_t i = 0; i < rows; i++) {
                file.write(&(map[i][0]), map[i].size());
             }
          }
          else {
             throw("Error: Cannot open file!");
          }
       }
       else {
          throw std::string("Treasure map is empty!");
       }
    }

    void TreasureMap::recall(const char* filename){
       std::ifstream file(filename, std::ios::in | std::ios::binary);
       if (file) {
          file.read(reinterpret_cast<char*>(&rows), sizeof(rows));
          file.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));
          map = new std::string[rows];
          for (std::size_t i = 0; i < rows; i++) {
             map[i].resize(colSize);   // Make sure there's enough room
             file.read(reinterpret_cast<char*>(&(map[i][0])), colSize);
          }
       }
       else {
          throw("Error: Cannot open file!");
       }
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;
        
        size_t thread = 0;
        std::string strings[NUM];
        
        auto dig = std::bind(digForTreasure, std::placeholders::_1, mark);
        for (size_t i = 0; i < rows; i++) {
           if (thread == NUM) {
              thread = 0;
           }
           strings[thread] += map[i];
           thread++;
        }

        std::packaged_task<size_t(std::string)> t1(dig);  
        std::packaged_task<size_t(std::string)> t2(dig);
        std::packaged_task<size_t(std::string)> t3(dig);
        std::packaged_task<size_t(std::string)> t4(dig);

        auto f1 = t1.get_future();
        auto f2 = t2.get_future();
        auto f3 = t3.get_future();
        auto f4 = t4.get_future();

        t1(strings[0]);
        t2(strings[1]);
        t3(strings[2]);
        t4(strings[3]);

        count = f1.get() + f2.get() + f3.get() + f4.get();

        return count;
    }
}




