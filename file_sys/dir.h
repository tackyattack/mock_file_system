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
    std::vector<directory *> get_subdirs();
    void add_subdir(directory *dir);
private:
    std::vector<directory *> subdirs;
    std::vector<file *> files;
};

#endif /* dir_h */
