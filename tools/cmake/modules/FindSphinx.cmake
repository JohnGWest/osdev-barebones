
set(Sphinx_ROOT "$ENV{Sphinx_ROOT}" CACHE PATH "Sphinx root installation directory.")

find_program( Sphinx_EXECUTABLE
    NAMES sphinx-build sphinx-build2
    PATHS
        "${Sphinx_ROOT}"
    DOC "PAth to sphinx-build executable."
)   

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    Sphinx
    "Failed to locate sphinx-build executable"
    Sphinx_EXECUTABLE
)
