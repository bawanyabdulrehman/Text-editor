# Text Editor

Text Editor is a simple console-based program that allows users to create, open, edit, and delete text files. It provides basic functionalities similar to a text editor, such as adding, deleting, and modifying text within files. 

## Features

- **Create New File**: Users can create a new text file by providing a filename.
- **Open Existing File**: Existing text files can be opened for viewing or editing.
- **Delete File**: Users can delete an existing file.
- **List Files**: Lists all existing files.
- **Save File**: Users can save the changes made to a file.

### Editing Options

- **Edit Line**: Users can edit a specific line within the file.
- **Undo/Redo**: Provides undo and redo functionalities for editing actions.
- **Add Text**: Allows users to add more text to the file.
- **Delete Line**: Users can delete a specific line from the file.
- **Insert at Line**: Allows insertion of text at a specific line in the file.
- **Copy/Move Line**: Provides options to copy or move lines within the file.

### Viewing Options

- **View Complete File**: Displays the entire content of the file.
- **View Single Line**: Displays a single line from the file.
- **View Multiple Lines**: Displays a range of lines from the file.

## Usage

1. **Creating a New File**: 
    ```
    new <filename>
    ```

2. **Opening an Existing File**: 
    ```
    open <filename>
    ```

3. **Deleting a File**: 
    ```
    delete <filename>
    ```

4. **Listing Existing Files**: 
    ```
    list
    ```

5. **Saving a File**: 
    Type `#save` command after adding text.

6. **Editing Options**: 
    - Type `e<n>` to edit a specific line.
    - Press `u` to undo, `r` to redo.
    - Type `a` to add text, `d<n>` to delete a line.
    - Type `i<n>` to insert at a line, `c<m><n>` to copy, `m<m><n>` to move.

7. **Viewing Options**: 
    - Press space bar to access viewing options.
    - Type `p<0>` to view complete file, `p<n>` for a single line.
    - Type `t<m><n>` to view multiple lines.

## Installation

1. Clone the repository:
    ```
    git clone https://github.com/your-username/text-editor.git
    ```

2. Compile the program:
    ```
    g++ main.cpp -o text_editor
    ```

3. Run the program:
    ```
    ./text_editor
    ```
