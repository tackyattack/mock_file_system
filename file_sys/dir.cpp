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

std::vector<directory *> directory::get_subdirs()
{
    return subdirs;
}

void directory::add_subdir(directory *dir)
{
    subdirs.push_back(dir);
    //set_links(get_links() + 1); probably won't work since the
    // number of links goes all the way down to the last folder
    // NOPE! nvm, it looks like links are the number of files (dir or actual
    // files) in a subfolder.
    // Therefore, maybe then you could call touch on the directory you
    // are in, which would be here so that the links could be update?
    // or, actually, maybe the link increase should go in the file
    // manager. That way, whenever you call mkdir or touch, or rm file,
    // the link for the current working directory gets updated correctly.
    // Yeah that's probably how it should work.
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
