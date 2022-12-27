#include <iostream>
#include "struct.h"
#include "func.h"

using namespace std;

void Print(Matrix matrix){
    Line* line, *head;
    Item* item;
    int i,j,maxi,maxj, found;
    maxi = matrix.line;
    maxj = matrix.column;
    for(i=0;i<maxi;i++){
        found = 0;
        head = matrix.head;
        while(head != nullptr){
            if(head->i==i){
                line = head;
                found = 1;
            }
            head = head->next;
        }
        if (found==0){
            for(j=0;j<maxj;j++){
                cout << "0 ";
            }
            cout << endl;
        }else{
            for(j=0;j<maxj;j++){
                item = line->head;
                found = 0;
                while(item!=nullptr){
                    if (item->j == j){
                        found = 2;
                        cout << item->value << " ";
                    }
                    item = item->next;
                }
                if(found!=2){
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
}

Item* NewItem(int val, int i, int j){
    Item* newitem = new Item;
    newitem->value = val;
    newitem->i = i;
    newitem->j = j;
    newitem->next = nullptr;
    return newitem;
}

Line* NewLine(int i){
    Line* newline = new Line;
    newline->head = nullptr;
    newline->next = nullptr;
    newline->i = i;
    newline->maxj = -1;
    return newline;
}

Line* InputItem(Line* line, Item* item){
    int j;
    j = item->j;
    Item* head = line->head;
    if(head == nullptr){
        line->head = item;
        line->maxj = j;
    }else if(line->maxj<j){
        while(head->next!=nullptr){
            head = head->next;
        }
        head->next = item;
        line->maxj = j;
    }else if(head->next == nullptr || (item->j<head->j)){
        item->next = line->head;
        line->head = item;
    }else{
        while(head->next->j < j){
            head = head->next;
        }
        item->next = head->next;
        head->next = item;
    }
    return line;
}


int vozr(int x){//1 если возрастает 0 если нет
    int f, max, y;
    f = 1;
    max = 10;
    while(x>0){
        y = x%10;
        x = x/10;
        if(y<max){
            max = y;
        }else if (y>=max){
            f = 0;
        }
    }
    return f;
}

int ubiv (int x){//1 если убывает 0 если нет
    int f, max, y;
    f = 1;
    max = -1;
    while(x>0){
        y = x%10;
        x = x/10;
        if(y>max){
            max = y;
        }else if (y<=max){
            f = 0;
        }
    }
    return f;
}



Matrix Init(Matrix matrix){
    matrix.head = nullptr;
    return matrix;
}

/*Line* pushline(Line* head, int i){
    Line* ptr = head;
    if(head == nullptr){
        head = NewLine(i);
    }else{
        while(ptr->next!=nullptr || ptr->next->i < i){
            ptr = ptr->next;
        }
        Line* cmd;
        cmd = ptr->next;
        ptr->next = NewLine(i);
        ptr->next->next = cmd;
    }
    return head;
}*/

Matrix Input(Matrix matrix){
    int f,i,j, val, maxi, find;
    Item* item;
    Line* line, *head;
    val = 1;
    while(val!=0){
        cout << "enter a value or 0 if there are no more items" << endl;
        cin >> val;
        if(val!=0){
            cout << "enter line number" << endl;
            cin >> i;
            if(i>(matrix.line)-1){
                do{
                    cout << "try again" << endl;
                    cin >> i;
                }while(i>(matrix.line)-1);
            }
            cout << "enter column number" << endl;
            cin >> j;
            if(j>(matrix.column)-1){
                do{
                    cout << "try again" << endl;
                    cin >> j;
                }while(j>(matrix.column)-1);
            }
            item = NewItem(val, i, j);
            head = matrix.head;
            maxi = matrix.maxi;
            if(head == nullptr){
                line = NewLine(i);
                matrix.head = line;
                matrix.maxi = i;
            }else if(head->i == i){
                line = head;
            }else if(head->next==nullptr || i<maxi){
                line = NewLine(i);
                line->next = matrix.head;
                matrix.head = line;
            }else if(maxi<i){
                while(head->next!=nullptr){
                    head = head->next;
                }
                line = NewLine(i);
                head->next = line;
                matrix.maxi = i;
            }else{
                while(head->next->i < i){
                    head = head->next;
                }
                if(head->next->i == i){
                    line = head->next;
                }else{
                    line = NewLine(i);
                    line->next = head->next;
                    head->next = line;
                }
            }
            line = InputItem(line, item);
        }
    }
    return matrix;
}

Line* InputLine2(Line* line, Item* item){
    Item* head = line->head;
    if(head == nullptr){
        line->head = item;
    }else{
        while(head->next!=nullptr){
            head = head->next;
        }
        head->next = item;
    }
    return line;
}

Matrix Copymatrix(Matrix matrix, Matrix newmatrix){
    Item* item, *headitem, *newitem;
    Line* line, *head, *newhead;
    int val, flag,i,j,found;
    newmatrix = Init(matrix);
    head = matrix.head;
    while(head!=nullptr){
        headitem = head->head;
        i = head->i;
        while(headitem!=nullptr){
            j = headitem->j;
            val = headitem->value;
            flag = 0;
            found = 0;
            found = vozr(val);
            if(found == 1){
                newhead = newmatrix.head;
                item = NewItem(val, i, j);
                if(newhead == nullptr){
                    line = NewLine(i);
                    newmatrix.head = line;
                    flag = 1;
                }/*else if(newhead->i == i){
                    line = newhead;
                    flag = 1;
                }*/else{
                    while(newhead!=nullptr){
                        if(newhead->i == i){
                            flag = 1;
                            line = newhead;
                        }
                        newhead = newhead->next;
                    }
                }
                if(flag==0){
                    line = NewLine(i);
                    line->next = newmatrix.head;
                    newmatrix.head = line;
                }
                line = InputLine2(line,item);
            }
            headitem = headitem->next;
        }
        head = head->next;
    }

    head = matrix.head;
    while(head!=nullptr){
        headitem = head->head;
        i = head->i;
        while(headitem!=nullptr){
            j = headitem->j;
            val = headitem->value;
            flag = 0;
            found = 0;
            found = ubiv(val);
            if((val/10)==0){
                found = 0;
            }
            if(found == 1){
                newhead = newmatrix.head;
                item = NewItem(val, i, j);
                if(newhead == nullptr){
                    line = NewLine(i);
                    newmatrix.head = line;
                    flag = 1;
                }/*else if(newhead->i == i){
                    line = newhead;
                    flag = 1;
                }*/else{
                    while(newhead!=nullptr){
                        if(newhead->i == i){
                            flag = 1;
                            line = newhead;
                        }
                        newhead = newhead->next;
                    }
                }
                if(flag==0){
                    line = NewLine(i);
                    line->next = newmatrix.head;
                    newmatrix.head = line;
                }
                line = InputLine2(line,item);
            }
            headitem = headitem->next;
        }
        head = head->next;
    }

    return newmatrix;
}

void Print2(Matrix matrix){
    int i,j,k,maxi,maxj,f,s;
    Line* line;
    Item* node;
    maxi = matrix.line;
    for(i=0;i<maxi;i++){
        line = matrix.head;
        f = 0;
        j = matrix.column;
        while(line!=nullptr){
        if(line->i == i){
                f = 1;
                s = 0;
                node = line->head;
                while(node!=nullptr){
                    cout << node->value << " ";
                    s = s+1;
                    node = node->next;
                }
                for(k=0;k<(j-s);k++){
                    cout << "0 ";
                }
                cout << endl;
            }
            line = line->next;
        }
        if(f==0){
            for(k=0;k<j;k++){
                cout << "0 ";
            }
            cout << endl;
        }
    }
}

void Delite(Matrix matrix){
    Line* line, *ptr;
    Item* item, *cmd;
    line = matrix.head;
    while(line!= nullptr){
        item = line->head;
        while(item!=nullptr){
            cmd = item->next;
            delete item;
            item = cmd;
        }
        line->head = nullptr;
        ptr = line->next;
        delete line;
        line = ptr;
    };
}