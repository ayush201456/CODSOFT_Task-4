#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addTask(vector<string> &tasks) {
    cout << "Enter the task: ";
    string task;
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added.\n";
}

void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

void removeTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
    } else {
        cout << "Enter task number to remove: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number.\n";
        } else {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed.\n";
        }
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\n1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                removeTask(tasks);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
