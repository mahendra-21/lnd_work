/* copy n characters from character buffer sbuf to character buffer dbuf */

void my_strncpy(char *dest, const char *src, int num) {

    while ((num--) & *src)  *dest++ = *src++;

    *dest = '\0';

}
