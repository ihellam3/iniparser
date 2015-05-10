#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

int main2(int argc, char * argv[])
{
    dictionary * ini ;
    char       * ini_name ;

    if (argc<2) {
        ini_name = "ss.ini";
    } else {
        ini_name = argv[1] ;
    }

    ini = iniparser_load(ini_name);
    iniparser_dump_sh(ini, stdout);
    //iniparser_dump_json(ini, stdout);
    iniparser_freedict(ini);

    return 0 ;
}

int main3(int argc, char * argv[])
{
    dictionary * ini ;
    char* k1 = "hello:a";
    char* v1 = "nihao";
    char* k2 = "hello:b";
    char* v2 = "heihei";

    ini = dictionary_new(0);
    dictionary_set(ini, k1, v1);
    dictionary_set(ini, "hello", NULL);
    dictionary_set(ini, k2, v2);
    iniparser_dump_json(ini, stdout);
    iniparser_freedict(ini);

    return 0 ;
}

int main(int argc, char * argv[])
{
    dictionary * ini ;
    char       * ini_name ;

    if (argc<2) {
        ini_name = "a.sh";
    } else {
        ini_name = argv[1] ;
    }

    ini = iniparser_load_sh(ini_name);
    iniparser_dump_sh(ini, stdout);
    iniparser_freedict(ini);

    return 0 ;
}
