#include <iostream>
#include <fstream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstdio>
#include <unistd.h>
#include <string>
#include <vector>
#include <mutex>
#include <cstdlib> // For system()
#include <curl/curl.h>

using namespace std;
mutex fileMutex;

void downloadYouTubeVideo(const string& url, const string& outputPath) {
    cout << "Video Generator Loading" << endl;
    string command = "python3 download_video.py \"" + url + "\" \"" + outputPath + "\"";
    int result = system(command.c_str());
    if (result != 0) {
        cerr << "Failed to download the video. Please check the URL and output path." << endl;
    }
}

void displayFileMetadata(const std::string& filename) {
    struct stat fileInfo;
    if (stat(filename.c_str(), &fileInfo) != 0) {
        cerr << "Error: Unable to retrieve file metadata." << endl;
        return;
    }
    cout << "File Metadata:" << endl;
    cout << "File: " << filename << endl;
    cout << "Size: " << fileInfo.st_size << " bytes" << endl;
    cout << "Permissions: " << (fileInfo.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)) << endl;
    cout << "Created: " << ctime(&fileInfo.st_ctime);
    cout << "Last modified: " << ctime(&fileInfo.st_mtime);
}

size_t WriteCallback(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

bool downloadImage(const std::string& url, const std::string& outputPath) {
    CURL* curl;
    FILE* fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outputPath.c_str(), "wb");
        if (!fp) {
            cerr << "Failed to open file for writing: " << outputPath << endl;
            return false;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            fclose(fp);
            curl_easy_cleanup(curl);
            return false;
        }

        fclose(fp);
        curl_easy_cleanup(curl);
        return true;
    }
    return false;
}

int main() {
    // Display the title of the program
    cout << "##########################################################################\n";
    cout << "#                                                                        #\n";
    cout << "#                                                                        #\n";
    cout << "#                               OS PROJECT                               #\n";
    cout << "#                                                                        #\n";
    cout << "#                                                                        #\n";
    cout << "##########################################################################\n";
    cout << "  [][][] [][][] []     [][][]\n";
    cout << "  []       []   []     []\n";
    cout << "  [][]     []   []     [][]\n";
    cout << "  []       []   []     [] \n";
    cout << "  []     [][][] [][][] [][][]\n\n";
    cout << "  []    []   []   []]  [] [] [][][] []  [] []      []   [][][] [] [][][] []]  []\n";
    cout << "  []}[]{[] []  [] [][] [] [] []  [] []  [] []    []  []   []   [] []  [] [][] []\n";
    cout << "  [] [] [] [][][] [] [][] [] [][][] []  [] []    [][][]   []   [] []  [] [] [][]\n";
    cout << "  []    [] []  [] []  []] [] []     []  [] []    []  []   []   [] []  [] []  []]\n";
    cout << "  []    [] []  [] []   [] [] []     [][][] [][[] []  []   []   [] [][][] []   []\n\n";
    cout << "\n\n\t\t      Presented by: Ithikash and AK Mirsha \n\n\n\n\n\n\n";
    cout << "Press Enter to continue...";
    cin.get();
    system("clear");

    string option;
menu:
    cout << endl;
    cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "          x   SIMPLE  FILE  MANIPULATION      x" << endl;
    cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "          x [1]  - Save to a file             x" << endl;
    cout << "          x [2]  - View file content          x" << endl;
    cout << "          x [3]  - Modify file content        x" << endl;
    cout << "          x [4]  - Move file content          x" << endl;
    cout << "          x [5]  - Obtain file size           x" << endl;
    cout << "          x [6]  - File Details               x" << endl;
    cout << "          x [7]  - Clear the file             x" << endl;
    cout << "          x [8]  - Delete the file            x" << endl;
    cout << "          x [9]  - Backup File                x" << endl;
    cout << "          x [10] - File Metadata              x" << endl;
    cout << "          x [11] - Automated Image Extraction x" << endl;
    cout << "          x [12] - Automated Video Extraction x" << endl;
    cout << "          x [13] - Exit the program           x" << endl;
    cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\n          Enter Your Choice:    ";
    getline(cin, option);

    if (option == "1") {
        // Saving a new file
        system("clear");
        string textToSave;
        cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
        cout << "                       ENTER THE STRING YOU WANT TO SAVE   \n\n\n";
        cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n\n" << endl;
        cout << " HERE: \n";
        getline(cin, textToSave);
        std::string file_name;
        std::string ext = ".txt";

        cout << " Enter File Name you wish to create : ";
        cin >> file_name;
        ofstream saveFile(file_name + ext);
        saveFile << textToSave;
        cout << "" << endl << endl << endl << endl << endl << endl;
        saveFile.close();
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "2") {
        // View file content
        system("clear");
        std::string file_name;
        std::string ext = ".txt";

        cout << "Enter File Name you wish to view contents for: ";
        getline(cin, file_name);
        std::string combine = file_name + ext;

        ifstream loadFile(combine);
        if (!loadFile.is_open()) {
            cout << "Error: Unable to open file." << endl;
        } else {
            cout << "File Content:" << endl;
            cout << "--------------" << endl;
            char ch;
            while (loadFile.get(ch)) {
                cout << ch;
            }
            cout << endl;
            loadFile.close();
        }
        //system("pause");
        //system("clear");
        goto menu;
    }

    if (option == "3") {
        // Modify file content
        system("clear");
        std::string file_name;
        std::string ext = ".txt";

        cout << "Enter File Name you wish to modify: ";
        getline(cin, file_name);

        ofstream modifyFile(file_name + ext, ios::trunc); // Open file with trunc mode to clear existing content
        if (!modifyFile.is_open()) {
            cout << "Error: Unable to open file." << endl;
        } else {
            cout << "Enter the new content you want to write to the file (Press Enter twice to finish):" << endl;
            string line;
            while (getline(cin, line)) {
                if (line.empty()) {
                    break;
                }
                modifyFile << line << endl;
            }
            modifyFile.close();
            cout << "\n\n\n\n";
            cout << "File successfully modified." << endl;
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "4") {
        // Move file content
        system("clear");
        std::string sourceFile, destinationFile;
        std::string ext = ".txt";

        cout << "Enter Source File Name: ";
        getline(cin, sourceFile);
        cout << "Enter Destination File Name: ";
        getline(cin, destinationFile);

        ifstream src(sourceFile + ext, ios::binary);
        ofstream dst(destinationFile + ext, ios::binary);

        if (!src.is_open() || !dst.is_open()) {
            cout << "Error: Unable to open source or destination file." << endl;
        } else {
            dst << src.rdbuf(); // Copy content
            src.close();
            dst.close();
            remove((sourceFile + ext).c_str()); // Remove the source file
            cout << "File content successfully moved." << endl;
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "5") {
        // Obtain file size
        system("clear");
        std::string file_name;
        std::string ext = ".txt";

        cout << "Enter File Name to get its size: ";
        getline(cin, file_name);

        ifstream file(file_name + ext, ios::binary | ios::ate);
        if (!file.is_open()) {
            cout << "Error: Unable to open file." << endl;
        } else {
            streamsize size = file.tellg();
            file.close();
            cout << "File size: " << size << " bytes." << endl;
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "6") {
        // File details
        system("clear");
        std::string file_name;
        std::string ext = ".txt";

        cout << "Enter File Name to get its details: ";
        getline(cin, file_name);

        struct stat fileStat;
        if (stat((file_name + ext).c_str(), &fileStat) == -1) {
            cout << "Error: Unable to retrieve file details." << endl;
        } else {
            cout << "File Details:" << endl;
            cout << "--------------" << endl;
            cout << "File: " << file_name + ext << endl;
            cout << "Size: " << fileStat.st_size << " bytes" << endl;
            cout << "Permissions: " << (fileStat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)) << endl;
            cout << "Created: " << ctime(&fileStat.st_ctime);
            cout << "Last modified: " << ctime(&fileStat.st_mtime);
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "7") {
        // Clear the file
        system("clear");
        std::string file_name;
        std::string ext = ".txt";

        cout << "Enter File Name to clear its content: ";
        getline(cin, file_name);

        ofstream clearFile(file_name + ext, ios::trunc);
        if (!clearFile.is_open()) {
            cout << "Error: Unable to open file." << endl;
        } else {
            clearFile.close();
            cout << "File content cleared successfully." << endl;
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "8") {
        // Delete the file
        system("clear");
        std::string file_name;
        std::string ext = ".txt";

        cout << "Enter File Name to delete: ";
        getline(cin, file_name);

        if (remove((file_name + ext).c_str()) != 0) {
            cout << "Error: Unable to delete the file." << endl;
        } else {
            cout << "File deleted successfully." << endl;
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "9") {
        // Backup File
        system("clear");
        std::string file_name, backup_file_name;
        std::string ext = ".txt";

        cout << "Enter File Name to backup: ";
        getline(cin, file_name);
        cout << "Enter Backup File Name: ";
        getline(cin, backup_file_name);

        ifstream src(file_name + ext, ios::binary);
        ofstream dst(backup_file_name + ext, ios::binary);

        if (!src.is_open() || !dst.is_open()) {
            cout << "Error: Unable to open source or backup file." << endl;
        } else {
            dst << src.rdbuf(); // Copy content
            src.close();
            dst.close();
            cout << "File backup created successfully." << endl;
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "10") {
        // File Metadata
        system("clear");
        std::string file_name;
        std::string ext = ".txt";

        cout << "Enter File Name to get its metadata: ";
        getline(cin, file_name);

        displayFileMetadata(file_name + ext);
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "11") {
        // Automated Image Extraction
        system("clear");
        std::string imageUrl;
        std::string outputPath;

        cout << "Enter Image URL: ";
        getline(cin, imageUrl);
        cout << "Enter Output Path for the image: ";
        getline(cin, outputPath);

        if (downloadImage(imageUrl, outputPath)) {
            cout << "Image downloaded successfully." << endl;
        } else {
            cout << "Failed to download the image." << endl;
        }
        system("pause");
        system("clear");
        goto menu;
    }

    if (option == "12") {
        //cout<<"Video Downloader is currently loading...";
        // Automated Video Extraction
        //system("clear");
        std::string videoUrl;
        std::string outputPath;

        cout << "Enter Video URL: ";
        getline(cin, videoUrl);
        cout << "Enter Output Path for the video: ";
        getline(cin, outputPath);

        downloadYouTubeVideo(videoUrl, outputPath);

        // Exit the program after downloading the video
        exit(0);
    }

    if (option == "13") {
        // Exit the program
        system("clear");
        cout << "Exiting the program." << endl;
        return 0;
    }

    // Handle invalid menu options
    system("clear");
    cout << "Invalid option selected. Please try again." << endl;
    goto menu;
}
