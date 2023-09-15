
PROJECT_ROOT=$(git rev-parse --show-toplevel)
IWYU_COMPILATION_DATABASE="$PROJECT_ROOT/build/compile-commands.json"
IWYU_REPORT="$PROJECT_ROOT/build/iwyu/report.txt"
IWYU_SCAN_DIR="$PROJECT_ROOT/src"

cmake -B build -S .
iwyu_tool -P $IWYU_COMPILATION_DATABASE -j $(nproc) $IWYU_SCAN_DIR | tee $IWYU_REPORT