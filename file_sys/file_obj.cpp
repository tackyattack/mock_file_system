//
//  file_obj.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include "file_obj.h"

file_obj::file_obj()
{
    user = NULL;
    group = NULL;
    date = NULL;
    name = NULL;
    
    links = 1;
    set_byte_size(rand()%50000);
    set_date("Jan 1 00:00");
}

file_obj::~file_obj()
{
    if(user != NULL) delete[] user;
    if(group != NULL) delete[] group;
    if(date != NULL)delete[] date;
    if(name != NULL)delete[] name;
}

char* file_obj::get_permissions_str()
{
    return permissions;
}

char file_obj::get_type()
{
    return type;
}

void file_obj::set_type(bool is_dir)
{
    if(is_dir)
    {
        type = 'd';
    }
    else
    {
        type = '-';
    }
}

void file_obj::set_name(const char *f_name)
{
    if(name != NULL)
    {
        delete[] name;
        name = NULL;
    }
    name = new char[strlen(f_name)+1];
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

void file_obj::set_links(int link_cnt)
{
    links = link_cnt;
}

char* file_obj::get_user()
{
    return user;
}

void file_obj::set_user(const char *usr)
{
    if(user != NULL)
    {
        delete[] user;
        user = NULL;
    }
    user = new char[strlen(usr)+1];
    strcpy(user, usr);
}

char* file_obj::get_group()
{
    return group;
}

void file_obj::set_group(const char *grp)
{
    if(group != NULL)
    {
        delete[] group;
        group = NULL;
    }
    group = new char[strlen(grp)+1];
    strcpy(group, grp);
}

int file_obj::get_byte_size()
{
    return byte_size;
}

void file_obj::set_byte_size(int sz)
{
    byte_size = sz;
}

char* file_obj::get_date()
{
    return date;
}

void file_obj::set_date(const char *dt)
{
    if(date != NULL)
    {
        delete[] date;
        date = NULL;
    }
    date = new char[strlen(dt)+1];
    strcpy(date, dt);
}

void file_obj::get_current_date(char *date_out, int sz)
{
    // get the current date in string format
    time_t t = time(0);
    tm const* tm = localtime(&t);
    strftime(date_out, sz, "%b %d %Y %H:%M", tm);
}

void file_obj::update_file_date()
{
    // update this file's time to now
    char dt[30] = {0};
    get_current_date(dt, 30);
    set_date(dt);
}

void file_obj::dec_to_p(char dec, char *out_p)
{
    // converts a decimal number to a permission str (3 chars long)
    // bit format: RWX
    
    char p_types[] ={'x','w','r','-'};
    
    // Check each bit and set the permission string according to the Linux standard
    // rwx rwx rwx
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
    char owner   = perm/100; // first digit
    char group   = (perm - owner*100)/10; // second digit
    char pub     = (perm - owner*100 - group*10); // third digit
    
    // modify each set of three RWX
    dec_to_p(owner, permissions);
    dec_to_p(group, permissions+3);
    dec_to_p(pub, permissions+6);
    permissions[9] = '\0';
}
