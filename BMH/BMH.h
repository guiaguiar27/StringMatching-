#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Util/Cadeia.h"
#define MAXCHAR 256

/*Functions*/
int *BMH_PreProccessing(long TextDimension, long PatternDimension, char *Pattern); 
int BMH(char *Text, char *Pattern, long TextSize, long PatternSize, long *comp, long *deslo);
