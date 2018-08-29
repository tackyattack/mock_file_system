//
//  main.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "dir.h"

int main(int argc, const char * argv[]) {
    
    file my_file;
    my_file.chmod(761);
    printf("%s", my_file.get_permissions_str());
    while(1);
    
    directory m;
    directory A;
    A.set_name("Directory_A");
    directory B;
    m.add_subdir(&A);
    m.add_subdir(&B);
    directory out = *(m.get_subdirs().front());
    char *x = out.get_name();
    printf("%s\n", x);
    return 0;
}
