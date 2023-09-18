
set(CMAKE_CROSSCOMPILING ON)

set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_SYSTEM_PROCESSOR "x86_64")

set(CLANG_TARGET_TRIPLE i686-pc-none-elf)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})

set(CMAKE_CXX_FLAGS_INIT "-ffreestanding -nostdlib")
set(CMAKE_C_FLAGS_INIT "-ffreestanding -nostdlib")
set(CMAKE_ASM_FLAGS_INIT "-x assembler-with-cpp")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-ffreestanding -nostdlib")

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# For libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)