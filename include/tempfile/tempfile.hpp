#include <filesystem>

namespace tempfile
{

std::filesystem::path mkdtemp(void);

std::filesystem::path mkstemp(void);

} // namespace tempfile
