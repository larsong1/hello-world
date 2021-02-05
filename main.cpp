#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"

using namespace std;
int main(int argc, char *argv[]) {
  TodoList mylist;
  for(int i = 0; i < argc; i++) {
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }
  string firstarg = argv[1];
  if(firstarg.compare("add") == 0) {
    cout << "Doing and add" << endl;
    string date = argv[2];
    string task = argv[3];
    cout << "date: " << date << "task: " << task << endl;
    mylist.add(date, task);
  } else if (firstarg.compare("remove") == 0) {
		cout << "Doing a remove" << endl;
    string task = argv[2];
    cout << "task: " << task << endl;
    mylist.remove(task);
	} else if (firstarg.compare("printList") == 0) {
		cout << "Doing a printList" << endl;
    mylist.printTodoList();
	} else if (firstarg.compare("printDay") == 0) {
		cout << "Doing a printDay" << endl;
    string date = argv[2];
    cout << "date: " << date << endl;
    mylist.printDaysTasks(date);
	}
}