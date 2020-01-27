
#include <stdio.h>

int ext = 0;
void print(int, char);

int main()
{
    auto int ext = 1;
    static char chr = 'A';

    print(ext, chr);
    {
        int ext = 2;
        print(ext, chr);
        {
            ext += 1;
            print(ext, chr);
            chr += 3;
        }
        print(ext, chr);
        chr++;
    }
    print(ext, chr);
    return 0;
}

void print(int var, char ch_var)
{
    printf("%d %d\n", var, ch_var);
}
