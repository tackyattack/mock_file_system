//
//  file_mngr.cpp
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "file_mngr.h"

// TODO: make function to check if file exists (dir or file)
//       if exists and mkdir, don't do it
//       if exists and touch, just update date

void file_manager::test()
{
    
    mkdir("x");
    cwd->chmod(777);
    mkdir("a");
    mkdir("y");
    mkdir("c");
    mkdir("z");
    mkdir("c");
    
    touch("hello_world");
    
    //list_cwd(true);
    print_cwd_path();
    change_directory_search("a/");
    print_cwd_path();
    
}

file_manager::file_manager()
{
    root.set_name("/");
    cwd = &root;
}

void file_manager::print_cwd_path()
{
    std::vector<char *> path;
    directory *current = cwd;
    while(current != NULL)
    {
        path.push_back(current->get_name());
        current = current->get_parent_dir();
    }
    for(long i = path.size()-1; i > -1; i--)
    {
        printf("%s", path[i]);
    }
    printf("\n");
}

void file_manager::mkdir(const char *name)
{
    // make a new dir (in current working dir) with the given name
    
    char *name_with_slash = new char[strlen(name)+2];
    strcpy(name_with_slash, name);
    strcat(name_with_slash, "/");
    
    directory *new_dir = new directory;
    new_dir->set_name(name_with_slash);
    cwd->add_subdir(new_dir);
    cwd->set_links(cwd->get_links()+1);
    delete[] name_with_slash;
}

void file_manager::rmdir(const char *name)
{
    std::vector<directory *> subdirs = cwd->get_subdirs();
    for(int i = 0; i < subdirs.size(); i++)
    {
        if(strcmp(subdirs[i]->get_name(), name))
        {
            file_obj *f = subdirs[i];
            subdirs.erase(subdirs.begin() + i);
            delete f;
        }
    }
    cwd->set_links(cwd->get_links()-1);
}

void file_manager::touch(const char *name)
{
    file *new_file = new file;
    new_file->set_name(name);
    cwd->add_file(new_file);
    cwd->set_links(cwd->get_links()+1);
}

void file_manager::rmf(const char *name)
{
    std::vector<file *> files = cwd->get_files();
    for(int i = 0; i < files.size(); i++)
    {
        if(strcmp(files[i]->get_name(), name))
        {
            file_obj *f = files[i];
            files.erase(files.begin() + i);
            delete f;
        }
    }
    cwd->set_links(cwd->get_links()-1);
}

void file_manager::change_directory(char *dir_name)
{
    // change the current working directory
    
    bool found = false;
    for(int i = 0; i < (cwd->get_subdirs()).size(); i++)
    {
        char *f_name = (cwd->get_subdirs())[i]->get_name();
        if(strcmp(f_name, dir_name))
        {
            found = true;
            cwd = (cwd->get_subdirs())[i];
            break;
        }
    }
    
    if(!found)
    {
        std::cout << "subdirectory not found" << std::endl;
    }
}

void file_manager::split_path(const char *path, std::vector<const char *> &dirs, std::vector<int> &lengths)
{
    // split the path string into individual directory names.
    // the lengths variable indicates the length of each directory name
    int j = 0;
    for(int i = 0; i < strlen(path); i++)
    {
        if(path[i] == '/')
        {
            i++;
            dirs.push_back(path+j);
            lengths.push_back(i-j);
            j=i;
        }
    }
}

bool file_manager::change_directory_search(const char *path)
{
    directory *current_dir = cwd;
    std::vector<const char *> dirs;
    std::vector<int> lengths;
    split_path(path, dirs, lengths);
    for(int i = 0; i < dirs.size(); i++)
    {
        char *dir_name = new char[lengths[i] + 1];
        strncpy(dir_name, dirs[i], lengths[i]);
        dir_name[lengths[i]] = '\0';
        current_dir = current_dir->search_for_dir(dir_name);
        if(current_dir == NULL)
        {
            return false;
        }
        delete[] dir_name;
    }
    
    cwd = current_dir;
    return true;
}

void file_manager::insert_alpha_file(file_obj &f, std::vector<file_obj *> &dest)
{
    // alphabetical insert based on first character
    std::vector<file_obj *>::iterator it = dest.begin();
    bool found_place = false;
    for(int i = 0; i < dest.size() && !found_place; i++)
    {
        if(f.get_name()[0] <= dest[i]->get_name()[0])
        {
             it = it + i;
            dest.insert(it, &f);
            found_place = true;
        }
    }
    if(!found_place)
    {
        // couldn't find a spot, so just insert at the end
        it = it + dest.size();
        dest.insert(it, &f);
    }
}

void file_manager::list_cwd(bool long_mode)
{
    // list the files/directories in the current working dir
    // in alphabetical order.
    // The long mode indicates that all information should be printed.
    
    std::vector<file_obj *> file_logs;
    
    file_logs.push_back((cwd->get_subdirs())[0]);
    for(int i = 1; i < (cwd->get_subdirs()).size(); i++)
    {
        insert_alpha_file(*(cwd->get_subdirs())[i], file_logs);
    }
    for(int i = 0; i < (cwd->get_files()).size(); i++)
    {
        insert_alpha_file(*(cwd->get_files())[i], file_logs);
    }
    
    if(!long_mode)
    {
        for(int i = 0; i < file_logs.size(); i++)
        {
            printf("%s\n", file_logs[i]->get_name());
        }
    }
    else
    {
        for(int i = 0; i < file_logs.size(); i++)
        {
            printf("%c%s %10d %10s %10s %10d %10s %20s\n", file_logs[i]->get_type(),
                                    file_logs[i]->get_permissions_str(),
                                    file_logs[i]->get_links(),
                                    file_logs[i]->get_user(),
                                    file_logs[i]->get_group(),
                                    file_logs[i]->get_byte_size(),
                                    file_logs[i]->get_date(),
                                    file_logs[i]->get_name());
        }
    }
}
