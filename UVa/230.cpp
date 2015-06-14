#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;

struct Book
{
	string title, author;
	Book(){};
	Book(string a, string b){
		title = a;
		author = b;
	}
};

bool operator < (Book a, Book b){
	if (a.author == b.author)
		return a.title < b.title;
	return a.author < b.author;
}

string sub(string &cad, int i, int f){
	string res = "";

	while (i < f){
		res = res + cad[i];
		i++;
	}

	return res;
}

int find(string &cad, string pat){
	int i = 0;

	for (i = 0; i < cad.length()-pat.size() && sub(cad, i, i + pat.length()) != pat; i++);

	return i;
}

string read(){
	string res;
	getline(cin, res);
	return res;
}

int main(){

	string cad;
	set <Book> books, borrowed, returned;
	map <string, string> authorOf;
	while ((cad = read()) != "END"){
		string author, title;
		char t[85], a[85];
		int index;

		sscanf(cad.c_str(), "\"%[^\"]\" by %[^\n\r]", t, a);
		
		title = string(t);
		author = string(a);

		books.insert(Book(title, author));
		authorOf[title] = author;
	}		


	while ((cad = read()) != "END"){
		if (cad == "SHELVE"){
			set<Book> :: iterator it, that;
			for (it = returned.begin(); it != returned.end(); it++){
				books.insert(*it);
				that = books.find(*it);
				if (that != books.begin()){
					that--;
					Book aBook = *that;
					Book oBook = *it;
					cout<<"Put \""<<oBook.title<<"\" after \""<<aBook.title<<"\""<<endl;
				}
				else
					cout<<"Put \""<<(*it).title<<"\" first"<<endl;				
			}	
			cout<<"END"<<endl;
			returned.clear();
		}
		else{
			int index = find(cad, " ");
			string com = sub(cad, 0, index);
			string title = sub(cad, index+1, cad.length());
			char t[85];
			if (com == "BORROW"){

				sscanf(cad.c_str(), "BORROW \"%[^\"]\"", t);
				title = string(t);
				Book aBook = Book(title, authorOf[title]);
				books.erase(aBook);
			}
			if (com == "RETURN"){
				sscanf(cad.c_str(), "RETURN \"%[^\"]\"", t);
				title = string(t);
				Book aBook = Book(title, authorOf[title]);
				returned.insert(aBook);
			}
		}
	}
	return 0;
}