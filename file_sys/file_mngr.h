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
    void change_directory(char *dir_name);
    void list_cwd(bool long_mode);
    void insert_alpha_file(file_obj &f, std::vector<file_obj *> &dest);
};

#endif /* file_mngr_h */
