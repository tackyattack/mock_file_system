//
//  file_obj.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "file_obj.h"

char* file_obj::get_permissions_str()
{
    return permissions;
}

char file_obj::get_type()
{
    return type;
}

void file_obj::set_name(const char *f_name)
{
    name = new char[strlen(f_name)];
    strcpy(name, f_name);
}

char* file_obj::get_name()
{
    return name;
}

int file_obj::get_links()
{
    return links;
}

char* file_obj::get_user()
{
    return user;
}

char* file_obj::get_group()
{
    return group;
}

int file_obj::get_byte_size()
{
    return byte_size;
}

char* file_obj::get_date()
{
    return date;
}

void file_obj::dec_to_p(char dec, char *out_p)
{
    // converts a decimal number to a permission str (3 chars long)
    // bit format: RWX
    
    char p_types[] ={'x','w','r','-'};
    
    for(int i = 0; i < 3; i++)
    {
        if((dec & (0x01<<i)) != 0)
        {
            out_p[2-i] = p_types[i];
        }
        else
        {
            out_p[2-i] = p_types[3];
        }
    }
    
}

void file_obj::chmod(int perm)
{
    char owner   = perm/100;
    char group   = (perm - owner*100)/10;
    char pub     = (perm - owner*100 - group*10);
    
    dec_to_p(owner, permissions);
    dec_to_p(group, permissions+3);
    dec_to_p(pub, permissions+6);
}
