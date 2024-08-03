#include <iostream> 
#include <vector> 
#include <string> 
 
using namespace std; 
 
struct Task { 
    string description; 
    bool completed; 
}; 
 
void addTask(vector<Task>& tasks) { 
    string task; 
    cout << "Enter task: "; 
    getline(cin, task); 
    tasks.push_back({task, false}); 
} 
 
void viewTasks(const vector<Task>& tasks) { 
    if (tasks.empty()) { 
        cout << "No tasks found.\n"; 
    } else { 
        cout << "Tasks:\n"; 
        for (int i = 0; i < tasks.size(); ++i) { 
            cout << i + 1 << ". " << tasks[i].description; 
            if (tasks[i].completed) { 
                cout << " (Completed)"; 
            } 
            cout << endl; 
        } 
    } 
} 
 
void markComplete(vector<Task>& tasks) { 
    int index; 
    cout << "Enter task number to mark as complete: "; 
    cin >> index; 
    if (index >= 1 && index <= tasks.size()) { 
        tasks[index - 1].completed = true; 
        cout << "Task marked as complete.\n"; 
    } else { 
        cout << "Invalid task number.\n"; 
    } 
} 
 
void deleteTask(vector<Task>& tasks) { 
    int index; 
    cout << "Enter task number to delete: "; 
    cin >> index; 
    if (index >= 1 && index <= tasks.size()) { 
        tasks.erase(tasks.begin() + index - 1); 
        cout << "Task deleted.\n"; 
    } else { 
        cout << "Invalid task number.\n"; 
    } 
} 
 
int main() { 
    vector<Task> tasks; 
    char choice; 
 
    do { 
        cout << "\nTo-Do List\n"; 
        cout << "1. Add task\n"; 
        cout << "2. View tasks\n"; 
        cout << "3. Mark task as complete\n"; 
        cout << "4. Delete task\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case '1': 
                addTask(tasks); 
                break; 
            case '2': 
                viewTasks(tasks); 
                break; 
            case '3': 
                markComplete(tasks); 
                break; 
            case '4': 
                deleteTask(tasks); 
                break; 
            case '5': 
                cout << "Exiting...\n"; 
                break; 
            default: 
                cout << "Invalid choice.\n"; 
        } 
    } while (choice != '5'); 
 
    return 0; 
}