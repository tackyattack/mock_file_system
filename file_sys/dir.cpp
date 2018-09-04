//
//  dir.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//
#include <stdio.h>
#include "dir.h"

directory::directory()
{
    chmod(777);
    set_type(true);
    set_user("mike");
    set_group("faculty");
    update_file_date();
}

directory* directory::search_for_dir(const char *name)
{
    // append a '/' if there isn't one
    char *name_with_slash = new char[strlen(name)+2];
    strcpy(name_with_slash, name);
    if(name[strlen(name)-1] != '/')
    {
        strcat(name_with_slash, "/");
    }

    // search the subdirectory vector for the given name
    for(int i = 0; i < subdirs.size(); i++)
    {
        if(strcmp(name_with_slash, subdirs[i]->get_name()) == 0)
        {
            delete[] name_with_slash;
            return subdirs[i];
        }
    }
    delete[] name_with_slash;
    return NULL;
}

file* directory::search_for_file(const char *name)
{
    for(int i = 0; i < dir_files.size(); i++)
    {
        if(strcmp(name, dir_files[i]->get_name()) == 0)
        {
            return dir_files[i];
        }
    }
    return NULL;
}

directory* directory::get_parent_dir()
{
    return parent;
}

std::vector<directory *> directory::get_subdirs()
{
    return subdirs;
}

void directory::add_subdir(directory *dir)
{
    dir->parent = this;
    subdirs.push_back(dir);
}

void directory::remove_subdir(directory *dir)
{
    for(int i = 0; i < subdirs.size(); i++)
    {
        if(subdirs[i] == dir)
        {
            subdirs.erase (subdirs.begin()+i);
            break;
        }
    }
}

std::vector<file *> directory::get_files()
{
    return dir_files;
}

void directory::add_file(file *f)
{
    dir_files.push_back(f);
}
