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
    void chmod(int perm);
    char *get_name();
    void set_name(const char *f_name);
    char *get_permissions_str();
private:
    char type;
    char permissions[9];
    int links;
    char *user;
    char *group;
    int byte_size;
    char *date;
    char *name;
    
    void dec_to_p(char dec, char *out_p);
};

#endif /* file_obj_h */
