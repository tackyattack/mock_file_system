//
//  file_mngr.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "file_mngr.h"

void file_manager::test()
{
    mkdir("x");
    mkdir("a");
    mkdir("y");
    mkdir("c");
    mkdir("z");
    mkdir("c");
    
    list_cwd();
}

file_manager::file_manager()
{
    root.set_name("/");
    cwd = &root;
}

void file_manager::mkdir(const char *name)
{
    // make a new dir (in current working dir) with the given name
    
    directory *new_dir = new directory;
    new_dir->set_name(name);
    cwd->add_subdir(new_dir);
}

void file_manager::change_directory(char *dir_name)
{
    // change the current working directory
    
    bool found = false;
    for(int i = 0; i < (cwd->get_subdirs()).size(); i++)
    {
        char *f_name = (cwd->get_subdirs())[i]->get_name();
        if(strcmp(f_name, dir_name))
        {
            found = true;
            cwd = (cwd->get_subdirs())[i];
            break;
        }
    }
    
    if(!found)
    {
        std::cout << "subdirectory not found" << std::endl;
    }
}

void file_manager::insert_alpha_str(char *src, std::vector<char *> &dest)
{
    // alphabetical insert based on first character
    std::vector<char *>::iterator it = dest.begin();
    bool found_place = false;
    for(int i = 0; i < dest.size() && !found_place; i++)
    {
        if(src[0] <= dest[i][0])
        {
             it = it + i;
            dest.insert(it, src);
            found_place = true;
        }
    }
    if(!found_place)
    {
        // couldn't find a spot, so just insert at the end
        it = it + dest.size();
        dest.insert(it, src);
    }
}

void file_manager::list_cwd()
{
    // list the files/directories in the current working dir
    // in alphabetical order
    
    std::vector<char *> names;
    
    names.push_back((cwd->get_subdirs())[0]->get_name());
    for(int i = 1; i < (cwd->get_subdirs()).size(); i++)
    {
        insert_alpha_str((cwd->get_subdirs())[i]->get_name(), names);
    }
    for(int i = 0; i < (cwd->get_files()).size(); i++)
    {
        insert_alpha_str((cwd->get_files())[i]->get_name(), names);
    }
    
    for(int i = 0; i < names.size(); i++)
    {
        printf("%s\n", names[i]);
    }
}
