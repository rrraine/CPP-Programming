 #include <iostream>
 #include "linkedList.h" 
 using namespace std;

 int main(){
    LinkedList* list = new LinkedList();
    Person* p;
    
    char op;

    do {
        cout << "Op: ";
		cin >> op;
		switch (op) {
			case 'a':
				p = new Person();
				cout << "Name: ";
				cin >> p->firstName >> p->lastName;
				cout << "Age: ";
				cin >> p->age;
				cout << "Requests (B,M,C,D): ";
				cin >> p->requests[0] >> p->requests[1] >> p->requests[2] >> p->requests[3];
				list->add(p);
				break;
			case 'B':
			case 'M':
			case 'C':
			case 'D':
				p = list->serveRequest(op);
				if (p) {
					cout << "Thanks for waiting, ";
					p->print_name();
				} else {
					cout << "No one in the waiting list." << endl;
				}
				break;
			case 'f':
				p = list->fastLane();
				if (p) {
					cout << "Fast lane for you, ";
					p->print_name();
				} else {
					cout << "No one in the waiting list." << endl;
				}
				break;
			case 'p':
				list->print();
				break;
			case 'x':
				
                delete list;
                cout << "Deleting the list. Exiting...";
				return 0;
		}
    } while (op != 'x');
    return 0;
 }