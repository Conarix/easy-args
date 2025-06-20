#define REQUIRED_ARGS \
    REQUIRED_STRING_ARG(input_path, "path/to/input", "Path to image input") \
    REQUIRED_FLOAT_ARG(contrast, "contrast", "Contrast applied to image") \
    REQUIRED_SIZE_ARG(index, "index", "The index of the frame") \
    // REQUIRED_ARG(char*, input_path, "path/to/input", "Path to image input", ) \
    REQUIRED_ARG(char*, output_path, "path/to/output", "Path to image output", ) \
    REQUIRED_ARG(double, contrast, "contrast", "Contrast applied to image", atof) \
    // REQUIRED_ARG(char*, b, NULL, "path/to/output", "Path to image output") \

#define OPTIONAL_ARGS \
    OPTIONAL_ARG(size_t, width, 64, "-w", "width", "Width of image", "%d", (size_t) atoi) \
    OPTIONAL_ARG(size_t, height, 64, "-h", "height", "Height of image", "%d", (size_t) atoi)

#define BOOLEAN_ARGS \
    BOOLEAN_ARG(grayscale, 1, "-bw", "Use black and white")

#include "../includes/easyargs.h"


int main(int argc, char* argv[]) {
    print_help(argv[0]);

    args_t args = make_default_args();
    parse_args(argc, argv, &args);

    printf("%s, %zu\n", args.input_path, args.width); //, args.output_path, args.contrast);
    // printf("%s, %s, %f\n", args.input_path, args.output_path, args.contrast);
}