#include <stdio.h>
#include <stdlib.h>

// #define REQUIRED_ARG(type, name, default, label, description) ...
// #define OPTIONAL_ARG(type, name, default, flag, label, description, formatter, parser) ...
// #define BOOLEAN_ARG(name, default, flag, description) ...

// Count arguments
#ifdef REQUIRED_ARGS
#define REQUIRED_ARG(...) + 1
static const int REQUIRED_ARG_COUNT = 0 REQUIRED_ARGS;
#undef REQUIRED_ARG
#else
static const int REQUIRED_ARG_COUNT = 0;
#endif

#ifdef OPTIONAL_ARGS
#define OPTIONAL_ARG(...) + 1
static const int OPTIONAL_ARG_COUNT = 0 OPTIONAL_ARGS;
#undef OPTIONAL_ARG
#else
static const int OPTIONAL_ARG_COUNT = 0;
#endif

#ifdef BOOLEAN_ARGS
#define BOOLEAN_ARG(...) + 1
static const int BOOLEAN_ARG_COUNT = 0 BOOLEAN_ARGS;
#undef BOOLEAN_ARG
#else
static const int BOOLEAN_ARG_COUNT = 0;
#endif

// Arg struct
#define REQUIRED_ARG(type, name, ...) type name;
#define OPTIONAL_ARG(type, name, ...) type name;
#define BOOLEAN_ARG(name, ...) _Bool name;
typedef struct {
    #ifdef REQUIRED_ARGS
    REQUIRED_ARGS
    #endif
    #if defined(OPTIONAL_ARGS)
    OPTIONAL_ARGS
    #endif
    #if defined(BOOLEAN_ARGS)
    BOOLEAN_ARGS
    #endif
} args_t;
#undef REQUIRED_ARG
#undef OPTIONAL_ARG
#undef BOOLEAN_ARG

// Display help string
void print_help(char* exec_alias) {
    // USAGE SECTION
    printf("USAGE:\n");

    printf("\t%s ", exec_alias);

    #ifdef REQUIRED_ARGS
    if (REQUIRED_ARG_COUNT > 0 && REQUIRED_ARG_COUNT <= 3) {
        #define REQUIRED_ARG(type, name, default, label, ...) "<" label "> "
        printf(REQUIRED_ARGS);
        #undef REQUIRED_ARG
    } else {
        printf("<ARGUMENTS> ");
    }
    #endif

    if (OPTIONAL_ARG_COUNT + BOOLEAN_ARG_COUNT <= 3) {
        #ifdef OPTIONAL_ARGS
        #define OPTIONAL_ARG(type, name, default, flag, label, ...) "[" flag " <" label ">" "] "
        printf(OPTIONAL_ARGS);
        #undef OPTIONAL_ARG
        #endif

        #ifdef BOOLEAN_ARGS
        #define BOOLEAN_ARG(name, default, flag, ...) "[" flag "] "
        printf(BOOLEAN_ARGS);
        #undef BOOLEAN_ARG
        #endif
    } else {
        printf("[OPTIONS]");
    }

    printf("\n\n");

    // ARGUMENTS SECTION
    #ifdef REQUIRED_ARGS
    if (REQUIRED_ARG_COUNT > 0) {
        printf("ARGUMENTS:\n");
    
        #define REQUIRED_ARG(type, name, default, label, description) "\t<" label ">\t\t" description "\n"
        printf(REQUIRED_ARGS);
        #undef REQUIRED_ARG

        printf("\n");
    }
    #endif

    #if defined(OPTIONAL_ARGS) || defined(BOOLEAN_ARGS)
    printf("OPTIONS:\n");

    #ifdef OPTIONAL_ARGS
    #define OPTIONAL_ARG(type, name, default, flag, label, description, formatter, parser) "\t" flag " <" label ">\t\t" description "\n"
    printf(OPTIONAL_ARGS);
    #undef OPTIONAL_ARG
    #endif

    #ifdef BOOLEAN_ARGS
    #define BOOLEAN_ARG(name, default, flag, description) "\t" flag "\t\t" description "\n"
    printf(BOOLEAN_ARGS);
    #undef BOOLEAN_ARG
    #endif

    #endif
}