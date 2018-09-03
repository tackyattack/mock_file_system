//
//  file.h
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#ifndef file_h
#define file_h
#include "file_obj.h"

class file: public file_obj
{
public:
    file();
private:
    file* search_for_file(const char *name);
    
};

#endif /* file_h */
