#include <iostream>
#include <vector>
#include <memory>
#include <filesystem>

int main()
{
    auto recursiveGetFileNamesByExtension =
        [](std::filesystem::path path, const std::string ext)
    {
        std::vector<std::string> file_name;
        for (const auto& p : std::filesystem::recursive_directory_iterator(path))
        {
            if (p.is_regular_file())
            {
                if (!p.path().extension().compare(ext))
                    file_name.push_back(p.path().filename());
            }
        }
        return std::make_unique<std::vector<std::string>>(file_name);
    };

    auto file = recursiveGetFileNamesByExtension("C:\\Users\\anton\\Desktop\\skillbox\\lesson_35_3\\lesson_35_3", ".cpp");

    for (auto i = file->begin(); i != file->end(); ++i)
        std::cout << *i << "\n";
}