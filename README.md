# File Organizer

A simple C program to organize files in a specified directory by sorting them into folders based on their file type extensions (e.g., images, documents, audio, etc.). This program creates folders for each category (e.g., "Images," "Documents") and moves files into their respective folders.

## Features

- **Automatic Categorization**: Sorts files into specific folders based on file extensions.
- **Duplicate File Handling**: Avoids duplicate files by appending a suffix to the filename if necessary.
- **Detailed Summary**: Displays a summary of files moved and errors encountered.

## Folder Structure

Files are organized into these folders:

- **Images**: `jpg`, `jpeg`, `png`, `gif`, `bmp`, `tiff`, `svg`
- **Documents**: `pdf`, `doc`, `docx`, `txt`, `rtf`, `odt`, `xls`, `xlsx`, `ppt`, `pptx`
- **Audio**: `mp3`, `wav`, `wma`, `flac`, `m4a`, `aac`
- **Video**: `mp4`, `avi`, `mkv`, `mov`, `wmv`, `flv`
- **Code**: `py`, `js`, `html`, `css`, `cpp`, `cs`, `java`, `php`
- **Archives**: `zip`, `rar`, `7z`, `tar`, `gz`
- **Others**: Any other file types or files without an extension

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Seuketchi/FileOrganizer.git
   cd file-organizer
   ```
2. **Compile the Code**: Use GCC or any C compiler to compile the program:
   ```bash
   gcc -o file_organizer file_organizer.c
   ```
3. **Run the Program**:
   ```bash
   ./file_organizer
   ```

## Usage

1. Place `file_organizer` in the directory you wish to organize or navigate to the target directory.
2. Run the program from the terminal.
3. The program will:
   - Create necessary folders if they don’t already exist.
   - Organize files in the directory into respective folders based on their file type.

### Example Output

```
FILE ORGANIZER
----------------
Current working directory: /path/to/your/directory
Starting file organization...

MOVED: example.jpg -> Images/example.jpg
MOVED: example.pdf -> Documents/example.pdf
MOVED: example.mp3 -> Audio/example.mp3
Error moving file: duplicate.mp4
...

Organization Complete!
Files moved successfully: 15
Errors encountered: 1
```

## Notes

- Ensure you have permission to move files in the specified directory.
- This program uses standard C libraries and does not require additional dependencies.

## Contributing

Contributions are welcome! Feel free to submit a pull request to enhance functionality or add more file categories.

## License

This project is open-source and available under the [MIT License](LICENSE).
