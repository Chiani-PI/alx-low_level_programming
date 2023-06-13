#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void inspect_elf(unsigned char *f_idnt);
void print_magic(unsigned char *f_idnt);
void print_class(unsigned char *f_idnt);
void print_data(unsigned char *f_idnt);
void print_version(unsigned char *f_idnt);
void print_osabi(unsigned char *f_idnt);
void print_abiver(unsigned char *f_idnt);
void print_type(unsigned int f_type, unsigned char *f_idnt);
void print_entrypa(unsigned long int f_entrypa, unsigned char *f_idnt);
void close_elf(int elf);

/**
 * inspect_elf – Function will check if a file is an ELF file
 * @f_idnt: The pointer to an array which contains ELF magic numbers
 *
 * Description: This function verifies whether the file is an ELF file
 * by comparing the magic numbers. If the file is not an ELF file,
 * it exits with an exit code of 98
 */
void inspect_elf(unsigned char *f_idnt)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (f_idnt[indx] != 127 &&
		    f_idnt[indx] != 'E' &&
		    f_idnt[indx] != 'L' &&
		    f_idnt[indx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic – Function prints the magic nums of an ELF header
 * @f_idnt: The pointer to an array which contains ELF magic numbers
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *f_idnt)
{
	int indx;

	printf(" Magic: ");

	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", f_idnt[indx]);

		if (indx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class – Function prints the class of an ELF header
 * @f_idnt: The pointer to an array which contains the ELF class
 */
void print_class(unsigned char *f_idnt)
{
	printf(" Class: ");

	switch (f_idnt[EI_CLASS])
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
		printf("<unknown: %x>\n", f_idnt[EI_CLASS]);
	}
}

/**
 * print_data – Funcction prints the data of an ELF header
 * @f_idnt: The pointer to an array which contains the ELF class
 */
void print_data(unsigned char *f_idnt)
{
	printf(" Data: ");

	switch (f_idnt[EI_DATA])
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
		printf("<unknown: %x>\n", f_idnt[EI_CLASS]);
	}
}

/**
 * print_version – Function prints the version of an ELF header
 * @f_idnt: The pointer to an array which contains the ELF version
 */
void print_version(unsigned char *f_idnt)
{
	 printf(" Version: %d",
			  f_idnt[EI_VERSION]);

	switch (f_idnt[EI_VERSION])
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
 * print_osabi – Function prints the OS/ABI of an ELF header
 * @f_idnt: The pointer to an array which contains the ELF version
 */
void print_osabi(unsigned char *f_idnt)
{
	printf(" OS/ABI: ");

	switch (f_idnt[EI_OSABI])
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
		printf("<unknown: %x>\n", f_idnt[EI_OSABI]);
	}
}

/**
 * print_abiver – Function prints the ABI version of an ELF header
 * @f_idnt: The pointer to an array which contains the ELF version
 */
void print_abiver(unsigned char *f_idnt)
{
	printf(" ABI Version: %d\n",
		f_idnt[EI_ABIVERSION]);
}

/**
 * print_type – Function prints the type of an ELF header
 * @f_type: Type for ELF
 * @f_idnt: The pointer to an array which contains the ELF class
 */
void print_type(unsigned int f_type, unsigned char *f_idnt)
{
	if (f_idnt[EI_DATA] == ELFDATA2MSB)
		f_type >>= 8;

	printf(" Type: ");

	switch (f_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", f_type);
	}
}

/**
 * print_entrypa – Function prints the entry point of an ELF header
 * @f_entrypa: ELF entry point adress
 * @f_idnt: The pointer to an array which contains the ELF class
 */
void print_entrypa(unsigned long int f_entrypa, unsigned char *f_idnt)
{
	printf(" Entry point address: ");

	if (f_idnt[EI_DATA] == ELFDATA2MSB)
	{
		f_entrypa = ((f_entrypa << 8) & 0xFF00FF00) |
			  ((f_entrypa >> 8) & 0xFF00FF);
		f_entrypa = (f_entrypa << 16) | (f_entrypa >> 16);
	}

	if (f_idnt[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)f_entrypa);

	else
		printf("%#lx\n", f_entrypa);
}

/**
 * close_elf – Function closes an ELF file
 * @elf: ELF file descriptor
 *
 * Description: If the file can’t be closed, Exit code is 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main – Function will show the information contained in the ELF header
 * at the beginning of an ELF file
 * @argc: The tnumb of arguments passed into the program
 * @argv: The array of pointers which point to the arguments
 *
 * Return: 0 if success
 *
 * Description: If file isn’t an ELF File or the func fails, Exit code is 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	inspect_elf(header->f_idnt);
	printf("ELF Header:\n");
	print_magic(header->f_idnt);
	print_class(header->f_idnt);
	print_data(header->f_idnt);
	print_version(header->f_idnt);
	print_osabi(header->f_idnt);
	print_abiver(header->f_idnt);
	print_type(header->f_type, header->f_idnt);
	print_entrypa(header->f_entrypa, header->f_idnt);

	free(header);
	close_elf(o);
	return (0);
}
