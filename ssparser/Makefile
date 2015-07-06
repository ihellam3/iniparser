CCPREF = arm-brcm-linux-uclibcgnueabi
#CC      = $(CCPREF)-gcc
#AR	= $(CCPREF)-ar
CC = gcc
AR = ar
RM      = rm -f


default: all

all:ssparser

ssparser: ssparser.c dictionary.c iniparser.c
	$(CC) $(CFLAGS) -o ssparser ssparser.c dictionary.c iniparser.c -I./

clean veryclean:
	$(RM) ssparse
