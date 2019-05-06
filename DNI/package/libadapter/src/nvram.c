
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nvram.h"

int config_get_int(const char *name)
{
    char *value = config_get(name);
    if(value)
        return atoi(value);
    else
        return 0;
}

int config_set_int(const char *name, int value)
{
    char int_str[16] = {0};
    snprintf(int_str, sizeof(int_str), "%d", value);
    return config_set(name, int_str);
}

char *config_get_ext(const char *prefix, int idx)
{
    char name[32] = {0};
    snprintf(name, sizeof(name), "%s%d", prefix, idx);
    return config_get(name);
}

int config_get_int_ext(const char *prefix, int idx)
{
    char name[32] = {0};
    snprintf(name, sizeof(name), "%s%d", prefix, idx);
    return config_get_int(name);
}

int config_set_ext(const char *prefix, int idx, char *value)
{
    char name[32] = {0};
    snprintf(name, sizeof(name), "%s%d", prefix, idx);
    return config_set(name, value);
}

int config_set_int_ext(const char *prefix, int idx, int value)
{
    char name[32] = {0};
    snprintf(name, sizeof(name), "%s%d", prefix, idx);
    return config_set_int(name, value);    
}

int config_unset_ext(const char *prefix, int idx)
{
    char name[32] = {0};
    snprintf(name, sizeof(name), "%s%d", prefix, idx);
    return config_unset(name);  
}

