//
//  arg_parse.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/31/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arg_parse.h"

void arg_parser::parse_arg(const char *arg, file_manager *fm, bool &quit)
{    
    // should split each argument based on what the command is
    // for example, cd will split once at the space: cd[space][arg: ".." | "dir name w/ spaces"]
    // chmod will split twice: chmod[space][arg: 777][space][arg: "name"]
    
    // grab the first argument (should be the command)
    char cmd[10] = {0};
    for(int i = 0; (i < 10) && (arg[i] != ' '); i++)
    {
        cmd[i] = arg[i];
    }
    
    if(strcmp(cmd, "pwd") == 0)
    {
        fm->print_cwd_path();
    }
    else if(strcmp(cmd, "cd") == 0)
    {
        fm->change_directory_search(arg+3);
    }
    else if(strcmp(cmd, "ls") == 0)
    {
        if(strlen(arg) == 2)
        {
            fm->list_cwd(false);
        }
        else if(arg[3] == '-' && arg[4] == 'l' && strlen(arg) == 5)
        {
            fm->list_cwd(true);
        }
        else
        {
            printf("invalid command\n");
        }
    }
    else if(strcmp(cmd, "mkdir") == 0)
    {
        fm->mkdir(arg+6);
    }
    else if(strcmp(cmd, "rmdir") == 0)
    {
        fm->rmdir(arg+6);
    }
    else if(strcmp(cmd, "touch") == 0)
    {
        fm->touch(arg+6);
    }
    else if(strcmp(cmd, "rm") == 0)
    {
        fm->rmf(arg+3);
    }
    else if(strcmp(cmd, "chmod") == 0)
    {
        char val_str[4] = {0};
        strncpy(val_str, arg+6, 3);
        fm->chmod(arg+10, atoi(val_str));
    }
    else if((strcmp(cmd, "exit") == 0) || (strcmp(cmd, "quit") == 0))
    {
        quit = true;
    }
    else
    {
        printf("invalid command\n");
    }
    
    return;
}
