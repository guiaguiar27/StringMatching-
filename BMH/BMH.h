#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Util/Cadeia.h"
#define MAXCHAR 256

/*Functions*/
long BMH_getTextSize(char *T);
int BMH_GetPatternSize(char *PString);
int *BMH_PreProccessing(long TextDimension, long PatternDimension, char *Pattern);