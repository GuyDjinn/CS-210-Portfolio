# CS 210 Portfolio: Corner Grocer Item Tracker

## Project Summary
The Corner Grocer application is a C++ item-tracking tool designed to analyze daily grocery purchase records. It processes an input text file containing raw transaction data, aggregates item frequencies, and provides a menu-driven console interface for store staff. The system allows users to look up the purchase count for an individual item, view a complete frequency list of all items sold, and display a text-based histogram representing sales volume. Additionally, it writes the aggregated frequency data to an output backup file (`frequency.dat`) upon initialization.

## Highlights and Strengths
The project excels in its data structure selection and clean object-oriented design. Using a `std::map<std::string, int>` allowed for efficient key-value storage and automatic alphabetical sorting of inventory items. Separating file operations, menu logic, and reporting into dedicated class methods ensured single-responsibility principles were maintained. Input validation was also handled robustly to prevent infinite loops on invalid menu choices.

## Areas for Enhancement
Future revisions could improve efficiency, security, and robustness in several ways:
- **Case-Insensitive Searching:** Normalizing user queries and data input to lowercase would prevent lookup misses caused by capitalization differences (e.g., "Apples" vs. "apples").
- **Dynamic File Paths & Error Logging:** Instead of hardcoding filenames, accepting file paths via configuration or command-line arguments would increase flexibility. Implementing structured exception handling (`try`/`catch`) and error logging would improve resilience against missing or corrupted data files.
- **Data Scaling:** If transaction volume grew significantly, transitioning from a balanced binary search tree (`std::map`) to a hash table (`std::unordered_map`) would optimize average-case lookups from O(log n) to O(1).

## Challenges and Resources
The most challenging aspect was implementing clean input validation during user prompts—specifically clearing the stream buffer using `std::cin.clear()` and `std::cin.ignore()` to handle invalid data types without hanging or terminating the console loop. To solve this, I reviewed C++ standard library documentation on stream states, referenced course lecture notes, and utilized interactive debugging within the IDE to trace variable states step by step.

## Transferable Skills
Key skills transferable to future software development coursework and projects include:
- Designing modular, maintainable classes with clean separation of interface and implementation.
- Selecting appropriate STL containers (`std::map`, `std::vector`) based on algorithmic complexity and data requirements.
- Standard file I/O operations (reading unstructured text files and persisting formatted backup data).
- Defending against unexpected runtime inputs with rigorous validation loops.

## Maintainability, Readability, and Adaptability
The codebase adheres to industry naming conventions and consistent formatting throughout:
- **Self-Documenting Code:** Variables and functions use descriptive identifiers (e.g., `DisplayHistogram()`, `itemFrequencies`) rather than generic labels.
- **In-Line & Block Documentation:** Function headers outline parameters, return values, and operational logic clearly.
- **Modular Structure:** File parsing is decoupled from presentation logic, meaning the display interface could easily be adapted to a graphical user interface (GUI) or web API without modifying the underlying data aggregation logic.
