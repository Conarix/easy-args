#if defined(REQUIRED_ARGS) || defined(OPTIONAL_ARGS) || defined(BOOLEAN_ARGS)

#include <stdio.h>
#include <stdlib.h>

// #define REQUIRED_ARG(type, name, default, label, description) ...
// #define OPTIONAL_ARG(type, name, default, flag, label, description, formatter, parser) ...
// #define BOOLEAN_ARG(name, default, flag, description) ...

// Count arguments
#define REQUIRED_ARG(...) + 1
#define OPTIONAL_ARG(...) + 1
#define BOOLEAN_ARG(...) + 1
static const int REQUIRED_ARG_COUNT = 0 REQUIRED_ARGS;
static const int OPTIONAL_ARG_COUNT = 0 OPTIONAL_ARGS;
static const int BOOLEAN_ARG_COUNT = 0 BOOLEAN_ARGS;
#undef REQUIRED_ARG
#undef OPTIONAL_ARG
#undef BOOLEAN_ARG

// Arg struct
#define REQUIRED_ARG(type, name, ...) type name;
#define OPTIONAL_ARG(type, name, ...) type name;
#define BOOLEAN_ARG(name, ...) _Bool name;
typedef struct {
    REQUIRED_ARGS
    OPTIONAL_ARGS
    BOOLEAN_ARGS
} args_t;
#undef REQUIRED_ARG
#undef OPTIONAL_ARG
#undef BOOLEAN_ARG

// Display help string
void print_help(char* exec_alias) {
    // USAGE SECTION
    printf("USAGE:\n");

    printf("\t%s ", exec_alias);

    if (REQUIRED_ARG_COUNT <= 3) {
        #define REQUIRED_ARG(type, name, default, label, ...) "<" label "> "
        printf(REQUIRED_ARGS);
        #undef REQUIRED_ARG
    } else {
        printf("<ARGUMENTS> ");
    }

    if (OPTIONAL_ARG_COUNT + BOOLEAN_ARG_COUNT <= 3) {
        #define OPTIONAL_ARG(type, name, default, flag, label, ...) "[" flag " <" label ">" "] "
        #define BOOLEAN_ARG(name, default, flag, ...) "[" flag "] "
        printf(
            OPTIONAL_ARGS
            BOOLEAN_ARGS
        );
        #undef OPTIONAL_ARG
        #undef BOOLEAN_ARG
    } else {
        printf("[OPTIONS]");
    }

    printf("\n\n");

    // ARGUMENTS SECTION
    printf("ARGUMENTS:\n");
    
    #define REQUIRED_ARG(type, name, default, label, description) "\t<" label ">\t\t" description "\n"
    printf(REQUIRED_ARGS);
    #undef REQUIRED_ARG

    printf("\n");

    printf("OPTIONS:\n");

    #define OPTIONAL_ARG(type, name, default, flag, label, description, formatter, parser) "\t" flag " <" label ">\t\t" description "\n"
    #define BOOLEAN_ARG(name, default, flag, description) "\t" flag "\t\t" description "\n"
    printf(OPTIONAL_ARGS);
    printf(BOOLEAN_ARGS);
    #undef OPTIONAL_ARG
    #undef BOOLEAN_ARG
}

#endif