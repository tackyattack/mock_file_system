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
    void list_cwd();
    void insert_alpha_str(char *src, std::vector<char *> &dest);
};

#endif /* file_mngr_h */
