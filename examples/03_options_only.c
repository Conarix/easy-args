// Desired usage: ./config [-c <config>] [-v] [--disable-cache]

// No required arguments for this example
#define OPTIONAL_ARGS \
    OPTIONAL_STRING_ARG(config_file, "config.ini", "-c", "config", "Configuration file path")

#define BOOLEAN_ARGS \
    BOOLEAN_ARG(verbose, 0, "-v", "Verbose output") \
    BOOLEAN_ARG(help, 0, "-h", "Show help")

#include "../includes/easyargs.h"

int main(int argc, char* argv[]) {
    args_t args = make_default_args();

    parse_args(argc, argv, &args);

    if (args.help) {
        print_help(argv[0]);
        return 1;
    }

    printf("Configuration file: %s\n", args.config_file);
    printf("Verbose: %s\n", args.verbose ? "on" : "off");
    
    return 0;
}