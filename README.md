<h2 align="center">
    <b>Tempfile</b>
</h2>

<p align="center">
    <img src="https://img.shields.io/badge/C++-17+-green">
    <img src="https://img.shields.io/badge/Bazel-6.4+-green">
    <img src="https://img.shields.io/badge/license-MIT-green">
</p>

**Tempfile** is a simple C++ library with support for the Bazel build system
for thread-safe creation of temporary files and directories. 

## Quick Start

```C++
#include <cassert>
#include <cstdlib>
#include <filesystem>

#include <tempfile/tempfile.hpp>

int main(void)
{
    std::filesystem::path dir = tempfile::mkdtemp();
    assert(std::filesystem::exists(dir));

    std::filesystem::path file = tempfile::mkstemp();
    assert(std::filesystem::exists(file));

    return EXIT_SUCCESS;
}
```

> [!NOTE]  
> If the OS API does not allow to create a file / directory, the functions are
> identical to calling `std::tmpnam(nullptr)`. In all other cases, the path to
> an already existing object is returned.

## Installation

Add the following lines to your `WORKSPACE`:

```python
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "tempfile",
    sha256 = "...",
    strip_prefix = "tempfile-1.0",
    url = "https://github.com/syubogdanov/tempfile/archive/refs/tags/v1.0.zip",
)
```

Now you can use the library for your needs:

```python
cc_library(
    name = "...",
    srcs = ["..."],
    hdrs = ["..."],
    deps = ["@tempfile"],
)
```

## License

MIT License, Copyright (c) 2023 Sergei Bogdanov. See [LICENSE](LICENSE) file.