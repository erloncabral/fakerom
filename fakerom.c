#include <stdio.h>
#include <stdlib.h>

#define ROM_SIZE 1024
#define ROM_NAME "fake.rom"

void print_success(size_t size) {
    printf("Success: %s\t%zukb\n", ROM_NAME, size);
}

void print_help() {
    puts("FakeROM v1.0 (C) 2025 by Erlon Cabral");
    puts("Utility for create an empty ROM with specific size.\n");
    puts("Usage: fakerom -r <rom_size>");
    puts("-r <rom_size>\n\tEnter a ROM size like 4, 8, 16, 32 (max 500)...");
}

size_t write_rom_file(size_t size, char *buffer) {
    FILE *file = fopen(ROM_NAME, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error when try create an empty ROM file.\n");
        return 0;
    }

    size_t count = size / sizeof(buffer[0]);
    size_t write_size = fwrite(buffer, sizeof(buffer[0]), count, file);
    fclose(file);

    return write_size;
}

void make_rom(size_t size) {
    if (size <= 0 || size > 500) {
        printf("Invalid size: %zu\n", size);
        exit(EXIT_FAILURE);
    }

    size_t rom_size = size * ROM_SIZE;
    char *buffer = malloc(sizeof(char) * rom_size);
    
    size_t i;
    for (i = 0; i < rom_size; ++i) {
        buffer[i] = 0x00;
    }

    if (write_rom_file(rom_size, buffer) < rom_size) {
        fprintf(stderr, "Unable to create a ROM file of this size.\n");
        free(buffer);
        buffer = NULL;
        exit(EXIT_FAILURE);
    }
    
    free(buffer);
    buffer = NULL;

    print_success(rom_size);
}

int main(int argc, char **argv) {
    int optind;
    for (optind = 1; optind < argc && argv[optind][0] == '-'; ++optind) {
        switch (argv[optind][1]) {
        case 'r':
            make_rom(atoi(argv[optind + 1]));
            exit(EXIT_SUCCESS);
        default:
            break;
        }   
    }
    
    print_help();
    return EXIT_FAILURE;
}
