# Student Management System

## Overview
This Student Management System is a C++ console application designed to manage student records, course enrollment, attendance, and marks. The system provides a user-friendly interface for administrators to perform various academic operations.

## Features

### Course Management
- Add new courses with details like code, name, instructor, credits, and capacity
- View available courses
- Display course information

### Student Management
- Enroll new students with personal details
- Remove students from courses
- Edit student information
- View enrolled students

### Attendance System
- Mark attendance for students
- View attendance records by course

### Grading System
- Assign marks to students
- View student marks by course

## Technical Details

### Classes
- **Course**: Manages course information and student enrollment
- **Student**: Handles student data including attendance and marks
- **FileHandler**: Manages file operations for data persistence
- **System**: Main controller class with menu navigation
- **Help**: Utility class for string operations

### Data Storage
- Courses are stored in `courses.txt`
- Student data is stored in separate files per course (e.g., `[course_code].txt`)
- Attendance and marks are stored in individual student files

## How to Use
1. Compile and run the program
2. Use the main menu to navigate through options:
   - Enroll/Manage Students
   - Course Registration
   - Attendance Management
   - Marks Management
3. Follow on-screen prompts to perform operations

## Requirements
- C++ compiler (supporting C++11 or later)
- Windows OS (due to Windows.h dependency)

## Installation
1. Clone the repository
2. Compile all source files:
   ```
   g++ main.cpp -o StudentManagementSystem
   ```
3. Run the executable:
   ```
   ./StudentManagementSystem
   ```

## File Structure
```
StudentManagementSystem/
├── c.h                # Course class header
├── Filehandler.h      # FileHandler class header
├── Stu.h              # Student class header
├── main.cpp           # Main program implementation
└── courses.txt        # Course data storage
```

## Limitations
- Currently Windows-specific due to `Windows.h` usage
- File-based storage may have performance limitations with large datasets
- Limited input validation in some areas

## Future Enhancements
- Cross-platform compatibility
- Database integration
- Enhanced reporting features
- Graphical user interface
