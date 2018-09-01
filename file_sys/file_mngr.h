//
//  file_mngr.h
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#ifndef file_mngr_h
#define file_mngr_h

#include "file.h"
#include "dir.h"
#include "file_obj.h"

class file_manager
{
public:
    file_manager();
    void test(); // REMOVE
private:
    directory root;
    directory *cwd;
    void mkdir(const char *name);
    void rmdir(const char *name);
    void touch(const char *name);
    void rmf(const char *name);
    void change_directory(char *dir_name);
    bool change_directory_search(const char *path);
    void change_to_parent_dir();
    void list_cwd(bool long_mode);
    void print_cwd_path();
    void insert_alpha_file(file_obj &f, std::vector<file_obj *> &dest);
    void split_path(const char *path, std::vector<const char *> &dirs, std::vector<int> &lengths);
    void recursive_rm_dir(directory *dir);
    void end();
};

#endif /* file_mngr_h */
