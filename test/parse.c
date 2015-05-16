#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

int main(int argc, char * argv[])
{
    dictionary *ini;

    if (argc != 4) {
        fprintf(stderr, "iniparser sh|ini filename sh|ini|json\n");
        return -1;
    }

    if(!strcmp(argv[1], "sh")) {
        ini = iniparser_load_sh(argv[2]);
    } else if(!strcmp(argv[1], "ini")) {
        ini = iniparser_load(argv[2]);
    } else {
        fprintf(stderr, "input format:%s not found\n", argv[1]);
        return -2;
    }

    if(NULL == ini) {
        fprintf(stderr, "cannot read file:%s\n", argv[1]);
        return -3;
    }

    if(!strcmp(argv[3], "sh")) {
        iniparser_dump_sh(ini, stdout);
    } else if(!strcmp(argv[3], "ini")) {
        iniparser_dump_ini(ini, stdout);
    } else if(!strcmp(argv[3], "json")) {
        iniparser_dump_json(ini, stdout);
    } else {
        fprintf(stderr, "output format:%s not found\n", argv[3]);
    }

    iniparser_freedict(ini);

    return 0 ;
}
