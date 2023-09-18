
set(CMAKE_CROSSCOMPILING ON)

set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_SYSTEM_PROCESSOR "aarch64")
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY") 

set(CLANG_TARGET_TRIPLE aarch64-none-elf)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})


set(ARCH_FLAGS "-mcpu=cortex-a57 -mthumb -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -mno-unaligned-access ")
set(ENVIRONMENT_FLAGS "-ffreestanding -nostdlib -nostartfiles -nodefaultlibs")
set(CMAKE_CXX_FLAGS_INIT "${ARCH_FLAGS} ${ENVIRONMENT_FLAGS} -fno-exceptions -fno-rtti -fno-threadsafe-statics")
set(CMAKE_C_FLAGS_INIT "${ARCH_FLAGS} ${ENVIRONMENT_FLAGS}")
set(CMAKE_ASM_FLAGS_INIT "${ARCH_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-ffreestanding -nostdlib -Wl,-Map,kernel.map,--gc-sections -fuse-linker-plugin")

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# For libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)