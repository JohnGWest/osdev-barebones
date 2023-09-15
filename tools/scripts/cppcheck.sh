
PROJECT_ROOT=$(git rev-parse --show-toplevel)
CPPCHECK_SCAN_DIR=$PROJECT_ROOT/src
CPPCHECK_ENABLED_CHECKS=all
CPPCHECK_FLAGS="--inline-suppr --quiet"
CPPCHECK_REPORT="$PROJECT_ROOT/build/cppcheck/report.xml"
CPPCHECK_BUILD_DIR="$PROJECT_ROOT/build/cppcheck/cache"

mkdir -p "$PROJECT_ROOT/build/cppcheck"
find $CPPCHECK_SCAN_DIR -iname *.c -or -iname *.cpp -or -iname *.h -or -iname *.hpp | \
  cppcheck --enable=${CPPCHECK_ENABLED_CHECKS} -j $(nproc) ${CPPCHECK_FLAGS}            \
    --xml --xml-version=2 --output-file=${CPPCHECK_REPORT}                              \
    --cppcheck-build-dir=${CPPCHECK_BUILD_DIR}                                          \
    --file-list=-
