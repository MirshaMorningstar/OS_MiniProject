# OS File System Control and Deadlock Management with Multithreading

## Project Overview

This project focuses on two critical aspects of operating systems: efficient file system management and robust deadlock recovery mechanisms in multithreaded environments.

### Part 1: File System Management Tool

The first part of this project addresses the crucial challenge of managing file systems efficiently by implementing a comprehensive set of functionalities for manipulation and maintenance. It encompasses tasks such as file creation, viewing, modification, size retrieval, details extraction, clearing, and deletion.

#### Objectives
- **File Manipulation**: Implement functionalities for creating, viewing, modifying, and deleting files to facilitate efficient file manipulation.
- **File Details**: Provide features to obtain essential file details such as size, creation date, and modification date to aid in file analysis.
- **File Clearing**: Offer mechanisms for clearing file content to maintain data privacy and security.
- **User Interaction**: Ensure user interaction through an intuitive menu-driven interface for easy navigation and operation.
- **System Optimization**: Leverage system resources and programming constructs to optimize file management tasks and enhance overall system reliability.

### Part 2: Deadlock Management in Multithreaded Environments

The second part of the project tackles the critical challenge of ensuring system reliability and stability in multithreading environments through the implementation of robust deadlock recovery mechanisms. It covers strategies such as deadlock detection using algorithms like Banker's algorithm, emphasizing controlled resource allocation to prevent deadlocks.

#### Objectives
- **Deadlock Detection**: Implement a deadlock detection algorithm to periodically check for deadlock occurrences and identify the threads involved.
- **Resource Allocation**: Ensure consistent and controlled resource allocation to prevent deadlock situations. Utilize techniques such as resource hierarchies, request protocols, and preemption.
- **Recovery Mechanisms**: Develop a recovery mechanism to resolve deadlock scenarios, including preempting resources from threads or rolling back thread states.
- **Thread Synchronization**: Employ synchronization primitives like mutexes, semaphores, and condition variables to coordinate resource access among multiple threads effectively.
- **Testing and Validation**: Conduct extensive testing to validate the correctness and effectiveness of the deadlock recovery mechanisms. Test the system under various scenarios and edge cases to ensure robustness and reliability.

## Scope

### File System Management Tool
1. **File Manipulation**: 
    - Design and implement functionalities for creating, viewing, modifying, and deleting files to facilitate efficient file manipulation.
    - Develop mechanisms for users to interact with files through an intuitive menu-driven interface.
2. **File Details Extraction**: 
    - Implement features to obtain essential file details such as size, creation date, and modification date to provide users with comprehensive file information.
3. **File Clearing**: 
    - Provide a mechanism for clearing file content to enable users to maintain data privacy and security by securely erasing file contents.
4. **Error Handling and User Feedback**: 
    - Incorporate robust error handling mechanisms to handle file operation failures gracefully and provide informative error messages to users.
    - Ensure clear and concise user feedback throughout the file manipulation process to enhance user experience and usability.
5. **System Resource Optimization**: 
    - Leverage system resources efficiently to optimize file management tasks and enhance overall system performance.
    - Implement mechanisms to minimize resource consumption and maximize system responsiveness during file operations.

### Deadlock Management
1. **Deadlock Detection**: 
    - Design and implement a deadlock detection algorithm to periodically check for deadlock occurrences in the system.
    - Develop mechanisms to identify the threads involved in deadlock situations.
2. **Resource Allocation**: 
    - Implement resource allocation methods to ensure resources are allocated in a consistent and controlled manner.
    - Explore techniques such as resource hierarchies, request protocols, and preemption to avoid deadlock situations.
3. **Recovery Mechanism**: 
    - Design and implement a robust recovery mechanism to resolve deadlock scenarios effectively.
    - Develop algorithms to preempt resources from threads or roll back thread states to mitigate deadlocks.
4. **Thread Synchronization**: 
    - Utilize synchronization primitives such as mutexes, semaphores, and condition variables to coordinate resource access among multiple threads.
    - Ensure threads acquire and release resources in a synchronized manner to prevent deadlock situations.
5. **Testing and Validation**: 
    - Conduct extensive testing to validate the correctness and effectiveness of the deadlock recovery mechanisms.
    - Test the system under various scenarios and edge cases to ensure robustness and reliability.

## Limitations

### File Management Tool
1. **Interface**: 
    - Operates only on files with a terminal/shell-like interface. No sophisticated graphical user interfaces involved.
2. **Security**: 
    - File security features like authentication and password-protected encryption are not included in this mini-project.
3. **Offline Mode**: 
    - All file operations are considered functional only in offline mode and non-operational online.

### Deadlock Recovery and Management Tool
1. **Thread and Resource Limits**: 
    - The deadlock avoidance, prevention, and recovery module is implemented with a maximum of 5 threads and 3 resources for simplicity and accuracy.
2. **Real-World Applications**: 
    - More complicated recovery mechanisms and tools need to be deployed for real-world deadlock challenges.
3. **Banker’s Algorithm**: 
    - Suitable only for processes and threads with static resource/memory requirements.

## Algorithms

### File Management System

![image](https://github.com/MirshaMorningstar/OS_MiniProject/assets/84216040/d1aa790d-4701-400e-a669-24f997e6959f)

#### File Creation and Management Algorithm
1. **Initialization**: 
    - Initialize constants and variables for file management operations.
    - Set up a mutex for thread synchronization to ensure concurrent file operations are executed safely.
2. **File Creation**: 
    - Implement functionality to create a new file and initialize it with user-provided content.
    - Handle errors gracefully if file creation fails due to permission issues or other system constraints.
3. **File Viewing**: 
    - Develop mechanisms to allow users to view the contents of an existing file.
    - Ensure proper error handling if the file specified by the user cannot be opened or does not exist.
4. **File Modification**: 
    - Implement functionality for users to modify the content of an existing file.
    - Ensure that the original content of the file is replaced entirely with the new content provided by the user.
5. **File Deletion**: 
    - Provide options for users to delete unwanted files from the system.
    - Handle file deletion operations carefully to prevent accidental data loss and confirm user intent before proceeding.

#### File Information Retrieval Algorithm

![image](https://github.com/MirshaMorningstar/OS_MiniProject/assets/84216040/5f69c565-c08d-48d2-b0d5-32bfb47cc33f)

1. **Obtain File Size**: 
    - Develop mechanisms to retrieve the size of a specified file in bytes.
    - Utilize appropriate system calls or library functions to accurately determine the size of the file.
2. **Retrieve File Details**: 
    - Implement functionality to extract additional details about a file, such as its creation date, modification date, and other metadata.
    - Ensure that the retrieved file details are presented to the user in a clear and understandable format.

#### Error Handling and User Interaction
1. **Error Handling**: 
    - Implement robust error handling mechanisms to handle various exceptional scenarios, such as file not found, permission denied, or insufficient disk space.
2. **User Feedback**: 
    - Provide informative feedback to users regarding the outcome of file management operations, including success messages or error notifications.
3. **User Interface**: 
    - Design the user interface to be intuitive and user-friendly, guiding users through the file management process seamlessly.

### Deadlock Management using Multithreading

![image](https://github.com/MirshaMorningstar/OS_MiniProject/assets/84216040/82b8cbbc-c793-4d0d-bb50-9676d59a9041)


#### Deadlock Detection and Avoidance using Banker’s Algorithm
1. **Initialization**: 
    - Initialize constants NUM_RESOURCES and NUM_PROCESSES.
    - Initialize vectors available, maximum, allocation, need, and resourceGranted for resource management.
    - Acquire a mutex for thread synchronization.

![image](https://github.com/MirshaMorningstar/OS_MiniProject/assets/84216040/71063576-df31-42ed-a633-037f6205bc30)

2. **Resource Management**: 
    - Implement isSafe function to check if a process can proceed safely.
    - Implement releaseResources function to release resources held by a process.
    - Implement requestResources function to request resources for a process, ensuring deadlock prevention and recovery.
    - Develop processThread function to simulate resource allocation and deallocation for each process in a separate thread.
  
![image](https://github.com/MirshaMorningstar/OS_MiniProject/assets/84216040/ceea44ce-c492-4396-83b5-91be46042d66)

3. **Main Execution**: 
    - Prompt the user to input available instances of resources.
    - Prompt the user to input maximum instances of resources for each process.
    - Initialize threads for each process using processThread function.
    - Join all threads to synchronize their execution.

#### Deadlock Recovery Algorithm

![image](https://github.com/MirshaMorningstar/OS_MiniProject/assets/84216040/8691d13f-da34-48b3-b96b-e6a67558ed0f)

1. **Initialization**: 
    - Define constants NUM_THREADS, NUM_RESOURCES, MAX_SLEEP, and MAX_ITERATIONS.
    - Implement the ResourceManager class to manage resources, including a mutex, condition variable, and vector to track resource availability.
    - Initialize a random number generator for deadlock recovery.
2. **Resource Management**: 
    - Implement requestResource method in the ResourceManager class to request resources for a thread, ensuring mutual exclusion.
    - Implement releaseResource method in the ResourceManager class to release acquired resources, notifying waiting threads.
    - Develop recoverFromDeadlock method in the ResourceManager class to preempt resources in case of deadlock detection.
3. **Thread Execution**: 
    - Implement threadFunction to simulate resource acquisition and release by each thread.
    - Inside threadFunction, loop until reaching the maximum iterations.
    - Request resources using requestResource, simulate critical section execution, and release resources.
    - Detect deadlock and initiate recovery mechanism using recoverFromDeadlock if necessary.
4. **Main Execution**: 
    - Initialize the random number generator.
    - Create instances of the ResourceManager class.
    - Create threads, each executing the threadFunction with a unique thread ID and reference to the ResourceManager.
    - Join all threads to synchronize their execution and ensure proper termination.

#### Deadlock Prevention Using Semaphores, Mutex, Condition Variable, Multiple Threads

![image](https://github.com/MirshaMorningstar/OS_MiniProject/assets/84216040/7e4e9b9c-80e9-41df-ad82-5d20233f154c)

1. **Initialization**:
    - Define constants NUM_THREADS, NUM_RESOURCES, and MAX_SLEEP.
    - Implement the Semaphore class with methods wait and notify to control resource access.
    - Implement the ResourceManager class to manage resource acquisition and release.
2. **Resource Acquisition and Release**: 
    - Implement acquireResource method in the ResourceManager class to acquire resources, ensuring mutual exclusion.
    - Implement releaseResource method in the ResourceManager class to release acquired resources.
3. **Thread Execution**: 
    - Implement threadFunction to simulate resource acquisition and release by each thread.
    - Inside threadFunction, loop indefinitely.
    - Wait for a resource to become available using the Semaphore object's wait method.
    - Acquire a resource from the ResourceManager.
    - Perform some work, simulating critical section execution.
    - Release the acquired resource using the releaseResource method of the ResourceManager.
    - Notify the Semaphore object that a resource is available using the notify method.
4. **Main Execution**: 
    - Seed the random number generator.
    - Create instances of the ResourceManager and Semaphore classes.
    - Create threads, each executing the threadFunction with a unique thread ID.
    - Detach threads to allow them to run independently.
    - Sleep the main thread to allow child threads to execute.
    - Terminate the program after the specified duration.

By following these algorithms and implementing the specified functionalities, the project aims to enhance the reliability and stability of multithreaded systems while providing efficient file management tools and robust deadlock recovery solutions.
