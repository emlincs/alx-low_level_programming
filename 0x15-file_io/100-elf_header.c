#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checkElf(unsigned char *e_ident);
void printMagic(unsigned char *e_ident);
void printClass(unsigned char *e_ident);
void printData(unsigned char *e_ident);
void printVersion(unsigned char *e_ident);
void printABI(unsigned char *e_ident);
void printOSABI(unsigned char *e_ident);
void printType(unsigned int e_type, unsigned char *e_ident);
void printEntry(unsigned long int e_entry, unsigned char *e_ident);
void closeElf(int elf);

/**
 * checkElf - identifies an ELF file.
 * @e_ident: Array pointer holding the ELF magic numbers.
 *
 * Commentary: If the file is not an ELF file - exit code 98.
 */
void checkElf (unsigned char *e_ident)
{
    for (int elementIndex = 0; elementIndex < 4; elementIndex++)
    {
        if (e_ident[elementIndex] != 127 &&
            e_ident[elementIndex] != 'E' &&
            e_ident[elementIndex] != 'L' &&
            e_ident[elementIndex] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printMagic – It prints the magic numbers of an ELF header.
 * @e_ident: Array pointer holding the ELF magic numbers.
 *
 * Commentary: Magic numbers are split by spaces.
 */
void printMagic(unsigned char *e_ident)
{
    printf("  Magic:   ");

    for (int elementIndex = 0; elementIndex < EI_NIDENT; elementIndex++)
    {
        printf("%02x", e_ident[elementIndex]);

        if (elementIndex == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printClass – It prints the class of an ELF header.
 * @e_ident: Array pointer holding the ELF class.
 */
void printClass(unsigned char *e_ident)
{
    printf("  Class:                             ");

    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printData -It prints the data of an ELF header.
 * @e_ident: Array pointer holding the ELF class.
 */
void printData(unsigned char *e_ident)
{
    printf("  Data:                              ");

    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printVersion – It prints the version of an ELF header.
 * @e_ident: Array pointer holding the ELF version.
 */
void printVersion(unsigned char *e_ident)
{
    printf("  Version:                           %d",
           e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * printOSABI – It prints the OS/ABI of an ELF header.
 * @e_ident: Array pointer holding the ELF version.
 */
void printOSABI(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");

    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/**
 *printABI – It prints the ABI version of an ELF header.
 * @e_ident: Array pointer holding the ELF ABI version.
 */
voidprintABI(unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n",
           e_ident[EI_ABIVERSION]);
}

/**
 * printType – It prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: Array pointer holding the ELF class.
 */
void printType (unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf("  Type:                              ");

    switch (e_type)
    {
    case ET_NONE:
        printf ("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

/**
 * printEntry – It prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: Array pointer holding the ELF class.
 */
void printEntry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:               ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);

    else
        printf("%#lx\n", e_entry);
}

/**
 * closeElf – It closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Commentary: If the file cannot be closed - exit code 98.
 */
void closeElf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

/**
 * main – It presents information found in the
 *        ELF header at the start of an ELF file.
 * @argx: The number of arguments supplied to the program.
 * @argz: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Commentary: If the file is not an ELF File or
 *              function fails - exit code 98.
 */
int main (int __attribute__((__unused__)) argx, char *argz[])
{
    Elf64_Ehdr *header;
    int src_fdesc, read_status;

    src_fdesc = open(argz[1], O_RDONLY);
    if (src_fdesc == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argz[1]);
        exit(98);
    }
    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        closeElf(src_fdesc);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argz[1]);
        exit(98);
    }
    src_fdescr= read(src_fdesc, header, sizeof(Elf64_Ehdr));
    if (src_fdescr== -1)
    {
        free(header);
        closeElf(src_fdesc);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argz[1]);
        exit(98);
    }

    checkElf(header->e_ident);
    printf("ELF Header:\n");
    printMagic(header->e_ident);
    printClass(header->e_ident);
    printData(header->e_ident);
    printVersion(header->e_ident);
    printOSABI(header->e_ident);
    printABI(header->e_ident);
    printType(header->e_type, header->e_ident);
    printEntry(header->e_entry, header->e_ident);

    free(header);
    closeElf(src_fdesc);
    return 0;
}














