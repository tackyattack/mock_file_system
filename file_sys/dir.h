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
    std::vector<directory *>* get_subdirs_ptr();
    std::vector<file *> get_files();
    std::vector<file *>* get_files_ptr();
    void add_subdir(directory *dir);
    void remove_subdir(directory *dir);
    void add_file(file *f);
    directory* get_parent_dir();
    directory* search_for_dir(const char *name);
    file* search_for_file(const char *name);
private:
    std::vector<directory *> subdirs;
    std::vector<file *> dir_files;
    directory *parent;
};

#endif /* dir_h */
