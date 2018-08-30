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
    
    list_cwd(false);
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

void file_manager::insert_alpha_file(file_obj &f, std::vector<file_obj *> &dest)
{
    // alphabetical insert based on first character
    std::vector<file_obj *>::iterator it = dest.begin();
    bool found_place = false;
    for(int i = 0; i < dest.size() && !found_place; i++)
    {
        if(f.get_name()[0] <= dest[i]->get_name()[0])
        {
             it = it + i;
            dest.insert(it, &f);
            found_place = true;
        }
    }
    if(!found_place)
    {
        // couldn't find a spot, so just insert at the end
        it = it + dest.size();
        dest.insert(it, &f);
    }
}
// todo: make it so it can print short version and long version using this
//       same function. Just be able to select the mode -- should be almost
//       all the same except the file log will now include the extra info.
//       Keep the same alphabetical ordering based on name.
void file_manager::list_cwd(bool long_mode)
{
    // list the files/directories in the current working dir
    // in alphabetical order
    
    std::vector<file_obj *> file_logs;
    
    file_logs.push_back((cwd->get_subdirs())[0]);
    for(int i = 1; i < (cwd->get_subdirs()).size(); i++)
    {
        insert_alpha_file(*(cwd->get_subdirs())[i], file_logs);
    }
    for(int i = 0; i < (cwd->get_files()).size(); i++)
    {
        insert_alpha_file(*(cwd->get_files())[i], file_logs);
    }
    
    if(long_mode)
    {
        for(int i = 0; i < file_logs.size(); i++)
        {
            printf("%s\n", file_logs[i]->get_name());
        }
    }
    else
    {
        for(int i = 0; i < file_logs.size(); i++)
        {
            printf("%c%s\t%d\t%s\t%s\t%d\t%s\t%s\n", file_logs[i]->get_type(),
                                    file_logs[i]->get_permissions_str(),
                                    file_logs[i]->get_links(),
                                    file_logs[i]->get_user(),
                                    file_logs[i]->get_group(),
                                    file_logs[i]->get_byte_size(),
                                    file_logs[i]->get_date(),
                                    file_logs[i]->get_name());
        }
    }
}
