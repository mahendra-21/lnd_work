#include <stdio.h>
#include <elf.h>

void print_elf(Elf32_Ehdr *elf);
        
int main(int argc, char *argv[])
{
    Elf32_Ehdr elf;
    FILE *fp; 

    if (2 != argc) {
        puts("USAGE: %s <exe_file>\n", argv[0]);
        return 0;
    }

    fp = fopen(argv[1], "r"); // Opening a given file
    perror("fopen");
    
    /* Reading first 52 bytes in the given file & copying into 
    the elf header structure instance */ 
    fread(&elf, sizeof(elf), 1, fp); 
    perror("fread");

    print_elf(&elf);
   
    fclose(fp);
    return 0;
}
