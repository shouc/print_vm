//
// Created by shou on 11/8/20.
//
#include <iostream>
#include <fstream>
#include <map>
#include <cassert>

int main(int argc, char** argv){
    if (argc != 2){
        exit(0);
    }
    std::map<std::string, std::string> function_def_table;
    function_def_table["001"] = "print";
    std::ifstream content(argv[1]);
    std::string file_cursor;
    getline(content, file_cursor);
    bool is_func_def_flag(false);
    assert(file_cursor.size() % 8 == 0);
    for (int i = 0; i < file_cursor.size(); i++){
        is_func_def_flag = file_cursor[i] == '0';
        char next_seven_bytes[7];
        for (char & next_seven_byte : next_seven_bytes) {
            i++;
            next_seven_byte = file_cursor[i];
        }
        std::string funct_name;
        funct_name += next_seven_bytes[0];
        funct_name += next_seven_bytes[1];
        funct_name += next_seven_bytes[2];
        if (is_func_def_flag){
            // function definition
            std::string funct_def;
            funct_def +=  next_seven_bytes[3];
            funct_def += next_seven_bytes[4];
            funct_def += next_seven_bytes[5];
            funct_def += next_seven_bytes[6];
            function_def_table[funct_name] = funct_def;
        } else {
            // function execution
            std::string funct_args;
            funct_args +=  next_seven_bytes[3];
            funct_args += next_seven_bytes[4];
            funct_args += next_seven_bytes[5];
            funct_args += next_seven_bytes[6];
            while (function_def_table.find(funct_name) != function_def_table.end()){
                funct_name = function_def_table.find(funct_name)->second;
                if (funct_name == "print"){
                    break;
                }
            }
            if (funct_name == "print"){
                printf("%s", funct_args.c_str());
            } else {
                printf("Cannot find function %s", funct_name.c_str());
            }
        }
    }
}
