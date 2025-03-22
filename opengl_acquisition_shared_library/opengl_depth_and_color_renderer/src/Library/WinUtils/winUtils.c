#include <stdio.h>
#include <stdlib.h>

#if defined (_WIN32)
#include <windows.h>    /* WinAPI */

/* Windows sleep in 100ns units */
int nanoSleep(LONGLONG ns) //https://stackoverflow.com/questions/13397571/precise-thread-sleep-needed-max-1ms-error/41862592#41862592
{
    /* Declarations */
    HANDLE timer;   /* Timer handle */
    LARGE_INTEGER li;   /* Time defintion */
    /* Create timer */
    if (!(timer = CreateWaitableTimer(NULL, TRUE, NULL)))
        return FALSE;
    /* Set timer properties */
    li.QuadPart = -ns;
    if (!SetWaitableTimer(timer, &li, 0, NULL, NULL, FALSE)) {
        CloseHandle(timer);
        return FALSE;
    }
    /* Start & wait for timer */
    WaitForSingleObject(timer, INFINITE);
    /* Clean resources */
    CloseHandle(timer);
    /* Slept without problems */
    return 1;
}

size_t getline(char **lineptr, size_t *n, FILE *stream) //https://stackoverflow.com/questions/735126/are-there-alternate-implementations-of-gnu-getline-interface/735472#735472
    {
        char *bufptr = NULL;
        char *p = bufptr;
        size_t size;
        int c;
    
        if (lineptr == NULL)
        {
            return -1;
        }
        if (stream == NULL)
        {
            return -1;
        }
        if (n == NULL)
        {
            return -1;
        }
        bufptr = *lineptr;
        size = *n;
    
        c = fgetc(stream);
        if (c == EOF)
        {
            return -1;
        }
        if (bufptr == NULL)
        {
            bufptr = malloc(128);
            if (bufptr == NULL)
            {
                return -1;
            }
            size = 128;
        }
        p = bufptr;
        while (c != EOF)
        {
            if ((p - bufptr) > (size - 1))
            {
                size = size + 128;
                bufptr = realloc(bufptr, size);
                if (bufptr == NULL)
                {
                    return -1;
                }
                p = bufptr + (size - 128);
            }
            *p++ = c;
            if (c == '\n')
            {
                break;
            }
            c = fgetc(stream);
        }
    
        *p++ = '\0';
        *lineptr = bufptr;
        *n = size;
    
        return p - bufptr - 1;
    }
#endif