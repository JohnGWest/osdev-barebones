# Contribution Guide

Thank you for contributing.

This guide contains the rules and conventions to be used for contributing to this project.

[[_TOC_]]

## Version

This project follows [Semantic Versioning](https://semver.org/). The intention behind this versioning scheme is to provide a simple set of rules and requirements that dictate how version numbers are assigned and incremented. These rules are based on pre-existing widespread common practices in use in both closed and open-source software.

Software versions _shall_ use the following convention:

<__major__>.<__minor__>.<__patch__>

- A change in a major revision denotes one or more breaking changes to the public API, either through a cahnge to the software or IO interfaces.
- A change in a minor revision denotes the addition of functionality or backwards-compatible API changes. In addition, defects may be resolved as part of a minor revision.
- A change in a patch revision denotes a modification to existing functionality that will not modify the existing API, such as documentation, refactoring, bug fixes, or performance enhancements.

## Commit Message Rules

* Commit messages _shall_ be no longer than 50 characters per line, but can be multiple lines long.
* Commit messages _shall_ meaningfully describe the contents of the commit.
* _Ideally_, squash commits into logical changes before merging into branches used for collaboration.
* Commit messages _shall_ follow the conventions outlined [here](https://www.conventionalcommits.org/en/v1.0.0/#specification), [quick summary](https://www.conventionalcommits.org/en/v1.0.0/#summary).

Commit types include the following:

* release: a commit that represents a release build.
* chore: a commit that represents a trivial level of work that does not modify source files.
* ci: a commit that adds new CI functionality
* docs: a commit that updates documentation
* feat: a commit that implements additional functionality.
* fix: a commit that fixes a bug or defect.
* perf: a commit that improves performance, without functional changes.
* refactor: a commit that refactors the code
* revert: a commit that reverts other previously commmited commits.
* style: a commit that corrects style errors and does not affect the meaning of code.
* test: a commit that updates or adds tests
* build: a commit that changes the build system or external dependencies

Example commit messages:

* 'feat(kernel): Implemented keyboard input.'
* 'bugfix: Fixed crash related to memory leak.'
* 'docs: Updated documentation on internal kernel library interfaces.'

## Tagging Rules

* Any tag starting in the format of v<MAJOR>.<MINOR>.<PATCH> is a protected tag by default.
* Any commit that denotes an increment of a version number should be tagged accordingly.
* All stable releases should be tagged.

## Repository Structure

This repository follows a variation of the [pitchfork](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs) convention.

The top-level directories shall be: 
* build/: Build artifacts
* src/: Source code
* tools/: Tooling scripts and other configuration
* docs/: Documentation and documentation generation source
* tests/: Unit tests, integration tests, and benchmark source code

