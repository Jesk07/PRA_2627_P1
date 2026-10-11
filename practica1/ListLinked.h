#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
Node<T>* first;

int n;
        

    public:

// heredadod de List.h

void insert(int pos, T e){

if ( pos < 0 || pos > n ) {

throw out_of_range("Posición no válida");
}
Node<T>* nuevo = new Node<T>(e);
Node<T>* prev = nullptr;
Node<T>* aux = first;
int i = 0;

while(aux != nullptr && i < pos ){

	prev = aux;
	aux = aux->next;
	i++;


}
if ( prev == nullptr) {
nuevo->next = first;
first = nuevo;	
}
else{
prev->next = nuevo;
nuevo -> next = aux;
}
n++;
}


void append(T e){
Node<T>* nuevo = new Node<T>(e);
Node<T>* prev = nullptr;
Node<T>* aux = first;

if(first == nullptr){

first = nuevo;
}else{

while(aux != nullptr){
	prev = aux;
	aux = aux->next;
}
prev->next = nuevo;
nuevo->next = nullptr;
}
n++;

}


void prepend(T e){

Node<T>* nuevo = new Node<T>(e);
Node<T>* aux = first;


nuevo->next = aux;
first = nuevo;
n++;







}

T remove(int pos){

if(pos < 0 || pos >= n){
	throw out_of_range("Posición no válida");
}

Node<T>* prev = nullptr;
Node<T>* aux = first;
int i = 0;

while(aux != nullptr && i<pos){
	prev = aux;
	aux = aux->next;
	i++;
}
if(prev == nullptr){
	first = aux -> next;
}else{
	prev->next = aux->next;	

}
T dato = aux->data;
delete aux;
n--;
return dato;
}

T get(int pos){

if(pos < 0 || pos >=n ){
	throw out_of_range("Posición inválida");
}

Node<T>* prev = nullptr;
Node<T>* aux = first;
int i = 0;

while( aux != nullptr && i < pos){
	prev = aux;
	aux = aux->next;
	i++;
}
T dato = aux->data;
return dato;

}


int search(T e){

Node<T>* aux = first;
int i =0;

while(aux!= nullptr && aux->data != e){
	aux = aux->next;
	i++;
}
if(aux == nullptr) {
	return -1;
}else{
	return i;
}
}

bool empty(){
	return (n==0) ? true : false;
}

int size(){
	return n;
}

// propios de ListLInked.h

// constructor y destructor

ListLinked(){

first = nullptr;

n = 0;


}

~ListLinked(){
	while(first!=nullptr){
	Node<T>* aux = first->next;
	delete first;
	first = aux;


}
}

// métodos públicos

T operator[](int pos){
	return get(pos);
}

friend ostream& operator<<(ostream &out, ListLinked &list){

out << "Lista -> [";
if(list.n>0){
out << endl;
Node<T>* aux = list.first;

while(aux != nullptr){
	out <<"  "<<  aux->data << endl;
	aux = aux->next;
}
}
out << "]";

return out;
}





        
};

#endif 
