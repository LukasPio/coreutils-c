# coreutils-c

A collection of classic Unix/Linux utilities reimplemented in pure C.

The goal of this project is to learn **C programming**, **Linux system programming**, and the **POSIX API** by rebuilding common command-line tools from scratch, relying primarily on the system documentation (`man`) instead of external tutorials.

## Goals

* Learn low-level C programming
* Understand how Unix utilities work internally
* Practice POSIX APIs and Linux syscalls
* Build software with minimal external dependencies
* Improve debugging and systems programming skills

## Project Structure

```text
coreutils-c/
├── cat/
├── ls/
├── wc/
├── grep/
├── find/
├── cp/
├── mv/
├── rm/
├── mkdir/
├── touch/
└── README.md
```

Each utility is implemented independently and can be built and executed on its own.

## Planned Utilities

| Utility | Status |
| ------- | ------ |
| cat     | ⏳      |
| ls      | ⏳      |
| wc      | ⏳      |
| grep    | ⏳      |
| find    | ⏳      |
| echo    | ⏳      |
| touch   | ⏳      |
| mkdir   | ⏳      |
| rm      | ⏳      |
| cp      | ⏳      |
| mv      | ⏳      |

## Principles

* Pure C
* POSIX-first
* Minimal dependencies
* Readable code
* Learn by reading the manual pages (`man`)
* AI usage: **0%** ( except for this README :p ).

## Build

Each utility contains its own source code and can be compiled with GCC.

Example:

```sh
gcc cat.c -o cat
```

## References

This project intentionally uses the official Unix/Linux documentation as the primary learning resource.

Useful manual pages include:

* `man 2 open`
* `man 2 read`
* `man 2 write`
* `man 2 close`
* `man 2 stat`
* `man 3 opendir`
* `man 3 readdir`
* `man 7 signal`
* `man 7 pipe`

## License

MIT
