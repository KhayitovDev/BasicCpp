Exercise Working with files


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

struct MyStruct
{
	char fname[20];
	int id;
	char name[20];
	int quantity;
	double w_cost;
	double r_cost;
	char date[10];
	
};
void add(vector<MyStruct*>& store) {

	bool flag = false;
	MyStruct* s = new MyStruct();

	do {

		cout << "Enter file name \t" << endl;
		cin >> s->fname;
		cout << "Enter product ID: ";
		cin >> s->id;
		cout << "Enter product name: ";
		cin >> s->name;
		cout << "Enter quantity: ";
		cin >> s->quantity;
		cout << "Enter wholsale cost: $";
		cin >> s->w_cost;
		cout << "Enter retail cost: $";
		cin >> s->r_cost;
		cout << "Enter date : ";
		cin >> s->date;

		
		ofstream ofile(s->fname);
		ofile << s->id << endl;
		ofile << s->name << endl;
		ofile << s->quantity << endl;
		ofile << s->w_cost << endl;
		ofile << s->r_cost << endl;
		ofile << s->date << endl;

		ifstream ifile(s->fname);
		ifile >> s->id;
		ifile >> s->name;
		ifile >> s->quantity;
		ifile >> s->w_cost;
		ifile >> s->r_cost;
		ifile >> s->date;
		ifile.close();


		if (s->w_cost < 0 || s->r_cost < 0)
			flag = false;
		else
		{
			flag = true;
		}

		

	}
	while (!flag);
	store.push_back(s);
}

void srd(vector<MyStruct*>& store) {
	string search;
	cout << "Enter item to search";
	cin >> search;
	for (int i = 0; i < store.size(); i++) {
		string iname = store[i]->name;
		if (iname.compare(0, search.size(), search) == 0) {
			cout << "ID of the item: \t" << store[i]->id << endl;
			cout << "Name of the item: \t" << store[i]->name << endl;
			cout << "Quantity of the item: \t" << store[i]->quantity << endl;
			cout << "Wholsale cost of the item: $\t" << store[i]->w_cost << endl;
			cout << "Retail cost of the item: $\t" << store[i]->r_cost << endl;
			cout << "Date of the item: \t" << store[i]->date << endl;

				
		}
	}

}

void wcosts(vector<MyStruct*>& store) {

	
	int total_q = 0;
	double total_wcost = 0;
	

	for (int i = 0; i < store.size(); i++) {
		total_q += store[i]->quantity;
		total_wcost += store[i]->w_cost;
	
	}

	cout << "Overall  costs: " << endl;
	cout << "Total quantity:" << total_q << endl;
	cout << "Wholesale cost: $" << total_wcost*total_q << endl;



}
void rcosts(vector<MyStruct*>& store) {

	
	int total_q = 0;
	double total_rcost = 0;

	for (int i = 0; i < store.size(); i++) {
		total_q += store[i]->quantity;
		total_rcost += store[i]->r_cost;
	}

	cout << "Overall costs: " << endl;
	cout << "Total quantity:" << total_q << endl;
	cout << "Retail cost: $" << total_rcost*total_q << endl;


}
void menu() {
	cout << "Menu" << endl;
	cout << "1.Add new records: "<< endl;
	cout << "2.Display records: "<< endl;
	cout << "3.Calculate wholsale records :" << endl;
	cout << "4.Calculate retail records :" << endl;
}

int main() {



	vector<MyStruct*>store;
	int choice = 1;

	do {
		menu();
		cin >> choice;

		switch (choice) {

		case 1:
			add(store);
			break;
		case 2:
			srd(store);
			break;
		case 3:
			wcosts(store);
			break;
		case 4:
			rcosts(store);
			break;


		}
	} while (choice != 0);
	
	return 0;
}