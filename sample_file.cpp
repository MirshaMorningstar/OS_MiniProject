#include <iostream>
#include <string>
#include <cstdlib> // For system()

using namespace std;

void downloadYouTubeVideo(const string& url, const string& outputPath) {
    string command = "python3 download_video.py \"" + url + "\" \"" + outputPath + "\"";
    int result = system(command.c_str());
    if (result != 0) {
        cerr << "Failed to download the video. Please check the URL and output path." << endl;
    }
}

int main() {
    string option;
menu:
    cout << endl;
    cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "          x   SIMPLE  FILE  MANIPULATION    x" << endl;
    cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "          x [12] - Automated Video Extraction from Internet from WEB URL and Save x" << endl;
    cout << "          x [13] - Exit the program         x" << endl;
    cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\n          Enter Your Choice:    ";
    getline(cin, option);

    if (option == "12") {
        // Download YouTube Video
        system("clear");
        string url, outputPath;

        cout << "Enter the URL of the YouTube video: ";
        getline(cin, url);
        cout << "Enter the output path (including file name and extension): ";
        getline(cin, outputPath);

        downloadYouTubeVideo(url, outputPath);

        goto menu;
    }

    if (option == "13") {
        cout << "Exiting the program." << endl;
        return 0;
    }

    // Invalid option, return to menu
    system("clear");
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\tPlease input a valid number.\n";
    cout << "\t\t\tPress any key to go back to the Menu.\n\n\n\n\n\n\n";

    system("pause");
    system("clear");
    goto menu;

    return 0;
}
