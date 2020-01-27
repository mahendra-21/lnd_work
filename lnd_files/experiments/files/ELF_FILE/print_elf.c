#include <stdio.h>
#include <elf.h>

void print_elf(Elf32_Ehdr *elf) {
    
    int loop;
    printf("ELF Header:\n");

    printf("  Magic:   ");
    for(loop = 0; loop < EI_NIDENT; loop++)
        printf("%.2x ", elf -> e_ident[loop]);
    printf("\n");

    printf("  Class:                             ");
    switch (elf -> e_ident[EI_CLASS]) {
        case ELFCLASSNONE : puts("Invalid class");
                            break;
        case ELFCLASS32   : puts("ELF32");
                            break;
        case ELFCLASS64   : puts("ELF64");
                            break;
    }

    printf("  Data:                              ");
    switch (elf -> e_ident[EI_DATA]) {
        case ELFDATANONE   : puts("Invalid data");
                             break;
        case ELFDATA2LSB   : puts("2's complement, little endian");
                             break;
        case ELFDATA2MSB   : puts("2's complement, big endian");
                             break;
    }

    printf("  Version:                           ");
    switch (elf -> e_ident[EI_VERSION]) {
        case EV_NONE      : puts("0 (invalid)");
                            break;
        case EV_CURRENT   : puts("1 (current)");
                            break;
    }

    printf("  OS/ABI:                            ");
    switch (elf -> e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV       : puts("UNIX - System V");
                                   break;
        case ELFOSABI_HPUX       : puts("HP-UX");
                                   break;
        case ELFOSABI_NETBSD     : puts("NetBSD");
                                   break;
        case ELFOSABI_LINUX      : puts("Linux");
                                   break;
        case ELFOSABI_SOLARIS    : puts("Solaris");
                                   break;
        case ELFOSABI_IRIX       : puts("IRIX");
                                   break;
        case ELFOSABI_FREEBSD    : puts("FreeBSD");
                                   break;
        case ELFOSABI_TRU64      : puts("TRU64 UNIX");
                                   break;
        case ELFOSABI_ARM        : puts("ARM architecture");
                                   break;
        case ELFOSABI_STANDALONE : puts("Stand-alone (embedded)");
                                   break;
    }

    printf("  ABI Version:                       %d\n", 
                elf -> e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (elf -> e_type) {
        case ET_NONE   : puts("Unknown file");
                         break;
        case ET_REL    : puts("RLC (Relocatable file)");
                         break;
        case ET_EXEC   : puts("EXEC (Executable file)");
                         break;
        case ET_DYN    : puts("Shared object file");
                         break;
        case ET_CORE   : puts("Core file");
                         break;
        case ET_LOPROC : puts("Processor-specific");
                         break;
        case ET_HIPROC : puts("Processor-specific");
                         break;
    }
    
    printf("  Machine:                           ");
    switch (elf -> e_machine) {
        case EM_NONE        : puts("An unknown machine");
                              break;
        case EM_M32         : puts("AT&T WE 32100");
                              break;
        case EM_SPARC       : puts("Sun Microsystems SPARC");
                              break;
        case EM_386         : puts("Intel 80386");
                              break;
        case EM_68K         : puts("Motorola 68000");
                              break;
        case EM_88K         : puts("Motorola 88000");
                              break;
        case EM_860         : puts("Intel 80860");
                              break;
        case EM_MIPS        : puts("MIPS RS3000 (big-endian only)");
                              break;
        case EM_PARISC      : puts("HP/PA");
                              break;
        case EM_SPARC32PLUS : puts("SPARC with enhanced instruction set");
                              break;
        case EM_PPC         : puts("PowerPC");
                              break;
        case EM_PPC64       : puts("PowerPC 64-bit");
                              break;
        case EM_S390        : puts("IBM S/390");
                              break;
        case EM_ARM         : puts("Advanced RISC Machines");
                              break;
        case EM_SH          : puts("Renesas SuperH");
                              break;
        case EM_SPARCV9     : puts("SPARC v9 64-bit");
                              break;
        case EM_IA_64       : puts("Intel Itanium");
                              break;
        case EM_X86_64      : puts("AMD x86-64");
                              break;
        case EM_VAX         : puts("DEC Vax");
                              break;
    }

    printf("  Version:                           ");
    switch (elf -> e_version) {
        case EV_NONE     : printf("0x%x\n", elf -> e_version); 
                           break;
        case EV_CURRENT  : printf("0x%x\n", elf -> e_version);
                           break;
    }

    printf("  Entry point address:               0x%x\n", elf -> e_entry);
    printf("  Start of program headers:          %d (bytes into files)\n", 
                elf -> e_phoff);
    printf("  Start of section headers:          %d (bytes into files)\n", 
                elf -> e_shoff);
    printf("  Flags:                             0x%x\n", elf -> e_flags);
    printf("  Size of this header:               %d (bytes)\n", 
                elf -> e_ehsize);
    printf("  Size of program headers:           %d (bytes)\n", 
                elf -> e_phentsize);
    printf("  Number of program headers:         %d\n", elf -> e_phnum);
    printf("  Size of section headers:           %d (bytes)\n", 
                elf -> e_shentsize);
    printf("  Number of section headers:         %d\n", elf -> e_shnum);
    printf("  Section header string table index: %d\n",elf -> e_shstrndx);
}
