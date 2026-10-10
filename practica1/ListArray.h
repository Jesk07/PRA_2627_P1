#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include "List.h"
#include <stdexcept>

using namespace std;

template <typename T>

class ListArray : public List<T> {

private:
//atributos	
T* arr;
int max;
int n;
static const int MINSIZE = 2;

//método privado

void resize(int new_size){

T* arr2 = new T[new_size];

for(int i = 0; i < n; i++){

arr2[i] = arr[i];
}

delete[] arr;

arr = arr2;
max = new_size;


}

public:
//métodos públicos
	
 void insert(int pos, T e) override{

if ( pos < 0 || pos > n){
	throw out_of_range("Posición inválida!");


 }
if ( n == max ) resize(max * 2);

for ( int i = n; i >pos; i--){

arr[i] = arr[i-1];

}
arr[pos] = e;
n++;
}


 void append(T e) override{
insert(n,e);
 }


 void prepend(T e) override{
insert(0,e);	
 }


 T remove(int pos) override{

if(pos < 0 || pos >= n) {

throw out_of_range("Posición inválida!");

}

T aux = arr[pos];



for(int i = pos; i < n - 1; i++){

arr[i] = arr[i+1];


 }

n--;

if ( n > MINSIZE && n <= max / 4) resize(max / 2);

return aux;
}


 T get(int pos) override{

if ( pos < 0 || pos >= n ) {

	throw out_of_range("Posicion invalida");
}
T aux = arr[pos];

return aux;



 }	 

 int search(T e) override{

for( int i = 0; i < n;i++){

	if( arr[i] == e){
		
		return i;	

	}
}

return -1;

 }	 

 bool empty() override{

return (n == 0) ? true : false;
 }

 int size() override{

return n;	 
 }




 ListArray() {
 
arr = new T[MINSIZE];
max = MINSIZE;
n = 0;
 
 }

~ListArray() override{

	delete[] arr;

}


T operator[](int pos){

if( pos < 0 || pos >= n) {

throw out_of_range("Posición inválida!");

}	
T aux = arr[pos];

return aux;
}	


friend ostream& operator<<(ostream &out, ListArray<T> &list){

out << "Lista -> [";

if(list.n > 0){

out << endl;	

for( int i = 0; i<list.n ; i++){

out << "  " <<  list.arr[i] << endl;

}	


  }
out << "]";
return out;
 } 	


};

#endif
