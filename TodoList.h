#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include "TodoListInterface.h"
#include <vector>

using namespace std;

class TodoList: public TodoListInterface {
public:
		vector <string> tasks;
    TodoList() {
      cout << "In Constructor" << endl;
			ifstream infile ("TODOList.txt");
			string line;
			if (infile.is_open())
			{
				while ( getline (infile,line) )
				{
					cout << line << '\n';
					tasks.push_back(line);
				}
				infile.close();
			}
    }
    virtual ~TodoList() {
      cout << "In Destructor" << endl;
			ofstream outfile;
			outfile.open("TODOList.txt", ofstream::out | ofstream :: trunc);
			for(int i = 0; i < tasks.size(); i++) {
				cout << tasks[i] << '\n';
				outfile << tasks[i] << endl;
			}
			outfile.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
			tasks.push_back(_duedate);
			tasks.push_back(_task);
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
			for(int i = 0; i < tasks.size(); i++) {
				if (tasks[i] == _task) {
					tasks.erase(tasks.begin() + i);
					tasks.erase(tasks.begin() + i - 1);
				} else if (tasks[i] != _task){
					cout << tasks[i] << endl;
				}
			}
    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
			for(int i = 0; i < tasks.size(); i++) {
					cout << tasks[i] << endl;
			}
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
			for(int i = 0; i < tasks.size(); i++) {
				if (tasks[i] == _date) {
					cout << tasks[i] << endl << tasks[i + 1] << endl;
				}
			}
    }
};

#endif