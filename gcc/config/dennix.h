#undef TARGET_COBALT
#define TARGET_COBALT 1

#undef LIB_SPEC
#define LIB_SPEC "-lc"

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC ""

#undef LIBUBSAN_SPEC
#define LIBUBSAN_SPEC ""

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS() \
  do { \
    builtin_define ("__cobalt__"); \
    builtin_define ("__unix__"); \
    builtin_assert ("system=cobalt"); \
    builtin_assert ("system=unix"); \
    builtin_assert ("system=posix"); \
  } while(0);

#undef SSIZE_TYPE
#define SSIZE_TYPE "long signed int"

#undef WCHAR_TYPE
#define WCHAR_TYPE "unsigned int"
