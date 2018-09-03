//
//  main.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "dir.h"
#include "file_mngr.h"
#include "arg_parse.h"

int main()
{
    file_manager fm;
    arg_parser ap;
    std::string arg;
    bool quit = false;
    
    while(!quit)
    {
        getline(std::cin, arg);
        const char *arg_c = arg.c_str();
        ap.parse_arg(arg_c, &fm, quit);
    }

    return 0;
}
