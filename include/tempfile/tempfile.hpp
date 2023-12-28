#ifndef INCLUDE_TEMPFILE_TEMPFILE_HPP_
#define INCLUDE_TEMPFILE_TEMPFILE_HPP_

#include <filesystem>

namespace tempfile {

std::filesystem::path mkdtemp(void);

std::filesystem::path mkstemp(void);

}  // namespace tempfile

#endif  // INCLUDE_TEMPFILE_TEMPFILE_HPP_
