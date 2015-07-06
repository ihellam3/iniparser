#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

enum FILE_EXT {
    FILE_EXT_INVALID,
    FILE_EXT_SH,
    FILE_EXT_INI,
    FILE_EXT_JSON,
    FILE_EXT_COUNT
};

enum FILE_EXT get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) {
        return FILE_EXT_INVALID;
    }

    dot += 1;
    if (0 == strcasecmp(dot, "sh")) {
        return FILE_EXT_SH;
    } else if (0 == strcasecmp(dot, "ini")) {
        return FILE_EXT_INI;
    } else if (0 == strcasecmp(dot, "json")) {
        return FILE_EXT_JSON;
    } else {
        return FILE_EXT_INVALID;
    }
}


dictionary * iniparser_load_from_file(const char * ininame) {
    enum FILE_EXT ext = get_filename_ext(ininame);

    if(FILE_EXT_SH == ext) {
        return iniparser_load_sh(ininame);
    } else if(FILE_EXT_INI == ext) {
        return iniparser_load(ininame);
    } else {
        return NULL;
    }
}

int main(int argc, char * argv[], char * envp[]) {
    int n = 0;
    dictionary *ini = NULL, *ini_tmp = NULL;

    if (argc < 2) {
        fprintf(stderr, "ssparser action args\n");
        return -1;
    }

    if(!strcmp(argv[1], "merge")) {
        if (argc < 4) {
            fprintf(stderr, "ssparser merge file1 file2 ...\n");
            return -1;
        }
        n = 2;
        ini = iniparser_load_from_file(argv[n]);
        if(NULL == ini) {
            fprintf(stderr, "load %s error\n", argv[n]);
            return -1;
        }
        for (n = n+1;n < argc; n++) {
            ini_tmp = iniparser_load_from_file(argv[n]);
            if(NULL == ini_tmp) {
                fprintf(stderr, "load %s error\n", argv[n]);
                return -1;
            }
            dictionary_merge(ini, ini_tmp);
            iniparser_freedict(ini_tmp);
        }

        iniparser_dump_sh(ini, stdout);
        iniparser_freedict(ini);
    } else if(!strcmp(argv[1], "convert")) {
        if(argc != 4) {
            fprintf(stderr, "ssparser convert file_in json|sh|ini|update\n");
            return -1;
        }
        ini = iniparser_load_from_file(argv[2]);
        if(NULL == ini) {
            fprintf(stderr, "cannot read file:%s\n", argv[2]);
            return -1;
        }

        if(!strcmp(argv[3], "sh")) {
            iniparser_dump_sh(ini, stdout);
        } else if(!strcmp(argv[3], "ini")) {
            iniparser_dump_ini(ini, stdout);
        } else if(!strcmp(argv[3], "json")) {
            iniparser_dump_json(ini, stdout);
        } else if(!strcmp(argv[3], "update")) {
            char** env;
            for (env = envp; *env != 0; env++) {
                char* this_env = xstrdup(*env);
                char *v = strstr(this_env, "=");
                if(v != NULL) {
                    *v = '\0';
                    v += 1;
                    iniparser_find_set(ini, this_env, v);
                }
                if(this_env != NULL) {
                    free(this_env);
                }
            }
            iniparser_dump_sh(ini, stdout);
        } else {
                fprintf(stderr, "output format:%s not found\n", argv[3]);
        }
        iniparser_freedict(ini);
    } else {
        fprintf(stderr, "ssparser merge|convert file1 ...");
    }

    return 0 ;
}
