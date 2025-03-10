/*
 * Tools : memory management, file loading and saving
 */

#include "../config.h"
#include "defines.h"
#include "tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <ctype.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>


void *xmalloc(size_t size) {
    void *ret = malloc(size);
    if (ret == NULL) {
        perror("malloc() ");
        exit(-1);
    } else
        return ret;
}


char *xstrdup(const char *string) {
    char *ret = strdup(string);
    if (ret == NULL) {
        perror("strdup() ");
        exit(-1);
    } else
        return ret;
}


int getbool(const char *value) {
    if (strcmp(value, "0") == 0) return FALSE;
    if (strcmp(value, "1") == 0) return TRUE;
    if (strcasecmp(value, "true") == 0) return TRUE;
    if (strcasecmp(value, "false") == 0) return FALSE;
    if (strcasecmp(value, "yes") == 0) return TRUE;
    if (strcasecmp(value, "no") == 0) return FALSE;
    if (strcasecmp(value, "on") == 0) return TRUE;
    if (strcasecmp(value, "off") == 0) return FALSE;
    printf("Error in converting \"%s\" to boolean value.\n", value);
    return FALSE;
}


char *robust_home(void) {
    if (getenv("HOME"))
        return getenv("HOME");
    else if (getenv("USER") && getpwnam(getenv("USER")))
        return getpwnam(getenv("USER"))->pw_dir;
    else if (getenv("LOGNAME") && getpwnam(getenv("LOGNAME")))
        return getpwnam(getenv("LOGNAME"))->pw_dir;
    else if (getpwuid(getuid()))
        return getpwuid(getuid())->pw_dir;
    else
        return "/";
}


char *get_file(const char *datestr) {
    char *Home = robust_home();
    int   len  = strlen(Home) + strlen(DEFAULT_CONFIGDIR) + strlen(datestr);
    char *filename = xmalloc(len + 3);

    sprintf(filename, "%s/%s/%s", Home, DEFAULT_CONFIGDIR, datestr);
    return filename;
}

