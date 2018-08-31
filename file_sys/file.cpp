//
//  file.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#include <stdio.h>
#include "file.h"

file::file()
{
    chmod(777);
    set_type(false);
    set_user("henry");
    set_group("students");
}
