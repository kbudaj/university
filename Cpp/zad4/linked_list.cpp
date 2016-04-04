#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class List {
    class Node {
        Node* next;
        string text;
        int index;
        friend class List;
      public:
        Node(const string& value, int i) : next(nullptr), index(i), text(value) {}
        friend ostream& operator<< (ostream& wy, const Node& wzl) {
            if (wzl.next) return wy << wzl.text << ", " << *wzl.next;
            else return wy << wzl.text;
        }
    };
    
    Node* head;

    int _size(Node* node, int size = 0) { 
        if (node == NULL) {
            return size;
        } else {
            _size(node->next, size+1);
        }
    }

    void _insert(Node* node, const string& value, int index) {
        if (node->next == NULL || node->next->index > index) {
            if (node->index == index) {
                node->text = value;
            } else {
                Node* element = new Node(value, index);
                element->next = node->next;
                node->next = element;
            }
        } else {
            _insert(node->next, value, index);
        }
    }
    
    string _read(Node* node, int index) {
        if (node->next != NULL && node->next->index <= index) {
            return _read(node->next, index);
        } else if (node->index == index) {
            return node->text;
        } else {
            throw invalid_argument("No such index");
        }
    }

    void _remove(Node* node, int index) {
        if (node->next != NULL && node->next->index < index) {
            _remove(node->next, index);
        } else if (node->next != NULL && node->next->index == index) {
            Node* temp;

            if (node->next->next != NULL) {
                int temp_index = node->next->next->index;
                temp = new Node(node->next->next->text, temp_index);
                if (node->next->next->next != NULL) { 
                    temp->next = node->next->next->next;
                } else {
                    temp->next = NULL;
                }
                temp->index = node->next->next->index;
            } else {
                temp = nullptr;
            }

            delete node->next;
            node->next = temp;
        } else {
            throw invalid_argument("No such index");
        }
    }
    
    friend void _swap(List& first, List& second) {
        swap(first.head, second.head);
    }

public:
    List() : head(nullptr){};
    List(const List &lst) : head(nullptr) {
        Node* tmp_lst = lst.head;
        Node** tmp_current = &head;

        while (tmp_lst != NULL) {
            Node* tmp_this = new Node(tmp_lst->text, tmp_lst->index);

            *tmp_current = tmp_this;
            tmp_current = &tmp_this->next;

            tmp_lst = tmp_lst->next;
        }
    }

    List(List&& lst) {
        this->head = lst.head;
        lst.head = nullptr;
    };

    List(initializer_list<string> lst) : List() {
        Node* tmp;
        int pos = 0;
        for (auto element : lst) {
            if (this->head != NULL){
                tmp->next = new Node(element, pos);
                tmp = tmp->next;
                pos++;
            } else {
                this->head = new Node(element, pos);
                tmp = this->head;
                pos++;
            }
        }
    };
    List& operator= (const List& lst) {
        List tmp(lst);
        _swap(*this, tmp);
        return *this;
    }
    List& operator= (List&& lst) {
        if (this != &lst) {
            delete this->head;

            this->head = lst.head;
            lst.head = nullptr;
        }
        return *this;
    };
    ~List(){
        delete head;    
    };

    void insert(const string& value, int pos) {
        if (pos < 0) {
            throw invalid_argument("Position cant be negative");
        }

        if (this->head == NULL) { // Nie ma zadnego elementu => tworzenie glowy
            Node* new_head = new Node(value, pos);
            this->head = new_head;
        } else if (this->head->index > pos) { // Glowa ma wiekszy index niz wkladany element => zmiana glowy
            Node* new_head = new Node(value, pos);
            new_head->next = this->head;
            this->head = new_head;
        } else { // Inny rekurencyjnie
            _insert(this->head, value, pos);
        }
    }

    string read(int pos) {
        return _read(this->head, pos);
    }    

    int size() {
       return _size(this->head);
    }

    void remove(int pos) {
        return _remove(this->head, pos);
    }

public:
    friend ostream& operator<< (ostream& wy, const List& lst) {
        if (lst.head) return wy << "(" << *lst.head << ")";
        else return wy << "()";
    }
};

int main() {
    // Tests 

    cout << "---------------------------------------------------" << endl;
    cout << "Initialiser list, read(), remove(), insert(), size()" << endl;
    cout << "---------------------------------------------------" << endl;

    List l{"jeden", "dwa", "trzy", "cztery", "piec"};
    cout << "> List l{\"jeden\", \"dwa\", \"trzy\", \"cztery\", \"piec\"}" << endl << l << endl;
    
    cout << "> l.read(3)" << endl << l.read(3) << endl;

    l.remove(3);
    cout << "> l.remove(3)" << endl << l << endl;
    
    l.insert("nowy_cztery", 3);
    cout << "> l.insert(\"nowy_cztery\", 3)" << endl << l << endl;

    l.insert("dwanascie", 12);
    cout << "> l.insert(\"dwanascie\", 12)" << endl << l << endl;

    l.insert("nowy_dwanascie", 12);
    cout << "> l.insert(\"nowy_dwanascie\", 12)" << endl << l << endl;

    cout << "> l.read(12)" << endl << l.read(12) << endl;
    
    cout << "> l.size()" << endl << l.size() << endl;

    
    cout << "---------------------------------------------------" << endl;
    cout << "Setting correct position by index" << endl;
    cout << "---------------------------------------------------" << endl;
    List k;
    k.insert("zero", 0);
    cout << "> List k" << endl;
    cout << "> k.insert(\"zero\", 0)" << endl << k << endl;

    k.insert("cztery", 4);
    cout << "> k.insert(\"cztery\", 4)" << endl << k << endl;

    k.insert("dwa", 2);
    cout << "> k.insert(\"dwa\", 2)" << endl << k << endl;

    k.insert("jeden", 1);
    cout << "> k.insert(\"jeden\", 1)" << endl << k << endl;
    
    cout << "---------------------------------------------------" << endl;
    cout << "Copy Constructor & Operator" << endl;
    cout << "---------------------------------------------------" << endl;
    List b(k);
    cout << "> List b(k);" << endl << "b: " << b << endl;
    
    List e = b;
    cout << "> List e = b;" << endl << "e: " << e << endl;

    b.remove(2);
    cout << "> b.remove(2);" << endl << "b: " << b << endl;
    cout << "e: " << e << endl;
    
    cout << "---------------------------------------------------" << endl;
    cout << "Move Constructor & Operator" << endl;
    cout << "---------------------------------------------------" << endl;
    List t(move(b));
    cout << ">List t(move(b))" << endl;
    cout << "t: " << t << endl;
    cout << "b: " << b << endl;

    List w = move(t);
    cout << ">List w = move(t)" << endl;
    cout << "w: " << w << endl;
    cout << "t: " << t << endl;
    
    cout << "---------------------------------------------------" << endl;
    cout << "Exception tests" << endl;
    cout << "w: " << w << endl;
    cout << "---------------------------------------------------" << endl; 
    int t_choice;

    cout << "Test:" << endl;
    cout << "\t 0) Quit" << endl;
    cout << "\t 1) Insert (invalid index)" << endl;
    cout << "\t 2) Read (invalid index)" << endl;
    cout << "\t 3) Remove (invalid index)" << endl;

    
    cout << "(1/2/3): ";
    cin >> t_choice;
   
    switch(t_choice) {
        case 0:
            cout << "Quiting..." << endl;
            break;
        case 1:
            cout << "> w.insert(\"weqw\", -10)" << endl;
            w.insert("weqw", -10);
        case 2: 
            cout << "> w.read(300)" << endl;
            w.read(300);
        case 3:
            cout << "> w.remove(300)" << endl;
            w.remove(300);  
        default:
            cout << "Input takes only intigers. 0-3" << endl;
    }

    return 0;

}
