#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct todolist
{
    int id;
    string status;
    string task;
};

int id = 0;

void initializeId()
{
    ifstream fin("todo.txt");
    string line;
    while (getline(fin, line))
    {
        if (line.find(":") != string::npos)
        {
            int currentId = stoi(line.substr(0, line.find(":")));
            if (currentId > id)
                id = currentId;
        }
    }
    fin.close();
}

void addTask()
{
    system("cls");
    todolist todo;
    cout << "Enter new task: ";
    cin.ignore();
    getline(cin, todo.task);
    char save;
    cout << "Save? (y/n): ";
    cin >> save;
    if (save == 'y')
    {
        id++;
        ofstream fout("todo.txt", ios::app);
        fout << id << ": PENDING: " << todo.task << endl;
        fout.close();
        cout << "Task added successfully!\n";

        char moreTask;
        cout << "Add more task? (y/n) : ";
        cin >> moreTask;
        if (moreTask == 'y')
        {
            addTask();
        }
        else
        {
            system("cls");
            cout << "Added Successfully!" << endl;
            return;
        }
    }
    system("cls");
}

void viewTask()
{
    system("cls");
    ifstream fin("todo.txt");
    string line;
    bool empty = true;

    cout << "Your Tasks:\n";
    while (getline(fin, line))
    {
        if (!line.empty())
        {
            cout << "\t" << line << endl;
            empty = false;
        }
    }

    if (empty)
        cout << "\tList is Empty\n";

    fin.close();
}

void markAsCompleted()
{
    system("cls");
    viewTask();
    cout << "\nEnter task ID to mark as completed: ";
    int targetId;
    cin >> targetId;

    ifstream fin("todo.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;

    while (getline(fin, line))
    {
        if (!line.empty() && line.find(":") != string::npos)
        {
            int idPos = line.find(":");
            int statusPos = line.find(":", idPos + 1);

            int currentId = stoi(line.substr(0, idPos));
            string status = line.substr(idPos + 2, statusPos - idPos - 2);
            string taskText = line.substr(statusPos + 2);

            if (currentId == targetId)
            {
                temp << currentId << ": COMPLETED: " << taskText << endl;
                found = true;
            }
            else
            {
                temp << line << endl;
            }
        }
    }

    fin.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");

    if (found)
        cout << "Task marked as completed!\n";
    else
        cout << "Task ID not found.\n";
}

void removeTask()
{
    system("cls");
    viewTask();
    cout << "\nEnter task ID to remove: ";
    int targetId;
    cin >> targetId;

    ifstream fin("todo.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;

    while (getline(fin, line))
    {
        if (!line.empty() && line.find(":") != string::npos)
        {
            int currentId = stoi(line.substr(0, line.find(":")));
            if (currentId == targetId)
            {
                found = true;
                continue;
            }
            else
            {
                temp << line << endl;
            }
        }
    }

    fin.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");

    if (found)
        cout << "Task removed successfully!\n";
    else
        cout << "Task ID not found.\n";
}

int main()
{
    initializeId();
    while (true)
    {
        cout << "\n----- To-Do List Manager -----\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTask();
            break;
        case 3:
            markAsCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, try again\n";
        }
    }
}
