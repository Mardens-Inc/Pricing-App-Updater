#include <iostream>
#include <filesystem>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: pricing-app-updater.exe <path_to_tmp_exe> <path_to_current_exe> \n");
        return 1;
    }
    std::string tmp_exe_path = argv[1];
    std::string current_exe_path = argv[2];

    if (!std::filesystem::exists(tmp_exe_path)) {
        fprintf(stderr, "Error: %s does not exist\n", tmp_exe_path.c_str());
        return 1;
    }

    // kill the current exe
    std::string command = "taskkill /F /IM pricing-app.exe";
    system(command.c_str());
    // delete current exe
    if (std::filesystem::exists(current_exe_path))
        std::filesystem::remove(current_exe_path);
    // move current exe to current directory
    std::filesystem::copy(tmp_exe_path, current_exe_path);
    std::filesystem::remove(tmp_exe_path);
    // start the new exe in the background
    std::system(current_exe_path.c_str());
    return 0;
}
