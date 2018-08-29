//
//  dir.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//
#include <stdio.h>
#include "dir.h"

std::vector<directory *> directory::get_subdirs()
{
    return subdirs;
}

std::vector<file *> directory::get_files()
{
    return dir_files;
}

void directory::add_subdir(directory *dir)
{
    subdirs.push_back(dir);
}
