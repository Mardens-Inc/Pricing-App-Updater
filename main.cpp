#include <iostream>
#include <filesystem>
#include <string>

int main(int argc, char *argv[]) {

    // check if the correct number of arguments are passed
    if (argc <= 2) {
        // set the color of the output to red
        fprintf(stderr, "\033[1;31m");
        // print the error message
        fprintf(stderr, "The Pricing App Updater takes 2 arguments\nUsage: ");
        // set the color to blue
        fprintf(stderr, "\033[1;34m");
        fprintf(stderr, ".\\updater.exe");
        fprintf(stderr, " \"/path/to/new.exe\" \"/path/to/current.exe\"\n");
        // reset the color of the output
        fprintf(stderr, "\033[0m");
        return 1;
    }

    // get the paths
    std::string tmp_exe_path = argv[1];
    std::string current_exe_path = argv[2];

    // check if the tmp exe exists
    if (!std::filesystem::exists(tmp_exe_path)) {
        // set the color of the output to red
        fprintf(stderr, "\033[1;31m");
        // print the error message
        fprintf(stderr, "Error: %s does not exist\n", tmp_exe_path.c_str());
        // reset the color of the output
        fprintf(stderr, "\033[0m");
        return 1;
    }

    try {

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
    } catch (const std::exception &e) {
        // set the color of the output to red
        fprintf(stderr, "\033[1;31m");
        // print the error message
        fprintf(stderr, "Failed to run the updater, please contact IT.\n\nError: %s\n", e.what());
        // reset the color of the output
        fprintf(stderr, "\033[0m");
        system("pause");
        return 1;
    }
    return 0;
}
