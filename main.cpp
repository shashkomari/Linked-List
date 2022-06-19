#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

class Data {
public:
	string name;
	string phone;
	uint8_t age;

	operator string() {
		return name + string("\t | \t") + phone + string("\t | \t") + to_string(age);
	}
};

int main() {
	LinkedList<string> friendsNames;

	friendsNames.add("Nikitka");
	friendsNames.add("Andrei");
	friendsNames.add("Vasya");
	friendsNames.add("Anna");
	friendsNames.add("Mara");
	friendsNames.add("Vichka");
	friendsNames.add("Vasya");

	friendsNames.show();

	std::string nameToDelete = "Vasya";
	bool removed = friendsNames.removeAll(nameToDelete);
	if (removed) {
		cout << "My udalili vseh druzei s imenem " << nameToDelete << " iz druzei" << endl;
	}
	else {
		cout << "Chtoby udalit vseh druzei s imenem " << nameToDelete << " nado snachala podruzhitca s nimi" << endl;
	}

	removed = friendsNames.removeAll(nameToDelete);
	if (removed) {
		cout << "My udalili vseh druzei s imenem " << nameToDelete << " iz druzei" << endl;
	}
	else {
		cout << "Chtoby udalit vseh druzei s imenem " << nameToDelete << " nado snachala podruzhitca s nimi" << endl;
	}

	friendsNames.show();

	// --------------------------------------------------------

	LinkedList<Data> notes;
	notes.add(Data{ "Oleg",   "+380(77)666-55-44",  7 });
	notes.add(Data{ "Dasha",  "+380(77)666-99-00",  13 });
	notes.add(Data{ "Dima",   "+380(77)666-00-11",  7 });
	notes.add(Data{ "Larisa", "+380(77)666-11-22",  7 });

	for (LinkedList<Data>::Iterator it = notes.getIterator(); it; ++it)
	{
		cout << (string)*it << endl;
	}

	return 0;
}