//
//  dir.h
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#ifndef dir_h
#define dir_h
#include <vector>
#include "file_obj.h"
#include "file.h"

class directory: public file_obj
{
public:
    directory();
    std::vector<directory *> get_subdirs();
    std::vector<file *> get_files();
    void add_subdir(directory *dir);
    void remove_subdir(directory *dir);
    void add_file(file *f);
    directory* get_parent_dir();
private:
    std::vector<directory *> subdirs;
    std::vector<file *> dir_files;
    directory *parent = NULL;
};

#endif /* dir_h */
