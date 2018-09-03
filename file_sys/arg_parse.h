//
//  arg_parse.h
//  file_sys
//
//  Created by HENRY BERGIN on 8/31/18.
//  Copyright © 2018 HENRY BERGIN. All rights reserved.
//

#ifndef arg_parse_h
#define arg_parse_h

#include <vector>
#include "file_mngr.h"

class arg_parser
{
public:
    void parse_arg(const char *arg, file_manager *fm, bool &quit);
private:
};

#endif /* arg_parse_h */
