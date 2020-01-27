/* check whether rstr is a rotated string of str */

char strrot (const char *str, const char *rev_str) {

    int str_len = 0;

    int revstr_len = 0;

    int start = 0;

    if (str_len != revstr_len) return 0;

    else {

        for (str_len = str_len - 1, start = 0; str[start]; 
                start++, str_len--)  {

            if (str[start] != rev_str[str_len]) return 0;

        }

    }

    return 1;

}
