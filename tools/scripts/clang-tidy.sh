
PROJECT_ROOT=$(git rev-parse --show-toplevel)
CLANG_TIDY_SCAN_DIR="$PROJECT_ROOT/src"
CLANG_TIDY_COMPILATION_DATABASE="$PROJECT_ROOT/build/compile_commands.json"
CLANG_TIDY_REPORT="$PROJECT_ROOT/build/clang-tidy/report.yml"
CLANG_TIDY_LOG="$PROJECT_ROOT/build/clang-tidy/log.txt"

mkdir -p "$PROJECT_ROOT/build/clang-tidy"
cmake -B build -S .
clang-tidy --export-fixes=$CLANG_TIDY_REPORT -p CLANG_TIDY_COMPILATION_DATABASE $(find $CLANG_TIDY_SOURCE_DIR -iname *.c -or -iname *.cpp -or -iname *.h -or -iname *.hpp) | tee $CLANG_TIDY_LOG
