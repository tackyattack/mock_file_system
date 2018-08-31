//
//  file_obj.h
//  file_sys
//
//  Created by HENRY BERGIN on 8/29/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#ifndef file_obj_h
#define file_obj_h

class file_obj
{
public:
    file_obj();
    void chmod(int perm);
    char get_type();
    void set_type(bool is_dir);
    char *get_name();
    void set_name(const char *f_name);
    char *get_permissions_str();
    int get_links();
    void set_links(int link_cnt);
    char *get_user();
    void set_user(const char *usr);
    char *get_group();
    void set_group(const char *grp);
    int get_byte_size();
    void set_byte_size(int sz);
    char *get_date();
    void set_date(const char *dt);
    void get_current_date(char *date_out, int sz);
    void update_file_date();
private:
    char type;
    char permissions[9];
    int links;
    char *user = NULL;
    char *group = NULL;
    int byte_size;
    char *date = NULL;
    char *name = NULL;
    
    void dec_to_p(char dec, char *out_p);
};

#endif /* file_obj_h */
