#define REQUIRED_ARGS \
    REQUIRED_ARG(char*, input_path, NULL, "path/to/input", "Path to image input") \
    REQUIRED_ARG(char*, output_path, NULL, "path/to/output", "Path to image output") \
    REQUIRED_ARG(char*, contrast, NULL, "contrast", "Contrast applied to image") \
    // REQUIRED_ARG(char*, b, NULL, "path/to/output", "Path to image output") \

#define OPTIONAL_ARGS \
    OPTIONAL_ARG(size_t, width, 64, "-w", "width", "Width of image", %d, (size_t) atoi) \
    OPTIONAL_ARG(size_t, height, 64, "-h", "height", "Height of image", %d, (size_t) atoi)

#define BOOLEAN_ARGS \
    BOOLEAN_ARG(grayscale, 1, "-bw", "Use black and white")

#include "../includes/easyargs.h"


int main(int argc, char* argv[]) {
    print_help(argv[0]);
}